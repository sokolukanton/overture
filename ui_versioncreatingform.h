/********************************************************************************
** Form generated from reading UI file 'versioncreatingform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONCREATINGFORM_H
#define UI_VERSIONCREATINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_VersionCreatingForm
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *folderCreateButton;
    QPushButton *deleteButton;
    QPushButton *addButton;
    QSpacerItem *verticalSpacer;
    QTreeView *treeView;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_3;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *VersionCreatingForm)
    {
        if (VersionCreatingForm->objectName().isEmpty())
            VersionCreatingForm->setObjectName(QStringLiteral("VersionCreatingForm"));
        VersionCreatingForm->setWindowModality(Qt::ApplicationModal);
        VersionCreatingForm->resize(577, 409);
        gridLayout_5 = new QGridLayout(VersionCreatingForm);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        folderCreateButton = new QPushButton(VersionCreatingForm);
        folderCreateButton->setObjectName(QStringLiteral("folderCreateButton"));

        gridLayout->addWidget(folderCreateButton, 1, 0, 1, 1);

        deleteButton = new QPushButton(VersionCreatingForm);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setEnabled(false);

        gridLayout->addWidget(deleteButton, 2, 0, 1, 1);

        addButton = new QPushButton(VersionCreatingForm);
        addButton->setObjectName(QStringLiteral("addButton"));

        gridLayout->addWidget(addButton, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        treeView = new QTreeView(VersionCreatingForm);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout_2->addWidget(treeView, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        okButton = new QPushButton(VersionCreatingForm);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_3->addWidget(okButton, 0, 0, 1, 1);

        cancelButton = new QPushButton(VersionCreatingForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_3->addWidget(cancelButton, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);


        retranslateUi(VersionCreatingForm);

        QMetaObject::connectSlotsByName(VersionCreatingForm);
    } // setupUi

    void retranslateUi(QDialog *VersionCreatingForm)
    {
        VersionCreatingForm->setWindowTitle(QApplication::translate("VersionCreatingForm", "\320\235\320\276\320\262\320\260\321\217 \320\262\320\265\321\200\321\201\320\270\321\217", 0));
        folderCreateButton->setText(QApplication::translate("VersionCreatingForm", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\260\320\277\320\272\321\203", 0));
        deleteButton->setText(QApplication::translate("VersionCreatingForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        addButton->setText(QApplication::translate("VersionCreatingForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273\321\213/\320\277\320\260\320\277\320\272\320\270", 0));
        okButton->setText(QApplication::translate("VersionCreatingForm", "\320\236\320\232", 0));
        cancelButton->setText(QApplication::translate("VersionCreatingForm", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class VersionCreatingForm: public Ui_VersionCreatingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONCREATINGFORM_H
