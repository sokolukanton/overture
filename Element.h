#ifndef ELEMENT_H
#define ELEMENT_H
#include <qobject.h>

class Element
{
private:
    int _id;
    int _parentId;
    QString _name;
    QString _path;
public:
    Element();
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

#endif // ELEMENT_H
