#include "projectcreatingform.h"
#include "ui_projectcreatingform.h"

ProjectCreatingForm::ProjectCreatingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectCreatingForm)
{
    ui->setupUi(this);
}

ProjectCreatingForm::~ProjectCreatingForm()
{
    delete ui;
}
