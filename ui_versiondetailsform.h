/********************************************************************************
** Form generated from reading UI file 'versiondetailsform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONDETAILSFORM_H
#define UI_VERSIONDETAILSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_VersionDetailsForm
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QTreeView *treeView;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *VersionDetailsForm)
    {
        if (VersionDetailsForm->objectName().isEmpty())
            VersionDetailsForm->setObjectName(QStringLiteral("VersionDetailsForm"));
        VersionDetailsForm->setWindowModality(Qt::ApplicationModal);
        VersionDetailsForm->resize(613, 428);
        gridLayout = new QGridLayout(VersionDetailsForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(VersionDetailsForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton = new QRadioButton(VersionDetailsForm);
        buttonGroup = new QButtonGroup(VersionDetailsForm);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(VersionDetailsForm);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout_2->addWidget(radioButton_2, 0, 1, 1, 1);

        treeView = new QTreeView(VersionDetailsForm);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout_2->addWidget(treeView, 1, 0, 1, 2);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 2);


        retranslateUi(VersionDetailsForm);
        QObject::connect(pushButton, SIGNAL(clicked()), VersionDetailsForm, SLOT(close()));

        QMetaObject::connectSlotsByName(VersionDetailsForm);
    } // setupUi

    void retranslateUi(QDialog *VersionDetailsForm)
    {
        VersionDetailsForm->setWindowTitle(QApplication::translate("VersionDetailsForm", "\320\244\320\260\320\271\320\273\321\213 \320\262\320\265\321\200\321\201\320\270\320\270", 0));
        pushButton->setText(QApplication::translate("VersionDetailsForm", "\320\235\320\260\320\267\320\260\320\264", 0));
        radioButton->setText(QApplication::translate("VersionDetailsForm", "\320\244\320\260\320\271\320\273\321\213 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\201\320\270\320\265\320\271", 0));
        radioButton_2->setText(QApplication::translate("VersionDetailsForm", "\320\244\320\260\320\271\320\273\321\213 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\275\320\275\321\213\320\265 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\271 \320\262\320\265\321\200\321\201\320\270\320\265\320\271", 0));
    } // retranslateUi

};

namespace Ui {
    class VersionDetailsForm: public Ui_VersionDetailsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONDETAILSFORM_H
