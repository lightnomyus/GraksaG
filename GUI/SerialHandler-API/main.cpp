#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "api_serialhandler.h"
#include "api_terminal.h"

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickView viewer;

// object declaration
    API_SerialHandler obj_SerialHandler;
    API_Terminal obj_Terminal;

// connection between objects
    QObject::connect(&obj_SerialHandler,&API_SerialHandler::message_SerialHandler,&obj_Terminal,&API_Terminal::receive_Message);

// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_SerialHandler",&obj_SerialHandler);
    viewer.rootContext()->setContextProperty("obj_Terminal",&obj_Terminal);

// final set up
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();
    return app.exec();
}
