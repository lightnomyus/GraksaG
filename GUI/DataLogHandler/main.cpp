#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickView viewer;

// object declaration

// connection between objects

// binding c++ with qml

// final set up
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();
    return app.exec();
}
