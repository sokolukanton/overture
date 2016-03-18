#ifndef XMLDATA_H
#define XMLDATA_H
#include <iostream>
#include <QString>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QVector>
#include "QFile"
#include <Project.h>
#include <Version.h>
#include <Element.h>
#include <QDebug>
using namespace std;

class XmlData
{
private:
    QString path;
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
    void setPath(QString );
    QVector<Project> *getProjects();
};

#endif // XMLDATA_H
