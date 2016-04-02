#ifndef XMLIO_H
#define XMLIO_H

#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include "Project.h"
#include "Reader.h"
#include <QVector>

class XmlIO
{
public:
    XmlIO(const QString & );
    static void createFile(const QString &);
    QString getFilePath();
    void appendProject(const Project &);
    void appendVersion(const uint, const Version &);
    void renameProject(const uint, const QString &);
    void renameVersion(const uint, const uint, const QString &);
    void setCurrentVersion(const uint, const uint);
    void eraseProject(const uint);
    void eraseVersion(const uint, const uint);
    void flush();

private:
    QDomDocument* _currentDocument;
    QFile* _currentFile;
    QDomElement _initialRoot;
    QDomElement _projectRoot;

    void _initXML();
    void _appendElements(QDomElement &, const QVector<Element> &);
    void _validateFileOpening(const QString &);
    void _appendVersion(const Version &);
    void _setElementAttributes(QDomElement &, const Element &);
    void _setVersionAttributes(QDomElement &, const Version &);
    void _setProjectAttributes(QDomElement &, const Project &);
};

#endif // XMLIO_H
