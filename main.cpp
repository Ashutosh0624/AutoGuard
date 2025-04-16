#include <QCoreApplication>
#include "sensorpresenter.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);  // ✅ Correct application object

        QQmlApplicationEngine engine;

        SensorDataModel model;
        sensorPresenter presenter;

        engine.rootContext()->setContextProperty("presenter", &presenter);

        //engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));

        //engine.load(QUrl::fromLocalFile("main.qml"));

        //engine.load(QUrl::fromLocalFile("../Adas_industrial_app/main.qml"));

        //engine.load(QUrl::fromLocalFile("/home/ashutosh/Desktop/QT-Qml/Lane_Adas/Adas_industrial_app/main.qml"));


        engine.load(QUrl::fromLocalFile("/home/ashutosh/Desktop/QT-Qml/Lane_ADAS/ADAS_inustrial_app/main.qml"));

        if (engine.rootObjects().isEmpty())  // ❗ Always good to add this check
            return -1;

        return app.exec();  // ✅ Use 'app' not 'a'
}
