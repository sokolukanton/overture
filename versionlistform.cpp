#include "versionlistform.h"
#include "ui_versionlistform.h"

VersionListForm::VersionListForm(QString projectName,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionListForm)
{
    ui->setupUi(this);
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(showVersionDetailsForm()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(moveConfirm()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(deleteConfirm()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(showVersionCreatingForm()));
}

VersionListForm::~VersionListForm()
{
    delete ui;
}

void VersionListForm::showVersionDetailsForm()
{
    versionDetailsForm=new VersionDetailsForm();
    versionDetailsForm->show();
    versionDetailsForm->setAttribute(Qt::WA_DeleteOnClose);
}

void VersionListForm::showVersionCreatingForm()
{
    versionCreatingForm=new VersionCreatingForm();
    versionCreatingForm->show();
    versionCreatingForm->setAttribute(Qt::WA_DeleteOnClose);
}

void VersionListForm::deleteConfirm()
{
    deleteConfirming=new QMessageBox();
    deleteConfirming->addButton("Да",QMessageBox::YesRole);
    deleteConfirming->addButton("Нет",QMessageBox::NoRole);
    deleteConfirming->setText("Вы уверены ,что хотите удалить эту версию?Вы уже не сможете восстановить ее файлы");
    deleteConfirming->setWindowTitle("Подтверждение удаления");
    deleteConfirming->setIcon(QMessageBox::Question);
    deleteConfirming->show();
    deleteConfirming->setAttribute(Qt::WA_DeleteOnClose);
}

void VersionListForm::moveConfirm()
{
    moveConfirming=new QMessageBox();
    moveConfirming->addButton("Да",QMessageBox::YesRole);
    moveConfirming->addButton("Нет",QMessageBox::NoRole);
    moveConfirming->setText("Вы уверены ,что хотите перейти к этой версии?");
    moveConfirming->setWindowTitle("Подтверждение перехода");
    moveConfirming->setIcon(QMessageBox::Question);
    moveConfirming->show();
    moveConfirming->setAttribute(Qt::WA_DeleteOnClose);
}
