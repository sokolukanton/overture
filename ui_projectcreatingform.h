/********************************************************************************
** Form generated from reading UI file 'projectcreatingform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTCREATINGFORM_H
#define UI_PROJECTCREATINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ProjectCreatingForm
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ProjectCreatingForm)
    {
        if (ProjectCreatingForm->objectName().isEmpty())
            ProjectCreatingForm->setObjectName(QStringLiteral("ProjectCreatingForm"));
        ProjectCreatingForm->setWindowModality(Qt::ApplicationModal);
        ProjectCreatingForm->resize(298, 143);
        gridLayout_2 = new QGridLayout(ProjectCreatingForm);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ProjectCreatingForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(ProjectCreatingForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        label_3 = new QLabel(ProjectCreatingForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_3 = new QLineEdit(ProjectCreatingForm);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);

        pushButton = new QPushButton(ProjectCreatingForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(ProjectCreatingForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(ProjectCreatingForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 2);


        retranslateUi(ProjectCreatingForm);
        QObject::connect(pushButton_2, SIGNAL(clicked()), ProjectCreatingForm, SLOT(close()));

        QMetaObject::connectSlotsByName(ProjectCreatingForm);
    } // setupUi

    void retranslateUi(QDialog *ProjectCreatingForm)
    {
        ProjectCreatingForm->setWindowTitle(QApplication::translate("ProjectCreatingForm", "\320\235\320\276\320\262\321\213\320\271 \320\277\321\200\320\276\320\265\320\272\321\202", 0));
        label->setText(QApplication::translate("ProjectCreatingForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", 0));
        label_3->setText(QApplication::translate("ProjectCreatingForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \320\277\320\260\320\277\320\272\320\265 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", 0));
        pushButton->setText(QApplication::translate("ProjectCreatingForm", "\320\236\320\261\320\267\320\276\321\200", 0));
        pushButton_3->setText(QApplication::translate("ProjectCreatingForm", "\320\236\320\232", 0));
        pushButton_2->setText(QApplication::translate("ProjectCreatingForm", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjectCreatingForm: public Ui_ProjectCreatingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTCREATINGFORM_H
