#ifndef PROJECTCREATINGFORM_H
#define PROJECTCREATINGFORM_H

#include <QDialog>

namespace Ui {
class ProjectCreatingForm;
}

class ProjectCreatingForm : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectCreatingForm(QWidget *parent = 0);
    ~ProjectCreatingForm();

private:
    Ui::ProjectCreatingForm *ui;
};

#endif // PROJECTCREATINGFORM_H
