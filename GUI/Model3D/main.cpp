#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "api_modelattitude.h"
#include "tester_modelattitude.h"

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickView viewer;

// object declaration
    API_ModelAttitude obj_Model3D;
    Tester_ModelAttitude obj_tester;

// connection between objects
    QObject::connect(&obj_tester,&Tester_ModelAttitude::incoming_Data,&obj_Model3D,&API_ModelAttitude::receive_Attitude);

// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_Model3D",&obj_Model3D);
    viewer.rootContext()->setContextProperty("obj_tester",&obj_tester);

// final set up
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();
    return app.exec();
}
