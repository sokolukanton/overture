#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    _storagePath=readIni();
    _xmlwriter=new XmlIO(_storagePath+"data.xml");
    _projects=new QVector<Project>();
    Reader::readXmlContents(*_projects,_storagePath+"data.xml");
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(deleteConfirm()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(showRenamingForm()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(showVersionList()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(showProjectCreatingForm()));
    connect(ui->action,SIGNAL(triggered(bool)),this,SLOT(showProjectCreatingForm()));
    connect(ui->action_2,SIGNAL(triggered(bool)),this,SLOT(showVersionList()));
    connect(ui->action_3,SIGNAL(triggered(bool)),this,SLOT(showRenamingForm()));
    connect(ui->action_4,SIGNAL(triggered(bool)),this,SLOT(deleteConfirm()));
    updateProjectsList();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete _xmlwriter;
    delete _projects;
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
    if(deleteConfirming->exec()==QMessageBox::Rejected){
        _xmlwriter->eraseProject(_projects->at(ui->listWidget->currentRow()).getId());
        _xmlwriter->flush();
        _projects->removeAt(ui->listWidget->currentRow());
    }
    updateProjectsList();
}

void MainWindow::showRenamingForm()
{
    int i=ui->listWidget->currentRow();
    QInputDialog *dlg=new QInputDialog();
    dlg->setTextValue((*_projects)[i].getName());
    dlg->setWindowTitle("Переименование");
    dlg->setLabelText("Введите новое название проекта");
    if(dlg->exec()==QInputDialog::Accepted) (*_projects)[i].setName(dlg->textValue());
    _xmlwriter->renameProject((*_projects)[i].getId(),(*_projects)[i].getName());
    _xmlwriter->flush();
    updateProjectsList();
}

void MainWindow::showVersionList()
{
    int i=ui->listWidget->currentRow();
    versionListForm=new VersionListForm((*_projects)[i],_storagePath,_xmlwriter);
    versionListForm->setProjectPath(i+1);
    versionListForm->show();
    versionListForm->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::showProjectCreatingForm()
{
    prjCreatingForm=new ProjectCreatingForm(_projects,storagePath);
    prjCreatingForm->show();
    prjCreatingForm->exec();
    qDebug()<<_projects->last().getName()<<_projects->last().getOriginPath();
    _xmlwriter->appendProject(_projects->last());
    _xmlwriter->flush();
    prjCreatingForm->setAttribute(Qt::WA_DeleteOnClose);
    updateProjectsList();
}

void MainWindow::updateProjectsList()
{
    ui->listWidget->clear();
    QStringList slist;
    for(auto it:*_projects) slist.append(it.getName());
    ui->listWidget->addItems(slist);
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
}

QString MainWindow::readIni()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    QString path=settings.value("DataStorage/Path","empty").toString();
    if(path=="empty") {
        path=createIni();
    }
    path+="/";
    return path;
}

QString MainWindow::createIni()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    QString dirpath = QFileDialog::getExistingDirectory(this, tr("Выберите папку в которой создастся хранилище"),"/home",
                                                    QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    QDir dir;
    dir.cd(dirpath);
    dir.mkdir("OvertureStorage");
    dir.cd("OvertureStorage");
    dirpath=dir.path();
    settings.setValue("DataStorage/Path",dirpath);
    _xmlwriter->createFile(dirpath+"/data.xml");
    return dirpath;
}

void MainWindow::closeEvent(QCloseEvent * ev)
{
    QMessageBox * exitConfirming=new QMessageBox();
    ev->ignore();
    exitConfirming->addButton("Да",QMessageBox::YesRole);
    exitConfirming->addButton("Нет",QMessageBox::NoRole);
    exitConfirming->setText("Вы уверены, что хотите выйти?");
    exitConfirming->setWindowTitle("Подтверждение закрытия");
    exitConfirming->setIcon(QMessageBox::Question);
    exitConfirming->setDefaultButton(QMessageBox::Yes);
    if (exitConfirming->exec()==QMessageBox::Rejected )
        {
            _xmlwriter->flush();
            ev->accept();
        }
    delete exitConfirming;
}


