#include "XmlIO.h"

//***********************
// Public method section
//***********************

XmlIO::XmlIO(const QString& filePath)
{
    _currentDocument = new QDomDocument();
    _currentFile = new QFile(filePath);

    _validateFileOpening(filePath);
    _initXML();
}

QString XmlIO::getFilePath()
{
    return _currentFile -> fileName();
}

void XmlIO::createFile(const QString& filePath)
{
    QFile xml(filePath);
    xml.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream(&xml)
            << "<?xml version='1.0' encoding='utf-8'?>\n<Overture>\n</Overture>";
    xml.close();
}

void XmlIO::appendProject(const Project& source)
{
    QDomElement project = _currentDocument -> createElement("Project");

    _setProjectAttributes(project, source);

    _initialRoot.appendChild(project);
    _projectRoot = project;

    _appendVersion(source.getVersions().at(0));
}

void XmlIO::appendVersion(const uint id, const Version& source)
{
    _projectRoot = Reader::getProjectRootById(_currentDocument, id);
    _appendVersion(source);
}

void XmlIO::renameProject(const uint projId, const QString& newName)
{
   Reader::getProjectRootById(_currentDocument, projId).setAttribute("name", newName);
}

void XmlIO::renameVersion(const uint projId, const uint verId, const QString& newName)
{
    QDomElement projRoot = Reader::getProjectRootById(_currentDocument, projId);
        QDomNodeList versions = projRoot.elementsByTagName("Version");
        int versionNumber = versions.count();

        if (versionNumber == 1) {
            versions.at(0).toElement().setAttribute("name", newName);
            return;
        }

        for (int i(0); i < versionNumber; ++i) {
            QDomNode node = versions.at(i);
            if (node.isElement()) {
                QDomElement version = node.toElement();
                if (version.attribute("id") == QString::number(verId)) {
                    version.setAttribute("name", newName);
                }
            }
        }
}

void XmlIO::setCurrentVersion(const uint projId, const uint verId)
{
    Reader::getProjectRootById(_currentDocument, projId).setAttribute("currentversion", verId);
}

void XmlIO::eraseProject(const uint projId)
{
    _initialRoot.removeChild(Reader::getProjectRootById(_currentDocument, projId));
}

void XmlIO::eraseVersion(const uint projId, const uint verId)
{
    QDomElement projRoot = Reader::getProjectRootById(_currentDocument, projId);
        QDomNodeList versions = projRoot.elementsByTagName("Version");
        int versionNumber = versions.count();

        if (versionNumber == 1) {
            eraseProject(projId);
            return;
        }

        for (int i(0); i < versionNumber; ++i) {
            QDomNode node = versions.at(i);
            if (node.isElement()) {
                QDomElement version = node.toElement();
                if (version.attribute("id") == QString::number(verId)) {
                    projRoot.removeChild(version);
                    return;
                }
            }
        }
}
void XmlIO::flush()
{
    _currentFile -> open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    QTextStream str(_currentFile);
    str << _currentDocument -> toString();
    _currentFile -> close();
}

//***********************
// Private method section
//***********************

void XmlIO::_initXML()
{
    if (!_currentDocument -> setContent(_currentFile)) {
        qCritical() << "Критическая ошибка в чтении xml-файла" <<
                        _currentFile -> fileName();
        exit(8);
    }
    _initialRoot = _currentDocument -> firstChildElement();
    _currentFile -> close();
}

void XmlIO::_appendElements(QDomElement& root, const QVector<Element>& source)
{
    auto it = source.begin();
    auto end = source.end();

    for (;it != end;) {
        QDomElement element;
        if (it -> isFolder()) {
            element = _currentDocument -> createElement("Folder");
        }
        else {
            element = _currentDocument -> createElement("File");
        }
        _setElementAttributes(element, *it++);
        root.appendChild(element);
    }
}

void XmlIO::_validateFileOpening(const QString& filePath)
{
    if (!_currentFile -> open(QIODevice::ReadWrite | QIODevice::Text)) {
        qCritical() << "Критическая ошибка: файл" << filePath <<
                       "не может быть открыт";
        exit(1);
    }
}

void XmlIO::_appendVersion(const Version& source)
{
    QDomElement version = _currentDocument -> createElement("Version");

    _setVersionAttributes(version, source);

    _projectRoot.appendChild(version);

    _appendElements(version, source.getElements());
}

void XmlIO::_setElementAttributes(QDomElement& element, const Element& item)
{
    element.setAttribute("path", item.getPath());
    element.setAttribute("is_new",item.isNew());
    element.setAttribute("is_deleted",item.isDeleted());
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
    project.setAttribute("currentversion", source.getCurrentVersionId());
}
