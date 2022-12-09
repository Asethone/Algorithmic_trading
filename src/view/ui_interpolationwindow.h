#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

#include "../model/thirdparty/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_InterpolationWindow {
 public:
  QGridLayout *gridLayout;
  QPushButton *calcBtn;
  QDateTimeEdit *dateTimeEdit;
  QLineEdit *degreeLineEdit;
  QLineEdit *pointLineEdit;
  QPushButton *loadBtn;
  QRadioButton *newtonRBtn;
  QPushButton *clearBtn;
  QLabel *label_5;
  QLabel *pointLbl;
  QCustomPlot *graphWidget;
  QPushButton *drawBtn;
  QLabel *label;
  QLabel *label_3;
  QLineEdit *fileLineEdit;
  QLineEdit *predictLineEdit;
  QRadioButton *splineRBtn;

  void setupUi(QDialog *InterpolationWindow) {
    if (InterpolationWindow->objectName().isEmpty())
      InterpolationWindow->setObjectName(
          QString::fromUtf8("InterpolationWindow"));
    InterpolationWindow->resize(1504, 795);
    InterpolationWindow->setStyleSheet(
        QString::fromUtf8("background-color: #ebeae6;"));
    gridLayout = new QGridLayout(InterpolationWindow);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    calcBtn = new QPushButton(InterpolationWindow);
    calcBtn->setObjectName(QString::fromUtf8("calcBtn"));
    calcBtn->setMaximumSize(QSize(200, 16777215));
    QFont font;
    font.setFamilies({QString::fromUtf8("PT Sans")});
    font.setPointSize(16);
    font.setBold(false);
    calcBtn->setFont(font);
    calcBtn->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "background-color: #ff513c;\n"
                          "border-radius:0.4em;\n"
                          "padding: 0.7em 1.7em;\n"
                          "height: 20px;\n"
                          "border: none;\n"
                          "color: #ebeae6;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "}\n"
                          "\n"
                          "QPushButton:hover {\n"
                          "background-color: #ff260c;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "color: rgba(41, 47, 46, 231);\n"
                          "}"));

    gridLayout->addWidget(calcBtn, 12, 0, 1, 1);

    dateTimeEdit = new QDateTimeEdit(InterpolationWindow);
    dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
    dateTimeEdit->setMaximumSize(QSize(200, 16777215));
    QFont font1;
    font1.setFamilies({QString::fromUtf8("PT Sans")});
    font1.setPointSize(16);
    dateTimeEdit->setFont(font1);
    dateTimeEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    dateTimeEdit->setDateTime(QDateTime(QDate(2022, 1, 1), QTime(0, 0, 0)));
    dateTimeEdit->setDate(QDate(2022, 1, 1));
    dateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);

    gridLayout->addWidget(dateTimeEdit, 10, 0, 1, 1);

    degreeLineEdit = new QLineEdit(InterpolationWindow);
    degreeLineEdit->setObjectName(QString::fromUtf8("degreeLineEdit"));
    degreeLineEdit->setMaximumSize(QSize(200, 16777215));
    degreeLineEdit->setFont(font1);
    degreeLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    degreeLineEdit->setMaxLength(2);
    degreeLineEdit->setReadOnly(true);

    gridLayout->addWidget(degreeLineEdit, 8, 0, 1, 1);

    pointLineEdit = new QLineEdit(InterpolationWindow);
    pointLineEdit->setObjectName(QString::fromUtf8("pointLineEdit"));
    pointLineEdit->setMaximumSize(QSize(200, 16777215));
    pointLineEdit->setFont(font1);
    pointLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    pointLineEdit->setMaxLength(4);
    pointLineEdit->setReadOnly(false);

    gridLayout->addWidget(pointLineEdit, 6, 0, 1, 1);

    loadBtn = new QPushButton(InterpolationWindow);
    loadBtn->setObjectName(QString::fromUtf8("loadBtn"));
    loadBtn->setMaximumSize(QSize(200, 16777215));
    loadBtn->setFont(font);
    loadBtn->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "background-color: #ff513c;\n"
                          "border-radius:0.4em;\n"
                          "padding: 0.7em 1.7em;\n"
                          "height: 20px;\n"
                          "border: none;\n"
                          "color: #ebeae6;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "}\n"
                          "\n"
                          "QPushButton:hover {\n"
                          "background-color: #ff260c;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "color: rgba(41, 47, 46, 231);\n"
                          "}"));

    gridLayout->addWidget(loadBtn, 0, 0, 1, 1);

    newtonRBtn = new QRadioButton(InterpolationWindow);
    newtonRBtn->setObjectName(QString::fromUtf8("newtonRBtn"));
    QFont font2;
    font2.setPointSize(16);
    newtonRBtn->setFont(font2);
    newtonRBtn->setStyleSheet(
        QString::fromUtf8("QRadioButton {\n"
                          "	color: #3c3b3a;\n"
                          "	border-radius : 5;\n"
                          "}\n"
                          "\n"
                          "QRadioButton::indicator {\n"
                          "    width:                  10px;\n"
                          "    height:                 10px;\n"
                          "    border-radius:          7px;\n"
                          "}\n"
                          "\n"
                          "QRadioButton::indicator:checked {\n"
                          "    background-color:       #ff513c;\n"
                          "    border:                 2px solid white;\n"
                          "}\n"
                          "\n"
                          "QRadioButton::indicator:unchecked {\n"
                          "    background-color:       #ebeae6;\n"
                          "    border:                 2px solid white;\n"
                          "}"));

    gridLayout->addWidget(newtonRBtn, 4, 0, 1, 1);

    clearBtn = new QPushButton(InterpolationWindow);
    clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
    clearBtn->setEnabled(false);
    clearBtn->setMaximumSize(QSize(200, 16777215));
    clearBtn->setFont(font);
    clearBtn->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "background-color: #ff513c;\n"
                          "border-radius:0.4em;\n"
                          "padding: 0.7em 1.7em;\n"
                          "height: 20px;\n"
                          "border: none;\n"
                          "color: #ebeae6;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "}\n"
                          "\n"
                          "QPushButton:hover {\n"
                          "background-color: #ff260c;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "color: rgba(41, 47, 46, 231);\n"
                          "}"));

    gridLayout->addWidget(clearBtn, 14, 0, 1, 1);

    label_5 = new QLabel(InterpolationWindow);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setMaximumSize(QSize(250, 25));
    QFont font3;
    font3.setFamilies({QString::fromUtf8("PT Sans")});
    font3.setPointSize(18);
    font3.setBold(false);
    label_5->setFont(font3);
    label_5->setLayoutDirection(Qt::LeftToRight);
    label_5->setStyleSheet(
        QString::fromUtf8("color: #ff513c;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;"));
    label_5->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_5, 9, 0, 1, 1);

    pointLbl = new QLabel(InterpolationWindow);
    pointLbl->setObjectName(QString::fromUtf8("pointLbl"));
    pointLbl->setMaximumSize(QSize(200, 25));
    pointLbl->setFont(font3);
    pointLbl->setLayoutDirection(Qt::LeftToRight);
    pointLbl->setStyleSheet(
        QString::fromUtf8("color: #ff513c;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "margin-left: auto;\n"
                          "margin-right: auto;"));
    pointLbl->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(pointLbl, 5, 0, 1, 1);

    graphWidget = new QCustomPlot(InterpolationWindow);
    graphWidget->setObjectName(QString::fromUtf8("graphWidget"));
    graphWidget->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(graphWidget, 0, 2, 15, 1);

    drawBtn = new QPushButton(InterpolationWindow);
    drawBtn->setObjectName(QString::fromUtf8("drawBtn"));
    drawBtn->setMaximumSize(QSize(200, 16777215));
    drawBtn->setFont(font);
    drawBtn->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "background-color: #ff513c;\n"
                          "border-radius:0.4em;\n"
                          "padding: 0.7em 1.7em;\n"
                          "height: 20px;\n"
                          "border: none;\n"
                          "color: #ebeae6;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "}\n"
                          "\n"
                          "QPushButton:hover {\n"
                          "background-color: #ff260c;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "color: rgba(41, 47, 46, 231);\n"
                          "}"));

    gridLayout->addWidget(drawBtn, 13, 0, 1, 1);

    label = new QLabel(InterpolationWindow);
    label->setObjectName(QString::fromUtf8("label"));
    label->setMaximumSize(QSize(200, 25));
    label->setFont(font3);
    label->setStyleSheet(
        QString::fromUtf8("color: #ff513c;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "margin-left: auto;\n"
                          "margin-right: auto;"));
    label->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label, 2, 0, 1, 1);

    label_3 = new QLabel(InterpolationWindow);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setMaximumSize(QSize(200, 25));
    label_3->setFont(font3);
    label_3->setLayoutDirection(Qt::LeftToRight);
    label_3->setStyleSheet(
        QString::fromUtf8("color: #ff513c;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "margin-left: auto;\n"
                          "margin-right: auto;"));
    label_3->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_3, 7, 0, 1, 1);

    fileLineEdit = new QLineEdit(InterpolationWindow);
    fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));
    fileLineEdit->setMaximumSize(QSize(200, 16777215));
    fileLineEdit->setFont(font1);
    fileLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    fileLineEdit->setReadOnly(true);

    gridLayout->addWidget(fileLineEdit, 1, 0, 1, 1);

    predictLineEdit = new QLineEdit(InterpolationWindow);
    predictLineEdit->setObjectName(QString::fromUtf8("predictLineEdit"));
    predictLineEdit->setMaximumSize(QSize(200, 16777215));
    predictLineEdit->setFont(font1);
    predictLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    predictLineEdit->setReadOnly(true);

    gridLayout->addWidget(predictLineEdit, 11, 0, 1, 1);

    splineRBtn = new QRadioButton(InterpolationWindow);
    splineRBtn->setObjectName(QString::fromUtf8("splineRBtn"));
    splineRBtn->setFont(font2);
    splineRBtn->setStyleSheet(
        QString::fromUtf8("QRadioButton {\n"
                          "	color: #3c3b3a;\n"
                          "	border-radius : 5;\n"
                          "}\n"
                          "\n"
                          "QRadioButton::indicator {\n"
                          "    width:                  10px;\n"
                          "    height:                 10px;\n"
                          "    border-radius:          7px;\n"
                          "}\n"
                          "\n"
                          "QRadioButton::indicator:checked {\n"
                          "    background-color:       #ff513c;\n"
                          "    border:                 2px solid white;\n"
                          "}\n"
                          "\n"
                          "QRadioButton::indicator:unchecked {\n"
                          "    background-color:       #ebeae6;\n"
                          "    border:                 2px solid white;\n"
                          "}"));
    splineRBtn->setChecked(true);

    gridLayout->addWidget(splineRBtn, 3, 0, 1, 1);

    retranslateUi(InterpolationWindow);

    QMetaObject::connectSlotsByName(InterpolationWindow);
  }  // setupUi

  void retranslateUi(QDialog *InterpolationWindow) {
    InterpolationWindow->setWindowTitle(QCoreApplication::translate(
        "InterpolationWindow", "Interpolation", nullptr));
    calcBtn->setText(QCoreApplication::translate("InterpolationWindow",
                                                 "Calculate", nullptr));
    dateTimeEdit->setDisplayFormat(QCoreApplication::translate(
        "InterpolationWindow", "yyyy/MM/dd hh:mm:ss", nullptr));
    degreeLineEdit->setText(
        QCoreApplication::translate("InterpolationWindow", "1", nullptr));
    pointLineEdit->setText(
        QCoreApplication::translate("InterpolationWindow", "1000", nullptr));
    loadBtn->setText(QCoreApplication::translate("InterpolationWindow",
                                                 "Load file", nullptr));
    newtonRBtn->setText(
        QCoreApplication::translate("InterpolationWindow", "Newton", nullptr));
    clearBtn->setText(
        QCoreApplication::translate("InterpolationWindow", "Clear", nullptr));
    label_5->setText(QCoreApplication::translate("InterpolationWindow",
                                                 "Predict value", nullptr));
    pointLbl->setText(
        QCoreApplication::translate("InterpolationWindow", "Points", nullptr));
    drawBtn->setText(
        QCoreApplication::translate("InterpolationWindow", "Draw", nullptr));
    label->setText(
        QCoreApplication::translate("InterpolationWindow", "Type", nullptr));
    label_3->setText(
        QCoreApplication::translate("InterpolationWindow", "Degree", nullptr));
    predictLineEdit->setText(QString());
    splineRBtn->setText(QCoreApplication::translate("InterpolationWindow",
                                                    "Cubic spline", nullptr));
  }  // retranslateUi
};

namespace Ui {
class InterpolationWindow : public Ui_InterpolationWindow {};
}  // namespace Ui

QT_END_NAMESPACE
