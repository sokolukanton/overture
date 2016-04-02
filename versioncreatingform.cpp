#include "versioncreatingform.h"
#include "ui_versioncreatingform.h"

VersionCreatingForm::VersionCreatingForm(QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::VersionCreatingForm)
{
    ui->setupUi(this);
}

VersionCreatingForm::~VersionCreatingForm()
{
    delete ui;
}
