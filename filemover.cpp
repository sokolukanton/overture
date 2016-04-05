#include "filemover.h"
#include <QDebug>

FileMover::FileMover(const QString & originalPath,const QString & reservoirPath):
    _storagePath(reservoirPath),                                           //вносим путь к файлам в хранилище(!наличие "/" в конце!)
    _originPath(originalPath)                                          //вносим путь к файлам выбранного проекта(!наличие "/" в конце!)
{
}

bool FileMover::moveFile(const QString& oldName, const QString& newName)
{
    qDebug()<<oldName<<' '<<newName;
    QFile newFile(newName);
    if (newFile.exists()) {
        newFile.remove();
    }
    return QFile::rename(oldName,newName);
}

bool FileMover::copyFile(const QString& from, const QString& to)
{
    QFile newFile(to);
    if (newFile.exists()) {
        newFile.remove();
    }
    return QFile::copy(from,to);
}

bool FileMover::removeDir(const QString& dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        foreach(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System |
                                                  QDir::Hidden  | QDir::AllDirs |
                                                  QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = removeDir(info.absoluteFilePath());
            } else {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }

    return result;
}

void FileMover::moveFilesWhenJump(const QMap<QString,Element> &tomove,const QMap<QString,Element> & todelete, QString prjNum)
{
    QDir dir;
    for(auto it=todelete.end();it!=todelete.begin();){
        it--;
        qDebug()<<"delete from "+_originPath+it.value().getPath();
        if(!it.value().isFolder())
            QFile::remove(_originPath+it.value().getPath());
        else dir.rmdir(_originPath+it.value().getPath());
    }
    for(auto elem:tomove){
        QString from=_storagePath+"Project "+prjNum+ "/Version " + QString::number(elem.getVersionId()) +
                +"/adds" + elem.getPath();
        QString to=_originPath+elem.getPath();
        qDebug()<<"copy from "<<from<<" to "<<to;
        if(!elem.isFolder())
            FileMover::copyFile(from,to);
        else dir.mkdir(_originPath+elem.getPath());
    }
}

void FileMover::moveFilesWhenRollback(const QMap<QString,Element> &tomove,const QMap<QString,Element> & todelete, QString prjNum)
{
    QDir dir;
    for(auto it=todelete.cend();it!=todelete.cbegin();){
        it--;
        qDebug()<<"delete from "+_originPath+it.value().getPath();
        if(!it.value().isFolder())
            QFile::remove(_originPath+it.value().getPath());
        else dir.rmdir(_originPath+it.value().getPath());
    }

    for(auto elem:tomove) {
        QString from=_storagePath+"Project "+prjNum+ "/Version " + QString::number(elem.getVersionId()) +
                +"/changed" + elem.getPath();
        QString to=_originPath+elem.getPath();
        qDebug()<<"copy from "<<from<<" to "<<to;
        if(!elem.isFolder())
            FileMover::copyFile(from,to);
        else dir.mkdir(_originPath+elem.getPath());
    }
}

