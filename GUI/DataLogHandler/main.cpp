#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "api_dataloghandler.h"

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickView viewer;

// object declaration
    API_DataLogHandler obj_DataLogHandler;

// connection between objects

// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_DataLogHandler",&obj_DataLogHandler);

// final set up
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();
    return app.exec();
}
