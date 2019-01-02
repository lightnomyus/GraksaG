#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "api_chartviewer.h"
#include "tester_chartviewer.h"

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QQuickView viewer;

// object declaration
    API_ChartViewer obj_ChartViewer;
    Tester_ChartViewer obj_TesterChartViewer;

// connection between objects
    QObject::connect(&obj_TesterChartViewer,&Tester_ChartViewer::incoming_Data,&obj_ChartViewer,&API_ChartViewer::receive_DataSpline);

// binding c++ with qml
    viewer.rootContext()->setContextProperty("obj_ChartViewer",&obj_ChartViewer);
    viewer.rootContext()->setContextProperty("obj_TesterChartViewer",&obj_TesterChartViewer);

// final set up
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();
    return app.exec();
}
