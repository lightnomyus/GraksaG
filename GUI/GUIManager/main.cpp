#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "api_guimanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
        API_GUIManager haha;

        engine.rootContext()->setContextProperty("haha",&haha);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
