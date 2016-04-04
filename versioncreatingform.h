#ifndef VERSIONCREATINGFORM_H
#define VERSIONCREATINGFORM_H

#include <QDialog>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QStringList>
#include "addnewfolderform.h"
#include "filemover.h"
#include "Project.h"


namespace Ui {
    class VersionCreatingForm;
}

class VersionCreatingForm : public QDialog
{
    Q_OBJECT

public:
    explicit VersionCreatingForm(const QString &, QWidget *parent = 0);
    ~VersionCreatingForm();

public slots:
    void getNewFolderName(const QString &);

private slots:
    void setFileOnDelete();
    void addFile();
    void createFolderInVersion();

private:
    Ui::VersionCreatingForm *ui;
    AddNewFolderForm* newFolderForm;
    QFileSystemModel* _fsModel;
    QModelIndex* _mdIndex;
    QStringList _filesToAdd;
    QStringList _filesToDelete;
    QStringList _newFolders;

};

#endif // VERSIONCREATINGFORM_H
