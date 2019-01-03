#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
// basic set up
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QQuickStyle::setStyle("Fusion");
    QQuickView viewer;

// object declaration


// connection between objects
    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);


// binding c++ with qml


// final set up

    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.showFullScreen();

    return app.exec();
}
