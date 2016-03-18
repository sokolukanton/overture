#include "XmlIO.h"

XmlIO::XmlIO(const QString& filePath)
{
    _currentDocument = new QDomDocument();
    _currentFile = new QFile(filePath);

    _validateFileOpening(filePath);
    _initXML();
}

void XmlIO::appendProject(const Project& source)
{
    QDomElement project = _currentDocument -> createElement("Project");

    _setProjectAttributes(project, source);

    _dRoot.appendChild(project);
    _dRoot = project;
}

void XmlIO::appendVersion(const Version& source)
{
    QDomElement version = _currentDocument -> createElement("Version");

    _setVersionAttributes(version, source);

    _dRoot.appendChild(version);
    _dRoot = version;

    _appendElements(source.getElements());
}

void XmlIO::flush()
{
    QTextStream str(_currentFile);
    str << _currentDocument -> toString();
}

void XmlIO::_initXML()
{
    _currentDocument -> setContent(QString("<?xml version='1.0' encoding='UTF-8'?>"));
    _currentDocument -> appendChild(_currentDocument -> createTextNode("\n"));

    _dRoot = _currentDocument -> createElement("Overture");

    _currentDocument -> appendChild(_dRoot);
}

void XmlIO::_validateFileOpening(const QString& filePath)
{
    if (!_currentFile -> open(QIODevice::WriteOnly | QIODevice::Text)) {
        qCritical() << "Критическая ошибка";
        qCritical() << "Файл " << filePath << " не может быть открыт на запись";
        exit(1);
    }
}

void XmlIO::_appendElements(const QVector<Element>& source)
{
    auto it = source.begin();
    auto end = source.end();

    for (;it != end; ++it) {
        QDomElement element = _currentDocument -> createElement("Element");
        _setElementAttributes(element, *it);
        _dRoot.appendChild(element);
    }
}

void XmlIO::_setElementAttributes(QDomElement& element, const Element& item)
{
    element.setAttribute("id", item.getId());
    element.setAttribute("parentId", item.getParentId());
    element.setAttribute("name", item.getName());
    element.setAttribute("path", item.getPath());
}

void XmlIO::_setVersionAttributes(QDomElement& version, const Version& source)
{
    version.setAttribute("id", source.getId());
    version.setAttribute("name", source.getName());
}

void XmlIO::_setProjectAttributes(QDomElement& project, const Project& source)
{
    project.setAttribute("id", source.getId());
    project.setAttribute("name", source.getName());
    project.setAttribute("origin_path", source.getOriginPath());
}
