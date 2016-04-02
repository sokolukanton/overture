#ifndef VERSIONDETAILSFORM_H
#define VERSIONDETAILSFORM_H

#include <QDialog>
#include "Version.h"
#include "QFileSystemModel"
#include <QModelIndex>
#include <QDirModel>

namespace Ui {
class VersionDetailsForm;
}

class VersionDetailsForm : public QDialog
{
    Q_OBJECT

public:
    explicit VersionDetailsForm(Version &,QString ,int,QWidget *parent = 0);
    ~VersionDetailsForm();
private slots:
    void chooseDir();
private:
    Ui::VersionDetailsForm *ui;
    int _versionNumber;
    Version *_verison;
    QString _storagePath;
    QModelIndex *index1;
    QModelIndex *index2;
    QFileSystemModel *model1;
    QFileSystemModel *model2;
};

#endif // VERSIONDETAILSFORM_H
