#include "versioncreatingform.h"
#include "ui_versioncreatingform.h"

VersionCreatingForm::VersionCreatingForm(const QString& _projPath, QWidget *parent) :
    QDialog(parent), ui(new Ui::VersionCreatingForm)
{
    ui->setupUi(this);

    _fsModel = new QFileSystemModel();
    _mdIndex = new QModelIndex();

    *_mdIndex = _fsModel -> setRootPath(_projPath);
    _fsModel->setReadOnly(true);

    ui->treeView->setModel(_fsModel);
    ui->treeView->setRootIndex(*_mdIndex);

    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(setFileOnDelete()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(addFile()));
    connect(ui->buttonBox, SIGNAL(clicked()), this, SLOT(createFolderInVersion()));
    connect(newFolderForm, SIGNAL(sendNewFolderName(QString)), this, SLOT(getNewFolderName(QString)));
}

VersionCreatingForm::~VersionCreatingForm()
{
    delete ui;
}

void VersionCreatingForm::getNewFolderName(const QString& folderName)
{
    _newFolders << folderName;
}

void VersionCreatingForm::setFileOnDelete()
{
    _filesToDelete << _fsModel->fileInfo(ui->treeView->currentIndex()).absoluteFilePath();
}

void VersionCreatingForm::addFile()
{
    QString newFilePath = QFileDialog::getOpenFileName(0, "Укажите путь к добавляемому файлу/папке",
                                                       _fsModel->rootPath(), "Все файлы(*.*)");
    if (newFilePath == "") {
        return;
    } else {
        _filesToAdd << newFilePath;
    }
}

void VersionCreatingForm::createFolderInVersion()
{
    newFolderForm = new AddNewFolderForm();
    newFolderForm -> show();
    newFolderForm -> exec();
    _fsModel->mkdir(ui->treeView->currentIndex(), _newFolders.last());
}
