#ifndef VERSIONLISTFORM_H
#define VERSIONLISTFORM_H

#include <QDialog>
#include "versiondetailsform.h"
#include <qmessagebox.h>
#include "versioncreatingform.h"
#include <qinputdialog.h>
#include <XmlIO.h>
namespace Ui {
class VersionListForm;
}

class VersionListForm : public QDialog
{
    Q_OBJECT

public:
    explicit VersionListForm(Project &,QString,XmlIO*,QWidget *parent = 0);
    ~VersionListForm();
    void setProjectPath(int i){
        _projectPath="Project "+QString::number(i)+"/";
    }
private slots:
    void showVersionDetailsForm();
    void showVersionCreatingForm();
    void showRenamingForm();
    void deleteConfirm();
    void moveConfirm();

private:
    void updateVersionsList();
    Ui::VersionListForm *ui;
    VersionDetailsForm * versionDetailsForm;
    QMessageBox * deleteConfirming;
    QMessageBox * moveConfirming;
    VersionCreatingForm * versionCreatingForm;
    Project *_project;
    QString _projectPath;
    QString _storagePath;
    XmlIO * _xmlwriter;
};

#endif // VERSIONLISTFORM_H
