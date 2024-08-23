cmake_minimum_required(VERSION 3.5)

project(QtQQ VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets WebEngine Xml Sql Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets WebEngineWidgets Xml Sql Network)

include_directories(/Users/wangrundong/Documents/Projects/QtQQ /opt/homebrew/opt/mysql/include/mysql)

set(PROJECT_SOURCES
        main.cpp
        ccmainwindow.cpp
        ccmainwindow.h
        ccmainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtQQ
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        titlebar.h titlebar.cpp
        basicwindow.h basicwindow.cpp
        notifymanager.h notifymanager.cpp
        commonutils.h commonutils.cpp
        userlogin.h userlogin.cpp
        userlogin.ui
        ccmainwindow.qrc
        skinwindow.h skinwindow.cpp
        skinwindow.ui
        qclicklabel.h qclicklabel.cpp
        systray.h systray.cpp
        custommenu.h custommenu.cpp
        rootcontactitem.h rootcontactitem.cpp
        contactitem.h contactitem.cpp
        contactitem.ui
        talkwindowshell.h talkwindowshell.cpp
        talkwindowshell.ui
        emotionwindow.h emotionwindow.cpp
        emotionwindow.ui
        emotionlabelitem.h emotionlabelitem.cpp
        talkwindowitem.h talkwindowitem.cpp
        talkwindowitem.ui
        talkwindow.h talkwindow.cpp
        talkwindow.ui
        windowmanager.h windowmanager.cpp
        qmsgtextedit.h qmsgtextedit.cpp
        msgwebview.h msgwebview.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QtQQ APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QtQQ SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QtQQ
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QtQQ PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::WebEngineWidgets
    Qt${QT_VERSION_MAJOR}::Xml
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Network)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QtQQ)
endif()
set_target_properties(QtQQ PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QtQQ
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtQQ)
endif()
