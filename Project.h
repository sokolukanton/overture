#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>
#include <Version.h>
#include <filemover.h>
#include <QDebug>

class Project
{
public:
    Project();
    Project(int id,int versionId,QString name,QString origin_path, QVector<Version> versions)
        :_id(id),_currentVersionId(versionId), _name(name), _originPath(origin_path), _versions(versions){
    }
    int getId() const {
        return _id;
    }
    QString getName() const {
        return _name;
    }
    QString getOriginPath() const {
        return _originPath;
    }
    QVector<Version> getVersions() const {
        return _versions;
    }
    Version getCurrentVersion() const {
        foreach (Version ver, _versions) {
            if (ver.getId() == _currentVersionId) {
                return ver;
            }
        }
        return Version();
    }
    int getCurrentVersionId() const {
        return _currentVersionId;
    }
    void setName(QString &name){
        _name=name;
    }
    void setCurrentVersion(int versionid){
        _currentVersionId = versionid;
    }
    void renameVersion(int versionNumber,QString newName){
        _versions[versionNumber].setName(newName);
    }
    void deleteVersion(int versionNumber){
        _versions.removeAt(versionNumber);
    }
    void jumpToVersion(int, QString, QString);
    void rollbackToversion(int ,QString, QString);

private:
    int _id;
    int _currentVersionId;
    QString _name;
    QString _originPath;
    QVector<Version> _versions;
};

#endif // PROJECT_H
