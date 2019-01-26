#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickStyle>
#include "api_missionhandler.h"
#include "api_terminal.h"
#include "api_serialhandler.h"
#include "api_protocolhandler.h"
#include "api_dataloghandler.h"
#include "api_guimanager.h"

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QQuickStyle::setStyle("Fusion");
    QQuickView viewer;

// object declaration
    API_MissionHandler obj_MissionHandler;
    API_Terminal obj_LogMission;
    API_Terminal obj_LogData;
    API_SerialHandler obj_SerialHandler;
    API_ProtocolHandler obj_ProtocolHandler;
    API_DataLogHandler obj_DataLogHandler;
    API_GUIManager obj_GUIManager;

// connection between objects
    // koneksi ui ke Qt untuk fungsi quit
    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);
    // koneksi MissionHandler ke LogMission untuk notif
    QObject::connect(&obj_MissionHandler,&API_MissionHandler::notif_Log,&obj_LogMission,&API_Terminal::receive_Message);
    // koneksi SerialHandler ke LogMission untuk notif
    QObject::connect(&obj_SerialHandler,&API_SerialHandler::message_SerialHandler,&obj_LogMission,&API_Terminal::receive_Message);
    // koneksi SerialHandler ke ProtocolHandler untuk kirim byte
    QObject::connect(&obj_SerialHandler,&API_SerialHandler::send_DataByte,&obj_ProtocolHandler,&API_ProtocolHandler::receive_DataByte);
    // koneksi ProtocolHandler ke GUIManager untuk data accel dan gyro
    QObject::connect(&obj_ProtocolHandler, &API_ProtocolHandler::send_DataAccel,&obj_GUIManager,&API_GUIManager::receive_DataAccel);
    QObject::connect(&obj_ProtocolHandler, &API_ProtocolHandler::send_DataGyro,&obj_GUIManager,&API_GUIManager::receive_DataGyro);
    // koneksi GUIManager ke datalog handler

// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_MissionHandler",&obj_MissionHandler);
    viewer.rootContext()->setContextProperty("obj_LogMission",&obj_LogMission);
    viewer.rootContext()->setContextProperty("obj_LogData",&obj_LogData);
    viewer.rootContext()->setContextProperty("obj_SerialHandler",&obj_SerialHandler);
    viewer.rootContext()->setContextProperty("obj_DataLogHandler",&obj_DataLogHandler);

// final set up
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setSource(QUrl("qrc:/main.qml"));
    //viewer.showFullScreen();
    viewer.showMaximized();

    return app.exec();
}
