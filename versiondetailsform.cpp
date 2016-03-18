#include "versiondetailsform.h"
#include "ui_versiondetailsform.h"

VersionDetailsForm::VersionDetailsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionDetailsForm)
{
    ui->setupUi(this);
}

VersionDetailsForm::~VersionDetailsForm()
{
    delete ui;
}
