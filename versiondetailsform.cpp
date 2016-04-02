#include "versiondetailsform.h"
#include "ui_versiondetailsform.h"
#include <QDebug>

VersionDetailsForm::VersionDetailsForm(Version &version,QString projectPath,int versionNumber,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionDetailsForm)
{
    ui->setupUi(this);
    _verison=&version;
    this->setWindowTitle(this->windowTitle()+" "+_verison->getName());
    index1=new QModelIndex();
    index2=new QModelIndex();
    model1=new QFileSystemModel() ;
    model2=new QFileSystemModel() ;
    qDebug()<<projectPath+"Version "+QString(versionNumber)+"/changed";
    *index1=model1->setRootPath(projectPath+"Version "+QString::number(versionNumber)+"/adds");
    //*index1=model1->setRootPath("G:/OvertureStorage/Version 1/changed");
    model1->setReadOnly(1);
    *index2=model2->setRootPath(projectPath+"Version "+QString::number(versionNumber)+"/changed");
    qDebug()<<projectPath+"Version "+QString(versionNumber)+"/deleted";
    //*index2=model2->setRootPath("G:/OvertureStorage/Version 1/deleted");
    model2->setReadOnly(1);
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
