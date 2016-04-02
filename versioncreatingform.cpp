#include "versioncreatingform.h"
#include "ui_versioncreatingform.h"

VersionCreatingForm::VersionCreatingForm(const QString& path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionCreatingForm)
{
    ui->setupUi(this);
    fsModel = new QFileSystemModel();
    mdIndex = new QModelIndex();

    *mdIndex = fsModel -> setRootPath(path);
    fsModel->setReadOnly(true);

    ui->treeView->setModel(fsModel);
    ui->treeView->setRootIndex(*mdIndex);
}

VersionCreatingForm::~VersionCreatingForm()
{
    delete ui;
}
