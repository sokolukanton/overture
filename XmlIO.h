#ifndef XMLIO_H
#define XMLIO_H

#include <QDomDocument>
#include <QDirIterator>
#include <QFile>
#include <QVector>
#include <QDebug>
#include "Project.h"


class XmlIO
{
public:
    XmlIO(const QString &);

    void appendProject(const Project &);
    void appendVersion(const Version &);

    void flush();

private:
    QDomDocument* _currentDocument;
    QFile* _currentFile;
    QDomElement _dRoot;

    void _initXML();
    void _validateFileOpening(const QString &);
    void _appendElements(const QVector<Element> &);
    void _setElementAttributes(QDomElement &, const Element &);
    void _setVersionAttributes(QDomElement &, const Version &);
    void _setProjectAttributes(QDomElement &, const Project &);
};

#endif // XMLIO_H
