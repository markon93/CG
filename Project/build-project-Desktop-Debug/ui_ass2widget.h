/********************************************************************************
** Form generated from reading UI file 'ass2widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASS2WIDGET_H
#define UI_ASS2WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ass2Widget
{
public:
    QGroupBox *group_projection;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QRadioButton *btn_perspective;
    QLabel *label_5;
    QSpinBox *spin_fov;
    QLabel *label_6;
    QSpinBox *spin_pefar;
    QRadioButton *btn_parallel;
    QLabel *label;
    QDoubleSpinBox *spin_top;
    QLabel *label_2;
    QSpinBox *spin_plfar;
    QLabel *label_3;
    QDoubleSpinBox *spin_oblscale;
    QLabel *label_4;
    QDoubleSpinBox *spin_oblangle;
    QSpacerItem *verticalSpacer;
    QLabel *label_obj_filename;
    QPushButton *push_file;
    QLabel *label_file;

    void setupUi(QWidget *Ass2Widget)
    {
        if (Ass2Widget->objectName().isEmpty())
            Ass2Widget->setObjectName(QStringLiteral("Ass2Widget"));
        Ass2Widget->resize(309, 322);
        group_projection = new QGroupBox(Ass2Widget);
        group_projection->setObjectName(QStringLiteral("group_projection"));
        group_projection->setGeometry(QRect(10, 60, 201, 251));
        layoutWidget = new QWidget(group_projection);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 21, 178, 224));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(17);
        formLayout->setVerticalSpacing(4);
        formLayout->setContentsMargins(2, 0, 0, 0);
        btn_perspective = new QRadioButton(layoutWidget);
        btn_perspective->setObjectName(QStringLiteral("btn_perspective"));
        btn_perspective->setChecked(true);

        formLayout->setWidget(0, QFormLayout::SpanningRole, btn_perspective);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        spin_fov = new QSpinBox(layoutWidget);
        spin_fov->setObjectName(QStringLiteral("spin_fov"));
        spin_fov->setEnabled(true);
        spin_fov->setMinimum(20);
        spin_fov->setMaximum(160);
        spin_fov->setValue(60);

        formLayout->setWidget(1, QFormLayout::FieldRole, spin_fov);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        spin_pefar = new QSpinBox(layoutWidget);
        spin_pefar->setObjectName(QStringLiteral("spin_pefar"));
        spin_pefar->setEnabled(true);
        spin_pefar->setMinimum(1);
        spin_pefar->setMaximum(10000);
        spin_pefar->setSingleStep(10);
        spin_pefar->setValue(500);

        formLayout->setWidget(2, QFormLayout::FieldRole, spin_pefar);

        btn_parallel = new QRadioButton(layoutWidget);
        btn_parallel->setObjectName(QStringLiteral("btn_parallel"));
        btn_parallel->setChecked(false);

        formLayout->setWidget(7, QFormLayout::LabelRole, btn_parallel);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(8, QFormLayout::LabelRole, label);

        spin_top = new QDoubleSpinBox(layoutWidget);
        spin_top->setObjectName(QStringLiteral("spin_top"));
        spin_top->setEnabled(false);
        spin_top->setAutoFillBackground(true);
        spin_top->setDecimals(1);
        spin_top->setMinimum(1);
        spin_top->setSingleStep(0.5);
        spin_top->setValue(1);

        formLayout->setWidget(8, QFormLayout::FieldRole, spin_top);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_2);

        spin_plfar = new QSpinBox(layoutWidget);
        spin_plfar->setObjectName(QStringLiteral("spin_plfar"));
        spin_plfar->setEnabled(false);
        spin_plfar->setMinimum(1);
        spin_plfar->setMaximum(10000);
        spin_plfar->setSingleStep(10);
        spin_plfar->setValue(500);

        formLayout->setWidget(9, QFormLayout::FieldRole, spin_plfar);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_3);

        spin_oblscale = new QDoubleSpinBox(layoutWidget);
        spin_oblscale->setObjectName(QStringLiteral("spin_oblscale"));
        spin_oblscale->setEnabled(false);
        spin_oblscale->setAutoFillBackground(true);
        spin_oblscale->setMaximum(1);
        spin_oblscale->setSingleStep(0.25);

        formLayout->setWidget(10, QFormLayout::FieldRole, spin_oblscale);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_4);

        spin_oblangle = new QDoubleSpinBox(layoutWidget);
        spin_oblangle->setObjectName(QStringLiteral("spin_oblangle"));
        spin_oblangle->setEnabled(false);
        spin_oblangle->setMinimum(15);
        spin_oblangle->setMaximum(75);
        spin_oblangle->setSingleStep(15);
        spin_oblangle->setValue(45);

        formLayout->setWidget(11, QFormLayout::FieldRole, spin_oblangle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::LabelRole, verticalSpacer);

        label_obj_filename = new QLabel(Ass2Widget);
        label_obj_filename->setObjectName(QStringLiteral("label_obj_filename"));
        label_obj_filename->setGeometry(QRect(20, 30, 241, 20));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_obj_filename->sizePolicy().hasHeightForWidth());
        label_obj_filename->setSizePolicy(sizePolicy);
        label_obj_filename->setFocusPolicy(Qt::ClickFocus);
        label_obj_filename->setAutoFillBackground(true);
        label_obj_filename->setFrameShape(QFrame::Panel);
        label_obj_filename->setFrameShadow(QFrame::Sunken);
        label_obj_filename->setLineWidth(1);
        label_obj_filename->setScaledContents(false);
        label_obj_filename->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        push_file = new QPushButton(Ass2Widget);
        push_file->setObjectName(QStringLiteral("push_file"));
        push_file->setGeometry(QRect(270, 30, 31, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(push_file->sizePolicy().hasHeightForWidth());
        push_file->setSizePolicy(sizePolicy1);
        label_file = new QLabel(Ass2Widget);
        label_file->setObjectName(QStringLiteral("label_file"));
        label_file->setGeometry(QRect(10, 10, 61, 15));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_file->setFont(font);
        QWidget::setTabOrder(push_file, spin_top);
        QWidget::setTabOrder(spin_top, spin_plfar);
        QWidget::setTabOrder(spin_plfar, spin_oblscale);
        QWidget::setTabOrder(spin_oblscale, spin_oblangle);

        retranslateUi(Ass2Widget);
        QObject::connect(btn_parallel, SIGNAL(toggled(bool)), spin_top, SLOT(setEnabled(bool)));
        QObject::connect(btn_parallel, SIGNAL(toggled(bool)), spin_plfar, SLOT(setEnabled(bool)));
        QObject::connect(btn_parallel, SIGNAL(toggled(bool)), spin_oblscale, SLOT(setEnabled(bool)));
        QObject::connect(btn_parallel, SIGNAL(toggled(bool)), spin_oblangle, SLOT(setEnabled(bool)));
        QObject::connect(btn_perspective, SIGNAL(toggled(bool)), spin_fov, SLOT(setEnabled(bool)));
        QObject::connect(btn_perspective, SIGNAL(toggled(bool)), spin_pefar, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Ass2Widget);
    } // setupUi

    void retranslateUi(QWidget *Ass2Widget)
    {
        Ass2Widget->setWindowTitle(QApplication::translate("Ass2Widget", "3D Studio", Q_NULLPTR));
        group_projection->setTitle(QApplication::translate("Ass2Widget", "Projection", Q_NULLPTR));
        btn_perspective->setText(QApplication::translate("Ass2Widget", "Perspecti&ve", Q_NULLPTR));
        label_5->setText(QApplication::translate("Ass2Widget", "Field of view", Q_NULLPTR));
        label_6->setText(QApplication::translate("Ass2Widget", "Far", Q_NULLPTR));
        btn_parallel->setText(QApplication::translate("Ass2Widget", "Para&llel", Q_NULLPTR));
        label->setText(QApplication::translate("Ass2Widget", "Top", Q_NULLPTR));
        label_2->setText(QApplication::translate("Ass2Widget", "Far", Q_NULLPTR));
        label_3->setText(QApplication::translate("Ass2Widget", "Oblique scale", Q_NULLPTR));
        label_4->setText(QApplication::translate("Ass2Widget", "Oblique angle", Q_NULLPTR));
        label_obj_filename->setText(QApplication::translate("Ass2Widget", "(none)", Q_NULLPTR));
        push_file->setText(QApplication::translate("Ass2Widget", "...", Q_NULLPTR));
        label_file->setText(QApplication::translate("Ass2Widget", "OBJ File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Ass2Widget: public Ui_Ass2Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASS2WIDGET_H
