#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "api_scatter3d.h"
#include "tester_scatter3d.h"

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickView viewer;

// object declaration
    API_Scatter3D obj_Scatter3D;
    Tester_Scatter3D obj_testerScatter3D;

// connection between objects
    QObject::connect(&obj_testerScatter3D,&Tester_Scatter3D::incoming_Data,&obj_Scatter3D,&API_Scatter3D::receive_Data3DPosition);

// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_testerScatter3D",&obj_testerScatter3D);
    viewer.rootContext()->setContextProperty("obj_Scatter3D",&obj_Scatter3D);

// final set up
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

    return app.exec();
}
