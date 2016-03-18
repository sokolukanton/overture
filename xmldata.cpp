#include "xmldata.h"
XmlData::XmlData(){
    path = "F:\sample.xml";
    QVector<Project> *projects = getProjects();
    Project tmpProject;
    int projectsCount = projects->size();
    cout << "Projects in xml: " << projectsCount << endl;
    for (int i = 0; i < projectsCount; i++) {
        tmpProject = projects->at(i);
        cout << "Project id=" << tmpProject.getId() << endl;
        cout << "   Versions in project: " << tmpProject.getVersions().size() << endl;
        for (int j = 0; j < tmpProject.getVersions().size(); j++) {
            cout << "      " << tmpProject.getVersions()[j].getId()<< " " << endl;
            for (int k = 0; k < tmpProject.getVersions()[j].getElements().size(); k++) {
                cout << "         " << tmpProject.getVersions()[j].getElements()[k].getId()<< " " << endl;
            }
        }
    }
    delete projects;
}

void XmlData::setPath(QString path)
{
    this->path=path;
}
QVector<Project> *XmlData::getProjects(){
    QVector<Project> *projects = new QVector<Project>();
    QFile* file = new QFile(path);
    if (openFile(file)) {
        QXmlStreamReader *xmlReader = new QXmlStreamReader(file);
        xmlReader->readNextStartElement();
        while(!xmlReader->atEnd()) {
            if(isProject(xmlReader)){
                Project *tmpProject = getProjectByXmlReader(xmlReader);
                projects->push_back(*tmpProject);
                delete tmpProject;
            }
            xmlReader->readNextStartElement();
        }
    }
    delete file;
    return projects;
}
bool XmlData::openFile(QFile *file){
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)){
        cout << "FILE NOT FOUND";
        return false;
    } else {
        return true;
    }
}

bool XmlData::isProject(QXmlStreamReader *xmlReader){
    return  xmlReader->isStartElement() && xmlReader->name() == "project";
}


Project *XmlData::getProjectByXmlReader(QXmlStreamReader *xmlReader){
    QXmlStreamAttributes attributes = xmlReader->attributes();

    int id = attributes[0].value().toInt();;
    QString name = attributes[1].value().toString();
    QString origin_path = attributes[2].value().toString();
    QVector<Version> *versions = getVersions(xmlReader);
    Project *project = new Project(id, name, origin_path, *versions);
    delete versions;
    return project;
}

QVector<Version> *XmlData::getVersions(QXmlStreamReader *xmlReader){
    xmlReader->readNextStartElement();
    QVector<Version> *versions = new QVector<Version>();
    while(isVersion(xmlReader)){
        Version *version = getVersionByXmlReader(xmlReader);
        versions->push_back(*version);
        delete version;
        xmlReader->readNextStartElement();
    }
    return versions;
}
bool XmlData::isVersion(QXmlStreamReader *xmlReader){
    return  xmlReader->isStartElement() && xmlReader->name() == "version";
}


Version *XmlData::getVersionByXmlReader(QXmlStreamReader *xmlReader){
    QXmlStreamAttributes attributes = xmlReader->attributes();
    int id = attributes[0].value().toInt();
    QString name = attributes[1].value().toString();
    QVector<Element> *elements = getElements(xmlReader);
    Version *version = new Version(id, name, *elements);
    delete elements;
    return version;
}


QVector<Element> *XmlData::getElements(QXmlStreamReader *xmlReader){
    QVector<Element> *elements = new QVector<Element>();
    xmlReader->readNextStartElement();
    while(isElement(xmlReader)) {
        if(xmlReader->isStartElement()){
            Element *element = getElementByAttributes(xmlReader->attributes());
            elements->push_back(*element);
            delete element;
        }
        xmlReader->readNextStartElement();
    }
    return elements;
}


bool XmlData::isElement(QXmlStreamReader *xmlReader){
    return xmlReader->name() == "file" || xmlReader->name() == "folder";
}

Element *XmlData::getElementByAttributes(QXmlStreamAttributes attributes){
    int id = attributes[0].value().toInt();
    int parentId = attributes[1].value().toInt();
    QString name = attributes[2].value().toString();
    QString path = attributes[3].value().toString();
    Element *element = new Element(id, parentId, name, path);
    return element;
}
