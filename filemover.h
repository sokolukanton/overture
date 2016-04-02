#ifndef FILEMOVER_H
#define FILEMOVER_H

#include <QFile>
#include <Project.h>
#include <QMap>
#include <QDir>

class FileMover
{
private:

    QString _storagePath;             //путь к хранилищу
    QString _originPath;         //путь к версии

public:

    FileMover(const QString &, const QString &);

    static bool moveFile(const QString & , const QString &);
    static bool copyFile(const QString & , const QString &);
    void moveFilesWhenJump(const QMap<QString,Element> &,const QMap<QString,Element> &,QString prjNum);
    void moveFilesWhenRollback(const QMap<QString,Element> &,const QMap<QString,Element> &,QString prjNum);
};

#endif // FILEMOVER_H
