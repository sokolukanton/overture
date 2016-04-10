#ifndef PROJECTCREATINGFORM_H
#define PROJECTCREATINGFORM_H

#include <QDialog>
#include <Project.h>
#include <QDirIterator>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
    class ProjectCreatingForm;
}

class ProjectCreatingForm : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectCreatingForm(QVector<Project> *projects, QString& storagePath,QWidget *parent = 0);
    ~ProjectCreatingForm();

private slots:
    void addProject();
    void choosePath();
    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    Ui::ProjectCreatingForm *ui;
    QVector<Project> *_projects;
    QString _newProjectPath;
    QString _storagePath;

    Element _getElementWithAttributes(const QDirIterator &);
    void _createProjectFolder(const QString &, const QString &);
};

#endif // PROJECTCREATINGFORM_H
