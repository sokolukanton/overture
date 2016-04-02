#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmessagebox.h>
#include "versionlistform.h"
#include "projectcreatingform.h"
#include <QCloseEvent>
#include "Project.h"
#include <qstringlist.h>
#include <QSettings>
#include <QTextCodec>
#include <qdebug.h>
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
    void updateProjectsList();
    QString readIni();
    QString createIni();
    Ui::MainWindow * ui;
    QString storagePath;
    QMessageBox * deleteConfirming;
    VersionListForm * versionListForm;
    ProjectCreatingForm * prjCreatingForm;
    QVector <Project> * _projects;
    XmlIO * _xmlwriter;
    QString _storagePath;
};

#endif // MAINWINDOW_H
