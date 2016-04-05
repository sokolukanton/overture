#include "addnewfolderform.h"
#include "ui_addnewfolderform.h"

AddNewFolderForm::AddNewFolderForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewFolderForm)
{
    ui->setupUi(this);

    ui->lineEdit->setFocus();
}

AddNewFolderForm::~AddNewFolderForm()
{
    delete ui;
}

void AddNewFolderForm::on_lineEdit_textChanged(const QString &folderName)
{
    if (folderName == "") {
        ui->okButton->setEnabled(false);
    } else {
        ui->okButton->setEnabled(true);
    }
}

void AddNewFolderForm::on_okButton_clicked()
{
    emit sendNewFolderName(ui->lineEdit->text());
    close();
    delete this;
}
