#include "Project.h"

#include <qdebug.h>

Project::Project()
{

}

void Project::jumpToVersion(int versionId,QString prjNum, QString storagePath)
{
    QMap<QString,Element> tomove;
    QMap<QString,Element> todelete;
    for(Version it:_versions){
        if (it.getId()>_currentVersionId&&it.getId()<=versionId) {
            for(Element itr:it.getElements())
                if(itr.isDeleted()){
                    tomove.remove(itr.getPath());
                    todelete.insert(itr.getPath(),itr);
                }
                  else {
                    itr.setVersionId(it.getId());
                    todelete.remove(itr.getPath());
                    tomove.insert(itr.getPath(),itr);
                }
        }
    }
    _currentVersionId = versionId;
    FileMover(_originPath,storagePath)
            .moveFilesWhenJump(tomove,todelete,prjNum);
}

void Project::rollbackToversion(int versionId, QString prjNum, QString storagePath)
{
    QMap<QString,Element> tomove;
    QMap<QString,Element> todelete;
    for(auto it=_versions.begin();it!=_versions.end();it++)
        if (it->getId()<=_currentVersionId&&it->getId()>versionId) {
            for(Element itr:it->getElements())
                if(itr.isNew()) {
                    itr.setVersionId(it->getId());
                    todelete.insert(itr.getPath(),itr);
                }
                  else {
                    it--;
                    itr.setVersionId(it->getId());
                    it++;
                    if(tomove.find(itr.getPath())==tomove.end())tomove.insert(itr.getPath(),itr);
                }
        }
    for(auto it:todelete)
        tomove.remove(it.getPath());
    _currentVersionId = versionId;
    FileMover(_originPath,storagePath)
            .moveFilesWhenRollback(tomove, todelete, prjNum);
}

