#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "api_storagehandler.h"
#include "tester_writing.h"

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickView viewer;

// object declaration
    API_StorageHandler obj_StorageHandler;
    Tester_Writing obj_Tester;

// connection between objects
    QObject::connect(&obj_Tester,&Tester_Writing::incoming_Data,&obj_StorageHandler,&API_StorageHandler::write_Data);
    QObject::connect(&obj_Tester,&Tester_Writing::new_Name,&obj_StorageHandler,&API_StorageHandler::update_MissionName);
    QObject::connect(&obj_Tester,&Tester_Writing::start_Writing,&obj_StorageHandler,&API_StorageHandler::start_Write);
    QObject::connect(&obj_Tester,&Tester_Writing::end_Writing,&obj_StorageHandler,&API_StorageHandler::end_Write);

// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_StorageHandler",&obj_StorageHandler);
    viewer.rootContext()->setContextProperty("obj_Tester",&obj_Tester);

// final set up
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

    return app.exec();
}
