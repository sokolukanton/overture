#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>
#include <Version.h>
#include <filemover.h>
class Project
{
private:
    int _id;
    int _currentVersionId;
    QString _name;
    QString _originPath;
    QVector<Version> _versions;
public:
    Project();
    Project(int id,int versionId,QString name,QString origin_path, QVector<Version> versions)
        :_id(id),_currentVersionId(versionId), _name(name), _originPath(origin_path), _versions(versions){
    }
    int getId()const{
        return _id;
    }
    QString getName()const{
        return _name;
    }
    QString getOriginPath()const{
        return _originPath;
    }
    QVector<Version> getVersions()const{
        return _versions;
    }
    int getCurrentVersionId()const{
        return _currentVersionId;
    }
    void setName(QString &name){
        _name=name;
    }
    void setCurrentVersion(int versionid){
        _currentVersionId=versionid;
    }
    void renameVersion(int versionNumber,QString newName){
        _versions[versionNumber].setName(newName);
    }
    void deleteVersion(int versionNumber){
        _versions.removeAt(versionNumber);
    }
    void jumpToVersion(int ,QString,QString);
    void rollbackToversion(int,QString,QString);
};

#endif // PROJECT_H
