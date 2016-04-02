#include "Reader.h"
#include <qdebug.h>

void Reader::readXmlContents(QVector<Project>& target, const QString &filePath)
{
    QDomElement root = _getDomDocumentFromFile(filePath).firstChildElement();
    _listElements(target, root);
}

QDomElement Reader::getProjectRootById(QDomDocument* docRoot, const uint id)
{
    QDomNodeList projects = docRoot -> firstChildElement().elementsByTagName("project");
    int projectNumber = projects.count();
    if (projectNumber == 1) {
        return projects.at(0).toElement();
    }
    for (int i(0); i < projectNumber; ++i) {
        QDomNode node = projects.at(i);
        if (node.isElement()) {
            QDomElement project = node.toElement();
                if (project.attribute("id") == QString::number(id)) {
                    return project;
                }
            }
        }

    return QDomElement();
}

void Reader::_listElements(QVector<Project>& target, QDomElement& root)
{
    QDomNodeList projects = root.elementsByTagName("project");
    int projectNumber = projects.count();

    if (!target.empty()) {
        target.clear();
    }

    for (int i(0); i < projectNumber; ++i) {
        QDomNode node = projects.at(i);
        if (node.isElement()) {
            QDomElement projectElement = node.toElement();
            Project project=_getProjectWithProperties( projectElement);
            target.append(project);
        }
    }
}

Project Reader::_getProjectWithProperties( const QDomElement& source)
{
    int id=source.attribute("id").toInt();
    int versionid=source.attribute("currentversion").toInt();
    QString name=source.attribute("name");
    QString originpath=source.attribute("origin_path");
    QVector<Version> versions;
    _fillVersionVector(versions, source);
    Project prj(id,versionid,name,originpath,versions);
    return prj;
}

void Reader::_fillVersionVector(QVector<Version>& target, const QDomElement& source)
{
    QDomNodeList versions = source.elementsByTagName("version");
    int versionNumber = versions.count();

    if (!target.isEmpty()) {
        target.clear();
    }

    for (int i(0); i < versionNumber; ++i) {
        QDomNode node = versions.at(i);
        if (node.isElement()) {
            QDomElement versionElement = node.toElement();
            Version version=_getVersionWithProperties( versionElement);
            target.append(version);
        }
    }
}

Version Reader::_getVersionWithProperties( const QDomElement& source)
{
    QVector<Element> elements;
    _fillElementVector(elements, source);
    Version ver(source.attribute("id").toInt(),source.attribute("name"),elements);
    return ver;
}

void Reader::_fillElementVector(QVector<Element>& target, const QDomElement& source)
{
    QDomNodeList elements = source.childNodes();
    int elementNumber = elements.count();

    if (!target.isEmpty()) {
        target.clear();
    }

    for (int i(0); i < elementNumber; ++i) {
        QDomNode elementNode = elements.at(i);
        if (elementNode.isElement()) {
            QDomElement fileSystemElement = elementNode.toElement();
            Element element=_getElementWithProperties(fileSystemElement);
            target.append(element);
        }
    }
}

Element Reader::_getElementWithProperties( const QDomElement& source)
{
    QString path=source.attribute("path");
    bool isnew=source.attribute("is_new").toInt();
    bool isdeleted=source.attribute("is_deleted").toInt();
    Element elem(path,isnew,isdeleted);
    if (source.tagName() == "folder") {
         elem.setType(1);
    } else {
         elem.setType(0);
    }
    return elem;
}

QDomDocument Reader::_getDomDocumentFromFile(const QString& filePath)
{
    QFile* currentFile = new QFile(filePath);
    if (!currentFile -> open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Критическая ошибка: файл" << filePath <<
                       "не может быть открыт";
        exit(2);
    }

    QDomDocument mainDoc;

    if (!mainDoc.setContent(currentFile)) {
        qDebug() << "Критическая ошибка: не удалось загрузить документ" <<
                       filePath;
        exit(3);
    }
    currentFile -> close();

    delete currentFile;
    return mainDoc;
}

QDomElement Reader::_getRootElementById(const QDomElement& root, const uint id)
{
    QDomNodeList projects = root.elementsByTagName("project");
    int projectNumber = projects.count();

    for (int i(0); i < projectNumber; ++i) {
        QDomNode node = projects.at(i);
        if (node.isElement()) {
            QDomElement project = node.toElement();
            if (project.attribute("id") == QString::number(id)) {
                return project;
            }
        }
    }

    return QDomElement();
}
