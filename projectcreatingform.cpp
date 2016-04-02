#include "projectcreatingform.h"
#include "ui_projectcreatingform.h"
#include <qdebug.h>

ProjectCreatingForm::ProjectCreatingForm(QVector<Project> *projects, QString &storagePath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectCreatingForm)
{
    ui->setupUi(this);
    _projects=projects;
    _storagePath=storagePath;
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(addProject()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(choosePath()));
}

ProjectCreatingForm::~ProjectCreatingForm()
{
    delete ui;
}

void ProjectCreatingForm::addProject()
{
    if(ui->lineEdit_3->text()!=""){
        if(ui->lineEdit->text()!=""){
            QDirIterator iter(ui->lineEdit_3->text(), QDirIterator::Subdirectories);
            QVector<Element> elements;
            while (iter.hasNext()) {
                iter.next();
                 if (iter.fileInfo().baseName() != "") {
                    Element element=_getElementWithAttributes( iter);
                    elements.append(element);
                 }
            }
            Version firstVersion(1, "Version 1",elements);
            QVector<Version> versions;
            versions.append(firstVersion);
            if(!_projects->isEmpty()){
                Project prj(_projects->last().getId()+1,1,ui->lineEdit->text(),_newProjectPath,versions);
                _projects->append(prj);
            } else{
                Project prj(1,1,ui->lineEdit->text(),_newProjectPath,versions);
                _projects->append(prj);
            }
        }
        else {
            this->setAttribute(Qt::WA_AcceptDrops);
            QMessageBox::critical(0,"Ошибка","Выберите имя нового проекта",QMessageBox::Ok);
            show();
            return;
        }
    }
    else {
        QMessageBox::critical(0,"Ошибка","Выберите путь к новому проекту",QMessageBox::Ok);
        show();
        return;
    }
    close();
}

void ProjectCreatingForm::choosePath()
{
    _newProjectPath=QFileDialog::getExistingDirectory(this, tr("Выберите папку для которой будет осуществляться контроль версий"),"/home",
                                                      QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    ui->lineEdit_3->setText(_newProjectPath);
}

Element ProjectCreatingForm::_getElementWithAttributes( const QDirIterator &source)
{
    QString path=source.fileInfo().absolutePath().remove(_newProjectPath) + "/"+source.fileName();
    Element elem(path,0,0);
    if (source.fileInfo().isDir()) {
            elem.setType(1);
        } else {
            elem.setType(0);
        }
    return elem;
}
