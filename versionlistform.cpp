#include "versionlistform.h"
#include "ui_versionlistform.h"
#include "QDebug"


VersionListForm::VersionListForm(const Project& project, const QString& projectPath, const QString& storagePath, XmlIO* xmlwriter, QWidget *parent) :
    QDialog(parent), ui(new Ui::VersionListForm), _project(project),
    _projectPath(projectPath), _storagePath(storagePath), _xmlwriter(xmlwriter)
{
    ui->setupUi(this);
    this->setWindowTitle(this->windowTitle()+" "+_project.getName());

    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(showVersionDetailsForm()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(moveConfirm()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(deleteConfirm()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(showRenamingForm()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showVersionCreatingForm()));

    updateVersionsList();
}

VersionListForm::~VersionListForm()
{
    delete ui;
}

void VersionListForm::showVersionDetailsForm()
{
    int i = ui->listWidget->currentRow();
    versionDetailsForm=new VersionDetailsForm(_project.getVersions()[i],_storagePath+_projectPath, i + 1);
    versionDetailsForm->show();
    versionDetailsForm->setAttribute(Qt::WA_DeleteOnClose);
}

void VersionListForm::showVersionCreatingForm()
{
    versionCreatingForm = new VersionCreatingForm(_projectPath);
    versionCreatingForm->show();
    versionCreatingForm->setAttribute(Qt::WA_DeleteOnClose);
}

void VersionListForm::showRenamingForm()
{
    int i=ui->listWidget->currentRow();
    QInputDialog *dlg=new QInputDialog();
    dlg->setTextValue(_project.getVersions()[i].getName());
    dlg->setWindowTitle("Переименование");
    dlg->setLabelText("Введите новое название проекта");
    if(dlg->exec()==QInputDialog::Accepted) _project.renameVersion(i,dlg->textValue());
    _xmlwriter->renameVersion(_project.getId(),_project.getVersions()[i].getId(),dlg->textValue());
    _xmlwriter->flush();
    updateVersionsList();
}

void VersionListForm::deleteConfirm()
{
    deleteConfirming=new QMessageBox();
    deleteConfirming->addButton("Да",QMessageBox::YesRole);
    deleteConfirming->addButton("Нет",QMessageBox::NoRole);
    deleteConfirming->setText("Вы уверены ,что хотите удалить эту версию? Вы уже не сможете восстановить ее файлы");
    deleteConfirming->setWindowTitle("Подтверждение удаления");
    deleteConfirming->setIcon(QMessageBox::Question);
    deleteConfirming->show();
    if(deleteConfirming->exec()==QMessageBox::Rejected){
        _xmlwriter->eraseVersion(_project.getId(),
                                 _project.getVersions().at(ui->listWidget->currentRow()).getId());
        _xmlwriter->flush();
        _project.deleteVersion(ui->listWidget->currentRow());
        _project.setCurrentVersion(_project.getVersions().last().getId());
    }
    deleteConfirming->setAttribute(Qt::WA_DeleteOnClose);
    updateVersionsList();
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

    QString prjNum=_projectPath.at(_projectPath.length()-2);
    if (moveConfirming->exec()==QMessageBox::Rejected) {
        int cid = _project.getCurrentVersionId();
        int nid = _project.getVersions()[ui->listWidget->currentRow()].getId();
        if(nid==cid) {
            return;
        } else if (nid>cid) {
            _project.jumpToVersion(nid,prjNum,_storagePath);
        } else {
             _project.rollbackToversion(nid,prjNum,_storagePath);
        }
    }
    _xmlwriter->setCurrentVersion(_project.getId(),_project.getCurrentVersionId());
    _xmlwriter->flush();
}

void VersionListForm::updateVersionsList()
{
    ui->listWidget->clear();
    QStringList slist;
    for(auto it:_project.getVersions())
        slist.append(it.getName());
    ui->listWidget->addItems(slist);

    int cid=_project.getCurrentVersionId();
    int versionNumber = _project.getVersions().length();

    for (int i = 0; i < versionNumber; i++) {
        if (_project.getVersions()[i].getId() == cid) {
            ui->listWidget->setCurrentRow(i);
            break;
        }
    }
}
