#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "api_mapviewer.h"
#include "tester_mapviewer.h"

int main(int argc, char *argv[])
{
    // basic set up
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QGuiApplication app(argc, argv);
        QQuickView viewer;

    // object declaration
        API_MapViewer obj_MapViewer;
        Tester_MapViewer obj_testerMapViewer;

    // connection between objects
        QObject::connect(&obj_testerMapViewer,&Tester_MapViewer::incoming_Data,&obj_MapViewer,&API_MapViewer::receive_Data3DPosition);

    // binding c++ with qml
        viewer.rootContext()->setContextProperty("obj_testerMapViewer",&obj_testerMapViewer);
        viewer.rootContext()->setContextProperty("obj_MapViewer",&obj_MapViewer);

    // final set up
        viewer.setSource(QUrl("qrc:/main.qml"));
        viewer.show();
    return app.exec();
}
