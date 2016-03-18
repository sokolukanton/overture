#ifndef VERSIONDETAILSFORM_H
#define VERSIONDETAILSFORM_H

#include <QDialog>

namespace Ui {
class VersionDetailsForm;
}

class VersionDetailsForm : public QDialog
{
    Q_OBJECT

public:
    explicit VersionDetailsForm(QWidget *parent = 0);
    ~VersionDetailsForm();

private:
    Ui::VersionDetailsForm *ui;
};

#endif // VERSIONDETAILSFORM_H
