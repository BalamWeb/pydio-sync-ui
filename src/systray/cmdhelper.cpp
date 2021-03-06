#include "cmdhelper.h"

CmdHelper::CmdHelper(QObject *parent, QString path) :
    QObject(parent)
{
    this->pathToWinAgent = path;
}

void CmdHelper::launchAgentMac(bool stopBeforeLaunch){
    QProcess process;
    QString processName = "launchctl";
    QStringList arguments;
    if(stopBeforeLaunch){
        arguments = QStringList() << "remove"<< "PydioSync";
        process.start(processName, arguments);
        process.waitForStarted();
        process.waitForFinished();
    }
    arguments = QStringList()<<"load"<<"-w"<<"/library/LaunchAgents/io.pyd.sync.launcher.plist";
    process.start(processName, arguments);
    process.waitForStarted();
    process.waitForFinished();
}

void CmdHelper::launchAgentWin(){
    QProcess::startDetached(pathToWinAgent, QStringList());
    QTimer::singleShot(1500, this, SIGNAL(winAgentLaunched()));
}

void CmdHelper::stopAgentMac(){
    QProcess process;
    QString processName = "launchctl";
    QStringList arguments = QStringList() << "remove"<< "PydioSync";
    process.start(processName, arguments);
    process.waitForStarted();
    process.waitForFinished();
    arguments = QStringList() << "remove"<< "PydioSyncUI";
    process.start(processName, arguments);
    process.waitForStarted();
    process.waitForFinished();
}
