#include "qtqqserver.h"
#include "./ui_qtqqserver.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTimer>
#include <QFileDialog>
#include <QInputDialog>

QtQQServer::QtQQServer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QtQQServer)
{
    ui->setupUi(this);

    QPixmap pix(":/Resources/img/fly1.png");
    ui->imgLabel->setPixmap(pix);

    if (!connectDatabase()) {
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("连接数据库失败!"));
        close();
        return;
    }

    initDepMap();

    m_companyDepID = getCompanyDepID();
    m_depID = m_companyDepID;
    m_empID = 0;

    m_queryInfoModel = new QSqlQueryModel(this);
    updateTableData();

    m_timer = new QTimer(this);
    m_timer->setInterval(200);
    m_timer->start();

    connect(m_timer, &QTimer::timeout, this, &QtQQServer::onRefresh);
    connect(ui->queryDepartmentBtn, &QPushButton::clicked,
            this, &QtQQServer::onQueryDepartmentBtnClicked);
    connect(ui->queryIDBtn, &QPushButton::clicked,
            this, &QtQQServer::onQueryIDBtnClicked);
    connect(ui->logoutBtn, &QPushButton::clicked,
            this, &QtQQServer::onLogoutBtnClicked);
    connect(ui->selectPictureBtn, &QPushButton::clicked,
            this, &QtQQServer::onSelectPictureBtnClicked);
    connect(ui->addBtn, &QPushButton::clicked,
            this, &QtQQServer::onAddBtnClicked);

    initTcpSocket();
    initUdpSocket();
}

QtQQServer::~QtQQServer()
{
    delete ui;
    delete m_tcpServer;
}

void QtQQServer::initTcpSocket()
{
    m_tcpServer = new TcpServer(tcpPort);
    m_tcpServer->run();

    // 收到信息后进行广播
    connect(m_tcpServer, &TcpServer::signalTcpMsgComes,
            this, &QtQQServer::onBroadMsg);
}

void QtQQServer::initUdpSocket()
{
    m_udpSender = new QUdpSocket(this);
}

void QtQQServer::updateTableData(int depID, int employeeID)
{
    ui->tableWidget->clear();

    if (depID && m_companyDepID != depID)
        m_queryInfoModel->setQuery(QString("SELECT * "
                                           "FROM tab_employees "
                                           "WHERE departmentID = %1").arg(depID));
    else if (employeeID)
        m_queryInfoModel->setQuery(QString("SELECT * "
                                           "FROM tab_employees "
                                           "WHERE employeeID = %1").arg(employeeID));
    else
        m_queryInfoModel->setQuery("SELECT * FROM tab_employees");

    int rows = m_queryInfoModel->rowCount();
    int columns = m_queryInfoModel->columnCount();
    QModelIndex index;

    // 设置表格的行数和列数
    ui->tableWidget->setRowCount(rows);
    ui->tableWidget->setColumnCount(columns);

    // 设置表头
    QStringList headers;
    headers << "部门" << "工号" << "员工姓名" << "员工签名" << "员工状态" << "员工头像" << "在线状态";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // 设置列等宽
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < columns; j += 1) {
            index = m_queryInfoModel->index(i, j);
            QString data = m_queryInfoModel->data(index).toString();

            if (j == 0) {
                data = m_depID2DepName.value(data);
            } else if (j == 4) {
                if (data == "1")
                    data = "有效";
                else
                    data = "注销";
            } else if (j == 6) {
                if (data == "1")
                    data = "离线";
                else
                    data = "在线";
            }

            ui->tableWidget->setItem(i, j, new QTableWidgetItem(data));
        }
    }
}

int QtQQServer::getCompanyDepID()
{
    QSqlQuery query;
    QString sqlStr = QString("SELECT departmentID "
                             "FROM tab_department "
                             "WHERE department_name = '公司群'");
    query.exec(sqlStr);
    query.next();

    return query.value(0).toInt();
}

void QtQQServer::initDepMap()
{
    m_depID2DepName.clear();

    QSqlQuery query;
    QString sqlStr = QString("SELECT departmentID, department_name "
                             "FROM tab_department");
    query.exec(sqlStr);
    while(query.next()) {
        QString depID = query.value(0).toString(), depName = query.value(1).toString();
        m_depID2DepName.insert(depID, depName);
        m_depName2DepID.insert(depName, depID);
    }
}

void QtQQServer::logoutEmp(int empID)
{
    QSqlQuery query;
    QString sqlStr = QString("UPDATE tab_employees "
                             "SET status = 0 "
                             "WHERE employeeID = %1").arg(empID);
    if (query.exec(sqlStr))
        QMessageBox::information(NULL, QString("提示"),
                                 QString::fromLocal8Bit("注销 %1 员工成功!").arg(empID));
    else
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("注销 %1 员工失败!").arg(empID));
}

bool QtQQServer::isEmployeeFound(int empID)
{
    QSqlQuery query;
    QString sqlStr = QString("SELECT * "
                             "FROM tab_employees "
                             "WHERE employeeID = %1").arg(empID);
    query.exec(sqlStr);

    return query.next();
}

// 通过 UDP 广播消息
void QtQQServer::onBroadMsg(QByteArray &data)
{
    for (quint16 port = udpPort; port < udpPort + 200; port += 1) {
        m_udpSender->writeDatagram(data, data.size(), QHostAddress("127.0.0.1"), port);
    }
}

void QtQQServer::onRefresh()
{
    updateTableData(m_depID, m_empID);
}

bool QtQQServer::connectDatabase()
{
    // 数据库连接设置
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("qtqq");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("162738609");
    db.setPort(3306);

    if (!db.open())
        return false;

    return true;
}

void QtQQServer::onQueryDepartmentBtnClicked()
{
    m_empID = 0;
    QString depName = ui->departmentBox->currentText();
    m_depID = m_depName2DepID.value(depName).toInt();
    updateTableData(m_depID);
}


void QtQQServer::onQueryIDBtnClicked()
{
    ui->departmentBox->setCurrentIndex(0);

    m_depID = m_companyDepID;
    int empID = ui->queryIDLineEdit->text().toInt();

    if (empID == 0) {
        m_empID = empID;
        updateTableData(m_depID, m_empID);

        return;
    }

    if (isEmployeeFound(empID))
        m_empID = empID;
    else
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("未查询到 %1 员工!").arg(empID));

    updateTableData(m_depID, m_empID);
}


void QtQQServer::onLogoutBtnClicked()
{
    int empID = ui->logoutIDLineEdit->text().toInt();

    if (isEmployeeFound(empID)) {
        m_empID = empID;
    } else {
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("未查询到 %1 员工!").arg(empID));
        return;
    }

    logoutEmp(empID);
    updateTableData();
}


void QtQQServer::onSelectPictureBtnClicked()
{
    QString pixPath = QFileDialog::getOpenFileName(this,
                                                tr("选择图片"),
                                                ".",
                                                tr("Images(*.png *.jpg)"));
    if (pixPath.isEmpty()) {
        QMessageBox::warning(NULL, QString("提示"), QString::fromLocal8Bit("需要选择一张图片!"));
        return;
    } else {
        m_pixPath = pixPath;

        QPixmap pix(pixPath);
        ui->headLabel->setPixmap(pix);
        ui->headLabel->setScaledContents(true);
        ui->headLabel->setAlignment(Qt::AlignCenter);
        ui->headLabel->setText("");
    }
}


void QtQQServer::onAddBtnClicked()
{
    QString depName = ui->employeeDepBox->currentText();
    int depID = m_depName2DepID.value(depName).toInt();

    QString empName = ui->nameLineEdit->text();
    QString pixPath = m_pixPath;

    if (empName == "") {
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("请输入员工名!"));
        return;
    } else if (pixPath == "") {
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("请选择一张图片作为头像!"));
        return;
    }

    // 新的员工号 = 当前最大的员工号 + 1
    // 插入新的员工信息
    QSqlQuery query;
    QString sqlStr = QString("SELECT employeeID "
                             "FROM tab_employees");
    query.exec(sqlStr);
    int maxEmpID = -1;
    while (query.next()) {
        int curEmp = query.value(0).toInt();
        maxEmpID = std::max(curEmp, maxEmpID);
    }
    int newEmpID = maxEmpID + 1;

    sqlStr = QString("INSERT INTO tab_employees(departmentID, employeeID, employee_name, picture) "
                     "VALUES (%1, %2, '%3', '%4')").arg(depID).arg(newEmpID).arg(empName).arg(pixPath);

    ui->headLabel->clear();
    ui->headLabel->setText("头像");
    ui->nameLineEdit->clear();

    if (!query.exec(sqlStr)) {
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("新员工信息插入失败!"));
        return;
    }

    // 开始插入新员工的账号信息
    QString account = QInputDialog::getText(this, tr("账号输入"), tr("账号: "));

    if (account.isEmpty()) {
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("账号不能为空!"));

        // 撤回之前插入的记录
        sqlStr = QString("DELETE FROM tab_employees "
                         "WHERE employeeID = %1").arg(newEmpID);
        if (!query.exec(sqlStr))
            QMessageBox::warning(NULL, QString("提示"),
                                 QString::fromLocal8Bit("插入的新员工信息撤回失败!"));

        return;
    }

    // 判断账号是否重复
    sqlStr = QString("SELECT account "
                     "FROM tab_accounts "
                     "WHERE account = '%1'").arg(account);
    query.exec(sqlStr);
    if (query.next()) {
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("账号重复!"));

        // 撤回之前插入的记录
        sqlStr = QString("DELETE FROM tab_employees "
                         "WHERE employeeID = %1").arg(newEmpID);
        if (!query.exec(sqlStr))
            QMessageBox::warning(NULL, QString("提示"),
                                 QString::fromLocal8Bit("插入的新员工信息撤回失败!"));

        return;
    }

    QString password = QString("123456");
    sqlStr = QString("INSERT INTO tab_accounts(employeeID, account, password) "
                     "VALUES (%1, '%2', '%3')").arg(newEmpID).arg(account).arg(password);
    if (!query.exec(sqlStr)) {
        QMessageBox::warning(NULL, QString("提示"),
                             QString::fromLocal8Bit("账号信息插入失败!"));

        // 撤回之前插入的记录
        sqlStr = QString("DELETE FROM tab_employees "
                         "WHERE employeeID = %1").arg(newEmpID);
        if (!query.exec(sqlStr))
            QMessageBox::warning(NULL, QString("提示"),
                                 QString::fromLocal8Bit("插入的新员工信息撤回失败!"));

        return;
    }
}

