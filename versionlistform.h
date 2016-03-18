#ifndef VERSIONLISTFORM_H
#define VERSIONLISTFORM_H

#include <QDialog>
#include "versiondetailsform.h"
#include <qmessagebox.h>
#include "versioncreatingform.h"

namespace Ui {
class VersionListForm;
}

class VersionListForm : public QDialog
{
    Q_OBJECT

public:
    explicit VersionListForm(QString projectName,QWidget *parent = 0);//Или будем не имя проекта передавать?
    ~VersionListForm();
private slots:
    void showVersionDetailsForm();
    void showVersionCreatingForm();
    void deleteConfirm();
    void moveConfirm();

private:
    Ui::VersionListForm *ui;
    VersionDetailsForm * versionDetailsForm;
    QMessageBox * deleteConfirming;
    QMessageBox * moveConfirming;
    VersionCreatingForm * versionCreatingForm;
};

#endif // VERSIONLISTFORM_H
