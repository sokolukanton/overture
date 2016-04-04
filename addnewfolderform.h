#ifndef ADDNEWFOLDERFORM_H
#define ADDNEWFOLDERFORM_H

#include <QDialog>

namespace Ui {
class AddNewFolderForm;
}

class AddNewFolderForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewFolderForm(QWidget *parent = 0);
    ~AddNewFolderForm();

signals:
    void sendNewFolderName(const QString &);

private slots:
    void on_lineEdit_textChanged(const QString &);
    void on_okButton_clicked();

private:
    Ui::AddNewFolderForm *ui;
};

#endif // ADDNEWFOLDERFORM_H
