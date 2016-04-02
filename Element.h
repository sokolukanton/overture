#ifndef ELEMENT_H
#define ELEMENT_H
#include <qobject.h>

class Element
{
private:
    QString _path;
    bool _isNew;
    bool _isDeleted;
    bool _isFolder;
    int _versionId;
public:
    Element();
    Element(QString path,bool isnew,bool isdeleted):_path(path),_isNew(isnew),_isDeleted(isdeleted){}
    QString getPath()const{
        return _path;
    }
    int getVersionId()const{
        return _versionId;
    }
    void setVersionId(int versionId){
        _versionId=versionId;
    }
    bool isNew()const{
        return _isNew;
    }
    bool isDeleted()const{
        return _isDeleted;
    }
    bool isFolder()const{
        return _isFolder;
    }

    void setType(const int type){
        _isFolder=type;
    }
};

#endif // ELEMENT_H
