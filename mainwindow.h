#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmessagebox.h>
#include "versionlistform.h"
#include "projectcreatingform.h"
#include <QCloseEvent>
#include <QVector>
#include <xmldata.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void deleteConfirm();
    void showRenamingForm();
    void showVersionList();
    void showProjectCreatingForm();
    void updateProjectsList();
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow * ui;
    QMessageBox * deleteConfirming;
    VersionListForm * versionListForm;
    ProjectCreatingForm * prjCreatingForm;
    QVector <Project> * _projects;
    XmlData * _xmlreader;
};

#endif // MAINWINDOW_H
