#include "JSEventHandler.h"
#include <QDebug>

JSEventHandler::JSEventHandler(QObject *parent) :
    QObject(parent)
{
}

QString JSEventHandler::getPath()
{
   QString pydioDir = QDir::homePath() + "/pydio";
   return QFileDialog::getExistingDirectory(0, tr("Select local path"), pydioDir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}

void JSEventHandler::openUrl(QString toOpen)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(toOpen));
}

/*void JSEventHandler::openUrlSlot(QUrl toOpen){
    qDebug()<<"trying to open in slot"<<toOpen;
    QDesktopServices::openUrl(toOpen);
}*/
