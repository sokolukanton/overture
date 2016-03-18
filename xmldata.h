#ifndef XMLDATA_H
#define XMLDATA_H
#include <iostream>
#include <QString>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QVector>
#include "QFile"
#include <QDebug>
using namespace std;
class Element{
private:
    int _id;
    int _parentId;
    QString _name;
    QString _path;
public:
    Element(){}
    Element(int id,int parentId,QString name,QString path): _id(id), _parentId(parentId), _name(name), _path(path){}
    const int getId(){
        return _id;
    }
    const int getParentId(){
        return _parentId;
    }
    const QString getName(){
        return _name;
    }
    const QString getPath(){
        return _path;
    }
};

class Version{
private:
    int _id;
    QString _name;
    QVector<Element> _elements;
public:
    Version(){}
    Version(int id, QString name, QVector<Element> elements):_id(id), _name(name), _elements(elements){}
    int getId(){
        return _id;
    }
    QString getName(){
        return _name;
    }
    QVector<Element> getElements(){
        return _elements;
    }
};
class Project{
private:
    int _id;
    QString _name;
    QString _origin_path;
    QVector<Version> _versions;
public:
    Project(){}
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
class XmlData
{
private:
    bool XmlData::openFile(QFile *);
    QVector<Element> *getElements(QXmlStreamReader *);
    QVector<Version> *getVersions(QXmlStreamReader *);
    bool isProject(QXmlStreamReader *);
    bool isVersion(QXmlStreamReader *);
    bool isElement(QXmlStreamReader *);
    Project *XmlData::getProjectByXmlReader(QXmlStreamReader *);
    Version *XmlData::getVersionByXmlReader(QXmlStreamReader *);
    Element *XmlData::getElementByAttributes(QXmlStreamAttributes);
public:
    XmlData();
    QVector<Project> *getProjects(QString);
};

#endif // XMLDATA_H
