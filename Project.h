#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>
#include <Version.h>
#include <qvector.h>
#include <qstring.h>

class Project
{
private:
    int _id;
    QString _name;
    QString _origin_path;
    QVector<Version> _versions;
public:
    Project();
    Project(int id,QString name,QString origin_path, QVector<Version> versions):_id(id), _name(name), _origin_path(origin_path), _versions(versions){}
    int getId(){
        return _id;
    }
    QString getName(){
        return _name;
    }
    QString getOriginPath(){
        return _origin_path;
    }
    QVector<Version> getVersions(){
        return _versions;
    }
};

#endif // PROJECT_H
