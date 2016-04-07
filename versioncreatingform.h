#ifndef VERSIONCREATINGFORM_H
#define VERSIONCREATINGFORM_H

#include <QDialog>
#include <QDir>
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
    explicit VersionCreatingForm(const QString &, const Project &,
                                 const Version &, QWidget *parent = 0);
    ~VersionCreatingForm();

public slots:
    void getNewFolderName(const QString &);

private slots:
    void setFileOnDelete();
    void addFile();
    void createFolderInVersion();
    void cancelClicked();
    void okClicked();

private:
    Ui::VersionCreatingForm *ui;
    AddNewFolderForm* newFolderForm;
    QFileSystemModel* _fsModel;
    QModelIndex* _mdIndex;

    QString _storagetPath;
    Project _thisProject;
    Version _currentVersion;

    QStringList _filesToAddFrom;
    QStringList _filesToAddTo;
    QStringList _filesToDelete;
    QStringList _newFolders;
};

#endif // VERSIONCREATINGFORM_H
