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

    void on_treeView_pressed(const QModelIndex &index);

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

    QString _getPathToNewVersionFolder(const QFileInfo &, const QString &);
    QString _getPathToCurrentVersionFolder(const QFileInfo &, const QString &);
    bool _isVersionChanged();
};

#endif // VERSIONCREATINGFORM_H
