#ifndef VERSIONCREATINGFORM_H
#define VERSIONCREATINGFORM_H

#include <QDialog>
#include <Project.h>

namespace Ui {
class VersionCreatingForm;
}

class VersionCreatingForm : public QDialog
{
    Q_OBJECT

public:
    explicit VersionCreatingForm( QWidget *parent = 0);
    ~VersionCreatingForm();

private:
    Ui::VersionCreatingForm *ui;

};

#endif // VERSIONCREATINGFORM_H
