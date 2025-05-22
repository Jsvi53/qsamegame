#include <QDir>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>
#include <QSurfaceFormat>
#include <QFileInfo>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // set app name
    app.setOrganizationName("MTXL");
    app.setOrganizationDomain("mtxl.com");
    app.setApplicationName("qsamegame");

    QQuickView view;
    // check whether core configuration was neededj
    if(qgetenv("QT_QUICK_CORE_PROFILE").toInt())
    {
        QSurfaceFormat f = view.format();
        f.setProfile(QSurfaceFormat::CoreProfile);
        f.setVersion(4, 4);
        view.setFormat(f);
    }    // quit signal-slot applied
    QObject::connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);

    // create QQmlFileselector instance
    new QQmlFileSelector(view.engine(), &view);    // set QML file Dir
    view.setSource(QUrl("qrc:/qsamegame/samegame.qml"));

    // check QML file load
    if(view.status() == QQuickView::Error)
        return -1;

    // display ways
    if (QGuiApplication::platformName() == QLatin1String("qnx") ||
        QGuiApplication::platformName() == QLatin1String("eglfs")) {
        view.showFullScreen();
    } else {
        view.show();
    }

    return app.exec();
}
