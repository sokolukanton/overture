#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmldata.h"
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(deleteConfirm()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(showRenamingForm()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(showVersionList()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(showProjectCreatingForm()));
    connect(ui->action,SIGNAL(triggered(bool)),this,SLOT(showProjectCreatingForm()));
    connect(ui->action_2,SIGNAL(triggered(bool)),this,SLOT(showVersionList()));
    connect(ui->action_3,SIGNAL(triggered(bool)),this,SLOT(showRenamingForm()));
    connect(ui->action_4,SIGNAL(triggered(bool)),this,SLOT(deleteConfirm()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::deleteConfirm()
{
    deleteConfirming=new QMessageBox();
    deleteConfirming->addButton("Да",QMessageBox::YesRole);
    deleteConfirming->addButton("Нет",QMessageBox::NoRole);
    deleteConfirming->setText("Вы уверены, что хотите удалить этот проект?Вы уже не сможете восстановить его версии позже");
    deleteConfirming->setWindowTitle("Подтверждение удаления");
    deleteConfirming->setIcon(QMessageBox::Question);
    deleteConfirming->show();
    deleteConfirming->setAttribute(Qt::WA_DeleteOnClose);

}

void MainWindow::showRenamingForm()
{

    QString name = QInputDialog::getText(this,"Переименование","Введите новое название проекта");
}

void MainWindow::showVersionList()
{
    versionListForm=new VersionListForm("projectName");
    versionListForm->show();
    versionListForm->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::showProjectCreatingForm()
{
    prjCreatingForm=new ProjectCreatingForm();
    prjCreatingForm->show();
    prjCreatingForm->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::closeEvent(QCloseEvent * ev)
{
    QMessageBox * exitConfirming=new QMessageBox();
    ev->ignore();
    //exitConfirming=QMessageBox::question(this, "Подтверждение закрытия", "Вы уверены, что хотите выйти?",
    //                                             QMessageBox::Yes|QMessageBox::No);
    exitConfirming->addButton("Да",QMessageBox::YesRole);
    exitConfirming->addButton("Нет",QMessageBox::NoRole);
    exitConfirming->setText("Вы уверены, что хотите выйти?");
    exitConfirming->setWindowTitle("Подтверждение закрытия");
    exitConfirming->setIcon(QMessageBox::Question);
    exitConfirming->show();
    exitConfirming->setDefaultButton(QMessageBox::Yes);
    if (QMessageBox::Rejected == exitConfirming->exec())
        {
            ev->accept();
        }
    delete exitConfirming;
}


