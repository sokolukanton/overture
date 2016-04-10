#include "versioncreatingform.h"
#include "ui_versioncreatingform.h"
#include <QDebug>
VersionCreatingForm::VersionCreatingForm(const QString& storagePath, const Project& thisPrj,
                                         const Version& currentVer, QWidget *parent) :
    QDialog(parent), ui(new Ui::VersionCreatingForm), _storagetPath(storagePath),
    _thisProject(thisPrj), _currentVersion(currentVer)
{
    ui->setupUi(this);

    _fsModel = new QFileSystemModel();
    _mdIndex = new QModelIndex();

    *_mdIndex = _fsModel -> setRootPath(_thisProject.getOriginPath());
    _fsModel->setReadOnly(true);

    ui->treeView->setModel(_fsModel);
    ui->treeView->setRootIndex(*_mdIndex);

    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(setFileOnDelete()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addFile()));
    connect(ui->folderCreateButton, SIGNAL(clicked()), this, SLOT(createFolderInVersion()));
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));
}

VersionCreatingForm::~VersionCreatingForm()
{
    delete ui;
}

void VersionCreatingForm::getNewFolderName(const QString& folderName)
{
    if (folderName != "") {
        _fsModel->mkdir(!ui->treeView->currentIndex().isValid() ?
                            *_mdIndex : ui->treeView->currentIndex(), folderName);
        if (!ui->treeView->currentIndex().isValid()) {
            _newFolders << _thisProject.getOriginPath() + "/" + folderName;
        }
    }
}

void VersionCreatingForm::setFileOnDelete()
{
    QString fileToDelete = _fsModel->fileInfo(ui->treeView->currentIndex()).absoluteFilePath();
    qDebug() << FileMover::moveFile(fileToDelete, _getPathToCurrentVersionFolder(QFileInfo(fileToDelete), "changed"));
    _filesToDelete << fileToDelete;
}

void VersionCreatingForm::addFile()
{
    QString filePath = QFileDialog::getOpenFileName(0, "Укажите путь к добавляемому файлу/папке",
                                                       _fsModel->rootPath(), "Все файлы(*.*)");
    if (filePath == "") {
        return;
    } else {
        QModelIndex currentIndex = !ui->treeView->currentIndex().isValid() ?
                    *_mdIndex : ui->treeView->currentIndex();

        QString fileToAddTo = _fsModel->fileInfo(currentIndex).absoluteFilePath() +
                "/" + QFileInfo(filePath).fileName();

        _filesToAddTo << fileToAddTo;
        _filesToAddFrom << filePath;

        // Файлы копируются сразу, чтобы отобразить изменения в TreeView, при
        // нажатии Отмена все добавленные файлы удалятся, удаленные -
        // восстановятся
        qDebug() << FileMover::copyFile(filePath, fileToAddTo);
    }
}

void VersionCreatingForm::createFolderInVersion()
{
    newFolderForm = new AddNewFolderForm(this);
    connect(newFolderForm, SIGNAL(sendNewFolderName(const QString &)),
            this, SLOT(getNewFolderName(const QString &)));
    newFolderForm -> show();
    newFolderForm -> exec();
}

void VersionCreatingForm::cancelClicked()
{
    if (_isVersionChanged()) {
        foreach(QString addedPath, _filesToAddTo) {
            QFile(addedPath).remove(addedPath);
        }

        foreach(QString folderPath, _newFolders) {
            FileMover::removeDir(folderPath);
        }

        foreach (QString deletedPath, _filesToDelete) {
            FileMover::moveFile(_getPathToCurrentVersionFolder(QFileInfo(deletedPath), "changed"),
                                            deletedPath);
        }
    }
    close();
}

void VersionCreatingForm::okClicked()
{
    if (_isVersionChanged()) {
        QString path = _storagetPath + _thisProject.getName() + "/Version "
                + QString::number(_thisProject.getVersions().last().getId() + 1) + "/adds/";
        QDir().mkpath(path);

        foreach (QString folderPath, _newFolders) {
            QDir().mkdir(path + QFileInfo(folderPath).fileName());
        }

        int fileCount = _filesToAddTo.count();
        for (int i(0); i < fileCount; ++i) {
            FileMover::copyFile(_filesToAddFrom.at(i),
                                _getPathToNewVersionFolder(QFileInfo(_filesToAddTo.at(i)), "adds"));
        }
    }
    close();
}

QString VersionCreatingForm::_getPathToNewVersionFolder(const QFileInfo& fileInfo, const QString& folderName)
{
    return _storagetPath + _thisProject.getName() +
            "/Version " + QString::number(_thisProject.getVersions().last().getId() + 1) +
            "/" + folderName + "/" + fileInfo.fileName();
}

QString VersionCreatingForm::_getPathToCurrentVersionFolder(const QFileInfo& fileInfo, const QString& folderName)
{
    return _storagetPath + _thisProject.getName() + "/" + _currentVersion.getName() +
            "/" + folderName + "/" + fileInfo.fileName();
}

bool VersionCreatingForm::_isVersionChanged()
{
    return  !_filesToAddFrom.empty() ||
            !_filesToAddTo.empty() ||
            !_filesToDelete.empty() ||
            !_newFolders.empty();
}

void VersionCreatingForm::on_treeView_pressed(const QModelIndex& index)
{
    if (index.isValid()) {
        ui->deleteButton->setEnabled(true);
    }
}
