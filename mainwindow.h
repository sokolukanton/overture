#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmessagebox.h>
#include "versionlistform.h"
#include "projectcreatingform.h"
#include <QCloseEvent>
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
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow * ui;
    QMessageBox * deleteConfirming;
    VersionListForm * versionListForm;
    ProjectCreatingForm * prjCreatingForm;
};

#endif // MAINWINDOW_H
