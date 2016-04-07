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

    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(setFileOnDelete()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(addFile()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(createFolderInVersion()));
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
            qDebug() << _thisProject.getOriginPath() + "/" + folderName;
        }
    }
}

void VersionCreatingForm::setFileOnDelete()
{
    _filesToDelete << _fsModel->fileInfo(ui->treeView->currentIndex()).absoluteFilePath();
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
        _filesToAddTo << _fsModel->fileInfo(currentIndex).absoluteFilePath();
        _filesToAddFrom << filePath;
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
    foreach(QString folderPath, _newFolders) {
        FileMover::removeDir(folderPath);
    }

    close();
}

void VersionCreatingForm::okClicked()
{
    QDir dir;
    QString pathToMove = _storagetPath + _thisProject.getName() + "/" +
            _thisProject.getCurrentVersion().getName() + "/changed/";

    foreach (QString filePath, _filesToDelete) {
        qDebug() << FileMover::moveFile(filePath, pathToMove);
    }

    QString pathToCopy = _storagetPath + _thisProject.getName() +
            "/Version " + QString::number(_thisProject.getVersions().last().getId() + 1) + "/adds";

    dir.mkpath(pathToCopy);
    int fileCount = _filesToAddTo.count();
    for (int i(0); i < fileCount; ++i) {
        FileMover::copyFile(_filesToAddFrom.at(i), _filesToAddTo.at(i));
        FileMover::copyFile(_filesToAddFrom.at(i), pathToCopy);
    }

    close();
}
