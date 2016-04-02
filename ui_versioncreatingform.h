/********************************************************************************
** Form generated from reading UI file 'versioncreatingform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_VersionCreatingForm
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QTreeView *treeView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VersionCreatingForm)
    {
        if (VersionCreatingForm->objectName().isEmpty())
            VersionCreatingForm->setObjectName(QStringLiteral("VersionCreatingForm"));
        VersionCreatingForm->setWindowModality(Qt::ApplicationModal);
        VersionCreatingForm->resize(577, 409);
        gridLayout_3 = new QGridLayout(VersionCreatingForm);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(VersionCreatingForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(VersionCreatingForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(VersionCreatingForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        treeView = new QTreeView(VersionCreatingForm);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout_2->addWidget(treeView, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(VersionCreatingForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(VersionCreatingForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), VersionCreatingForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VersionCreatingForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(VersionCreatingForm);
    } // setupUi

    void retranslateUi(QDialog *VersionCreatingForm)
    {
        VersionCreatingForm->setWindowTitle(QApplication::translate("VersionCreatingForm", "\320\235\320\276\320\262\320\260\321\217 \320\262\320\265\321\200\321\201\320\270\321\217", 0));
        pushButton->setText(QApplication::translate("VersionCreatingForm", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\260\320\277\320\272\321\203", 0));
        pushButton_2->setText(QApplication::translate("VersionCreatingForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("VersionCreatingForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273\321\213/\320\277\320\260\320\277\320\272\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class VersionCreatingForm: public Ui_VersionCreatingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONCREATINGFORM_H
