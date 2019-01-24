#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickStyle>
#include "api_missionhandler.h"
#include "api_terminal.h"
#include "api_serialhandler.h"
#include "api_protocolhandler.h"

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

// connection between objects
    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);
    QObject::connect(&obj_MissionHandler,&API_MissionHandler::notif_Log,&obj_LogMission,&API_Terminal::receive_Message);
    QObject::connect(&obj_SerialHandler,&API_SerialHandler::message_SerialHandler,&obj_LogMission,&API_Terminal::receive_Message);
    QObject::connect(&obj_SerialHandler,&API_SerialHandler::send_DataByte,&obj_ProtocolHandler,&API_ProtocolHandler::receive_DataByte);

// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_MissionHandler",&obj_MissionHandler);
    viewer.rootContext()->setContextProperty("obj_LogMission",&obj_LogMission);
    viewer.rootContext()->setContextProperty("obj_LogData",&obj_LogData);
    viewer.rootContext()->setContextProperty("obj_SerialHandler",&obj_SerialHandler);

// final set up
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setSource(QUrl("qrc:/main.qml"));
    //viewer.showFullScreen();
    viewer.showMaximized();

    return app.exec();
}
