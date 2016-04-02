#include "versiondetailsform.h"
#include "ui_versiondetailsform.h"
#include <QDebug>

VersionDetailsForm::VersionDetailsForm(Version &version, QString projectPath, int versionNumber,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionDetailsForm)
{
    ui->setupUi(this);
    _verison = &version;
    this->setWindowTitle(this->windowTitle() + " " + _verison->getName());

    index1 = new QModelIndex();
    index2 = new QModelIndex();
    model1 = new QFileSystemModel();
    model2 = new QFileSystemModel();

    *index1 = model1->setRootPath(projectPath+"Version "+QString::number(versionNumber)+"/adds");
    model1->setReadOnly(true);
    *index2 = model2->setRootPath(projectPath+"Version "+QString::number(versionNumber)+"/changed");
    model2->setReadOnly(true);

    chooseDir();

    ui->treeView->setColumnWidth(0,ui->treeView->columnWidth(0)*2);

    connect(ui->radioButton,SIGNAL(clicked(bool)),this,SLOT(chooseDir()));
    connect(ui->radioButton_2,SIGNAL(clicked(bool)),this,SLOT(chooseDir()));
}

VersionDetailsForm::~VersionDetailsForm()
{
    delete ui;
}

void VersionDetailsForm::chooseDir()
{
    if(ui->radioButton->isChecked()){
        ui->treeView->setModel(model1);
        ui->treeView->setRootIndex(*index1);
    }
    else{
        ui->treeView->setModel(model2);
        ui->treeView->setRootIndex(*index2);
    }
}
