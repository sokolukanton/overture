/********************************************************************************
** Form generated from reading UI file 'versionlistform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONLISTFORM_H
#define UI_VERSIONLISTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_VersionListForm
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QListWidget *listWidget;

    void setupUi(QDialog *VersionListForm)
    {
        if (VersionListForm->objectName().isEmpty())
            VersionListForm->setObjectName(QStringLiteral("VersionListForm"));
        VersionListForm->setWindowModality(Qt::ApplicationModal);
        VersionListForm->resize(537, 478);
        gridLayout_2 = new QGridLayout(VersionListForm);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(VersionListForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(VersionListForm);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(VersionListForm);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 6, 0, 1, 1);

        pushButton = new QPushButton(VersionListForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font;
        font.setKerning(true);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(VersionListForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton_6 = new QPushButton(VersionListForm);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        listWidget = new QListWidget(VersionListForm);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);


        retranslateUi(VersionListForm);
        QObject::connect(pushButton_5, SIGNAL(clicked()), VersionListForm, SLOT(close()));

        QMetaObject::connectSlotsByName(VersionListForm);
    } // setupUi

    void retranslateUi(QDialog *VersionListForm)
    {
        VersionListForm->setWindowTitle(QApplication::translate("VersionListForm", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\262\320\265\321\200\321\201\320\270\320\271 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("VersionListForm", "<html><head/><body><p>\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\262\320\265\321\200\321\201\320\270\320\270</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("VersionListForm", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 ", 0));
        pushButton_4->setText(QApplication::translate("VersionListForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 ", 0));
        pushButton_5->setText(QApplication::translate("VersionListForm", "\320\235\320\260\320\267\320\260\320\264", 0));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("VersionListForm", "<html><head/><body><p>\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\262\320\265\321\200\321\201\320\270\321\216</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("VersionListForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("VersionListForm", "<html><head/><body><p>\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\262 \320\275\320\276\320\262\320\276\320\274 \320\276\320\272\320\275\320\265 \321\201\320\277\320\270\321\201\320\276\320\272 \321\204\320\260\320\271\320\273\320\276\320\262,\320\272\320\276\321\202\320\276\321\200\321\213\320\265 \320\270\320\267\320\274\320\265\320\275\320\270\320\273\320\260 \320\270\320\273\320\270 \321\203\320\264\320\260\320\273\320\270\320\273\320\260 \321\215\321\202\320\260 \320\262\320\265\321\200\321\201\320\270\321\217</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("VersionListForm", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\204\320\260\320\271\320\273\320\276\320\262 ", 0));
        pushButton_6->setText(QApplication::translate("VersionListForm", "\320\237\320\265\321\200\320\265\320\270\320\274\320\265\320\275\320\276\320\262\320\260\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class VersionListForm: public Ui_VersionListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONLISTFORM_H
