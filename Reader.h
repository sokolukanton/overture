#ifndef READER_H
#define READER_H

#include "XmlIO.h"


class Reader
{
public:
    static void readXmlContents(QVector<Project> &, const QString &);
    static QDomElement getProjectRootById(QDomDocument *, const uint);

private:
    static void _listElements(QVector<Project> &, QDomElement &);
    static Project _getProjectWithProperties( const QDomElement &);
    static void _fillVersionVector(QVector<Version> &, const QDomElement &);
    static Version _getVersionWithProperties(const QDomElement &);
    static void _fillElementVector(QVector<Element> &, const QDomElement &);
    static Element _getElementWithProperties( const QDomElement &);
    static QDomDocument _getDomDocumentFromFile(const QString &);
    static QDomElement _getRootElementById(const QDomElement &, const uint);
};

#endif // READER_H
