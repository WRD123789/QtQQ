#ifndef QTQQSERVER_H
#define QTQQSERVER_H

#include "tcpserver.h"

#include <QDialog>
#include <QSqlQueryModel>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class QtQQServer;
}
QT_END_NAMESPACE

const int tcpPort = 8888;
const int udpPort = 6666;

class QtQQServer : public QDialog
{
    Q_OBJECT

public:
    QtQQServer(QWidget *parent = nullptr);
    ~QtQQServer();

public:
    bool connectDatabase();

private:
    void initTcpSocket();
    void initUdpSocket();
    void updateTableData(int depID = 0, int employeeID = 0);
    int getCompanyDepID();
    void initDepMap();
    void logoutEmp(int empID);
    bool isEmployeeFound(int empID);

private slots:
    void onBroadMsg(QByteArray &data);
    void onRefresh();

    void onQueryDepartmentBtnClicked();
    void onQueryIDBtnClicked();
    void onLogoutBtnClicked();
    void onSelectPictureBtnClicked();
    void onAddBtnClicked();

private:
    Ui::QtQQServer *ui;
    int m_depID;
    int m_empID;
    int m_companyDepID;
    TcpServer *m_tcpServer;
    QUdpSocket *m_udpSender; // 用于广播
    QSqlQueryModel *m_queryInfoModel; // 查询所有员工的信息
    QMap<QString, QString> m_depID2DepName;
    QMap<QString, QString> m_depName2DepID;
    QTimer *m_timer; // 定时刷新数据
    QString m_pixPath; // 在添加新的员工时保存选择的头像路径
};
#endif // QTQQSERVER_H
