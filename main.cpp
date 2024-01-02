#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <sshclient.h>
#include <sshsftpcommandsend.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    /*
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/QtSshExample/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    */

    SshClient client;

    client.setPassphrase("*****");
    client.connectToHost("*****", "yourhost.org");
    client.waitForState(SshClient::Ready);

    qDebug() << "Connected";

    SshSFtp *sftp = client.getChannel<SshSFtp>("sftp");
    sftp->send("/etc/os-release", "/tmp/os-release");
    qDebug() << "Copy OK";

    //return app.exec();
    return 0;
}
