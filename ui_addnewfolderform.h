/********************************************************************************
** Form generated from reading UI file 'addnewfolderform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWFOLDERFORM_H
#define UI_ADDNEWFOLDERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewFolderForm
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *AddNewFolderForm)
    {
        if (AddNewFolderForm->objectName().isEmpty())
            AddNewFolderForm->setObjectName(QStringLiteral("AddNewFolderForm"));
        AddNewFolderForm->resize(312, 126);
        gridLayout_3 = new QGridLayout(AddNewFolderForm);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        okButton = new QPushButton(AddNewFolderForm);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setEnabled(false);

        gridLayout->addWidget(okButton, 0, 0, 1, 1);

        cancelButton = new QPushButton(AddNewFolderForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout->addWidget(cancelButton, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(AddNewFolderForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(AddNewFolderForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 2);


        retranslateUi(AddNewFolderForm);
        QObject::connect(cancelButton, SIGNAL(clicked()), AddNewFolderForm, SLOT(close()));

        QMetaObject::connectSlotsByName(AddNewFolderForm);
    } // setupUi

    void retranslateUi(QWidget *AddNewFolderForm)
    {
        AddNewFolderForm->setWindowTitle(QApplication::translate("AddNewFolderForm", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\320\260\320\277\320\272\320\270", 0));
        okButton->setText(QApplication::translate("AddNewFolderForm", "\320\236\320\232", 0));
        cancelButton->setText(QApplication::translate("AddNewFolderForm", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        label->setText(QApplication::translate("AddNewFolderForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265, \320\277\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260, \320\270\320\274\321\217 \320\277\320\260\320\277\320\272\320\270:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddNewFolderForm: public Ui_AddNewFolderForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWFOLDERFORM_H
