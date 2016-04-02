#ifndef VERSIONCREATINGFORM_H
#define VERSIONCREATINGFORM_H

#include <QDialog>
#include <Project.h>
#include "QFileSystemModel"
#include <QModelIndex>


namespace Ui {
class VersionCreatingForm;
}

class VersionCreatingForm : public QDialog
{
    Q_OBJECT

public:
    explicit VersionCreatingForm(const QString &, QWidget *parent = 0);
    ~VersionCreatingForm();

private:
    Ui::VersionCreatingForm *ui;
    QFileSystemModel* fsModel;
    QModelIndex* mdIndex;

};

#endif // VERSIONCREATINGFORM_H
