#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "api_missionhandler.h"

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QQuickView viewer;

// object declaration
    API_MissionHandler obj_MissionHandler;

// connection between objects


// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_MissionHandler",&obj_MissionHandler);

// final set up
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

    return app.exec();
}
