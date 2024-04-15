/********************************************************************************
** Form generated from reading UI file 'WaypointNavigation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAYPOINTNAVIGATION_H
#define UI_WAYPOINTNAVIGATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaypointNavigationWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_topic;
    QLineEdit *topic_line_edit;
    QLabel *label_frame;
    QLineEdit *frame_line_edit;
    QCheckBox *sixDcheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *wp_height_label;
    QDoubleSpinBox *wp_height_doubleSpinBox;
    QLabel *waypoint_count_label;
    QLabel *sel_label;
    QLabel *sel_wp_label;
    QPushButton *load_wp_button;
    QHBoxLayout *horizontalLayout;
    QLabel *x_label;
    QDoubleSpinBox *x_doubleSpinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *y_label;
    QDoubleSpinBox *y_doubleSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *z_label;
    QDoubleSpinBox *z_doubleSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *yaw_label;
    QDoubleSpinBox *yaw_doubleSpinBox;
    QPushButton *clear_all_button;
    QPushButton *save_wp_button;
    QPushButton *publish_wp_button;

    void setupUi(QWidget *WaypointNavigationWidget)
    {
        if (WaypointNavigationWidget->objectName().isEmpty())
            WaypointNavigationWidget->setObjectName(QStringLiteral("WaypointNavigationWidget"));
        WaypointNavigationWidget->resize(469, 175);
        gridLayout = new QGridLayout(WaypointNavigationWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_topic = new QLabel(WaypointNavigationWidget);
        label_topic->setObjectName(QStringLiteral("label_topic"));

        horizontalLayout_3->addWidget(label_topic);

        topic_line_edit = new QLineEdit(WaypointNavigationWidget);
        topic_line_edit->setObjectName(QStringLiteral("topic_line_edit"));

        horizontalLayout_3->addWidget(topic_line_edit);

        label_frame = new QLabel(WaypointNavigationWidget);
        label_frame->setObjectName(QStringLiteral("label_frame"));

        horizontalLayout_3->addWidget(label_frame);

        frame_line_edit = new QLineEdit(WaypointNavigationWidget);
        frame_line_edit->setObjectName(QStringLiteral("frame_line_edit"));

        horizontalLayout_3->addWidget(frame_line_edit);

        sixDcheckBox = new QCheckBox(WaypointNavigationWidget);
        sixDcheckBox->setObjectName(QStringLiteral("sixDcheckBox"));

        horizontalLayout_3->addWidget(sixDcheckBox);


        gridLayout->addLayout(horizontalLayout_3, 5, 1, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        wp_height_label = new QLabel(WaypointNavigationWidget);
        wp_height_label->setObjectName(QStringLiteral("wp_height_label"));

        horizontalLayout_2->addWidget(wp_height_label);

        wp_height_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        wp_height_doubleSpinBox->setObjectName(QStringLiteral("wp_height_doubleSpinBox"));
        wp_height_doubleSpinBox->setMinimum(-5);
        wp_height_doubleSpinBox->setSingleStep(0.1);

        horizontalLayout_2->addWidget(wp_height_doubleSpinBox);

        waypoint_count_label = new QLabel(WaypointNavigationWidget);
        waypoint_count_label->setObjectName(QStringLiteral("waypoint_count_label"));

        horizontalLayout_2->addWidget(waypoint_count_label);

        sel_label = new QLabel(WaypointNavigationWidget);
        sel_label->setObjectName(QStringLiteral("sel_label"));

        horizontalLayout_2->addWidget(sel_label);

        sel_wp_label = new QLabel(WaypointNavigationWidget);
        sel_wp_label->setObjectName(QStringLiteral("sel_wp_label"));

        horizontalLayout_2->addWidget(sel_wp_label);


        gridLayout->addLayout(horizontalLayout_2, 6, 1, 1, 3);

        load_wp_button = new QPushButton(WaypointNavigationWidget);
        load_wp_button->setObjectName(QStringLiteral("load_wp_button"));

        gridLayout->addWidget(load_wp_button, 10, 2, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        x_label = new QLabel(WaypointNavigationWidget);
        x_label->setObjectName(QStringLiteral("x_label"));

        horizontalLayout->addWidget(x_label);

        x_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        x_doubleSpinBox->setObjectName(QStringLiteral("x_doubleSpinBox"));
        x_doubleSpinBox->setMinimum(-1000);
        x_doubleSpinBox->setMaximum(1000);
        x_doubleSpinBox->setSingleStep(0.5);

        horizontalLayout->addWidget(x_doubleSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        y_label = new QLabel(WaypointNavigationWidget);
        y_label->setObjectName(QStringLiteral("y_label"));

        horizontalLayout->addWidget(y_label);

        y_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        y_doubleSpinBox->setObjectName(QStringLiteral("y_doubleSpinBox"));
        y_doubleSpinBox->setMinimum(-1000);
        y_doubleSpinBox->setMaximum(1000);
        y_doubleSpinBox->setSingleStep(0.5);

        horizontalLayout->addWidget(y_doubleSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        z_label = new QLabel(WaypointNavigationWidget);
        z_label->setObjectName(QStringLiteral("z_label"));

        horizontalLayout->addWidget(z_label);

        z_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        z_doubleSpinBox->setObjectName(QStringLiteral("z_doubleSpinBox"));
        z_doubleSpinBox->setMinimum(-1000);
        z_doubleSpinBox->setMaximum(1000);
        z_doubleSpinBox->setSingleStep(0.5);

        horizontalLayout->addWidget(z_doubleSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        yaw_label = new QLabel(WaypointNavigationWidget);
        yaw_label->setObjectName(QStringLiteral("yaw_label"));

        horizontalLayout->addWidget(yaw_label);

        yaw_doubleSpinBox = new QDoubleSpinBox(WaypointNavigationWidget);
        yaw_doubleSpinBox->setObjectName(QStringLiteral("yaw_doubleSpinBox"));
        yaw_doubleSpinBox->setMinimum(-3.15);
        yaw_doubleSpinBox->setMaximum(3.15);
        yaw_doubleSpinBox->setSingleStep(0.1);

        horizontalLayout->addWidget(yaw_doubleSpinBox);


        gridLayout->addLayout(horizontalLayout, 8, 1, 1, 3);

        clear_all_button = new QPushButton(WaypointNavigationWidget);
        clear_all_button->setObjectName(QStringLiteral("clear_all_button"));

        gridLayout->addWidget(clear_all_button, 9, 1, 1, 1);

        save_wp_button = new QPushButton(WaypointNavigationWidget);
        save_wp_button->setObjectName(QStringLiteral("save_wp_button"));

        gridLayout->addWidget(save_wp_button, 10, 1, 1, 1);

        publish_wp_button = new QPushButton(WaypointNavigationWidget);
        publish_wp_button->setObjectName(QStringLiteral("publish_wp_button"));

        gridLayout->addWidget(publish_wp_button, 9, 2, 1, 2);


        retranslateUi(WaypointNavigationWidget);

        QMetaObject::connectSlotsByName(WaypointNavigationWidget);
    } // setupUi

    void retranslateUi(QWidget *WaypointNavigationWidget)
    {
        WaypointNavigationWidget->setWindowTitle(QApplication::translate("WaypointNavigationWidget", "Quadrotor Steering", Q_NULLPTR));
        label_topic->setText(QApplication::translate("WaypointNavigationWidget", "Topic", Q_NULLPTR));
        topic_line_edit->setText(QApplication::translate("WaypointNavigationWidget", "/waypoints", Q_NULLPTR));
        label_frame->setText(QApplication::translate("WaypointNavigationWidget", "Frame", Q_NULLPTR));
        frame_line_edit->setText(QApplication::translate("WaypointNavigationWidget", "map", Q_NULLPTR));
        sixDcheckBox->setText(QApplication::translate("WaypointNavigationWidget", "6D", Q_NULLPTR));
        wp_height_label->setText(QApplication::translate("WaypointNavigationWidget", "Default Height", Q_NULLPTR));
        waypoint_count_label->setText(QApplication::translate("WaypointNavigationWidget", "Total Waypoints: ", Q_NULLPTR));
        sel_label->setText(QApplication::translate("WaypointNavigationWidget", "Selected wp: ", Q_NULLPTR));
        sel_wp_label->setText(QString());
        load_wp_button->setText(QApplication::translate("WaypointNavigationWidget", "Load Waypoints", Q_NULLPTR));
        x_label->setText(QApplication::translate("WaypointNavigationWidget", "X:", Q_NULLPTR));
        y_label->setText(QApplication::translate("WaypointNavigationWidget", "Y:", Q_NULLPTR));
        z_label->setText(QApplication::translate("WaypointNavigationWidget", "Z:", Q_NULLPTR));
        yaw_label->setText(QApplication::translate("WaypointNavigationWidget", "Yaw:", Q_NULLPTR));
        clear_all_button->setText(QApplication::translate("WaypointNavigationWidget", "Clear All", Q_NULLPTR));
        save_wp_button->setText(QApplication::translate("WaypointNavigationWidget", "Save Waypoints", Q_NULLPTR));
        publish_wp_button->setText(QApplication::translate("WaypointNavigationWidget", "Publish Waypoints", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WaypointNavigationWidget: public Ui_WaypointNavigationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAYPOINTNAVIGATION_H
