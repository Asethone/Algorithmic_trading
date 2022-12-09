#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "../model/thirdparty/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QAction *actionInterpolation;
  QAction *actionAproximation_2;
  QWidget *centralwidget;
  QGridLayout *gridLayout;
  QLabel *label_4;
  QPushButton *loadBtn;
  QLineEdit *predictLineEdit;
  QLineEdit *degreeLineEdit;
  QLineEdit *pointLineEdit;
  QCustomPlot *graphWidget;
  QDateTimeEdit *dateTimeEdit;
  QLabel *label_3;
  QPushButton *clearBtn;
  QLabel *pointLbl;
  QLabel *label_5;
  QLineEdit *dayLineEdit;
  QPushButton *drawBtn;
  QPushButton *calcBtn;
  QLineEdit *fileLineEdit;
  QMenuBar *menubar;
  QMenu *menuMenu;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1761, 795);
    MainWindow->setStyleSheet(QString::fromUtf8("background-color: #ebeae6;"));
    MainWindow->setLocale(QLocale(QLocale::English, QLocale::World));
    actionInterpolation = new QAction(MainWindow);
    actionInterpolation->setObjectName(
        QString::fromUtf8("actionInterpolation"));
    actionAproximation_2 = new QAction(MainWindow);
    actionAproximation_2->setObjectName(
        QString::fromUtf8("actionAproximation_2"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label_4 = new QLabel(centralwidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setMaximumSize(QSize(200, 25));
    QFont font;
    font.setFamilies({QString::fromUtf8("PT Sans")});
    font.setPointSize(18);
    font.setBold(false);
    label_4->setFont(font);
    label_4->setLayoutDirection(Qt::LeftToRight);
    label_4->setStyleSheet(
        QString::fromUtf8("color: #ff513c;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "margin-left: auto;\n"
                          "margin-right: auto;"));
    label_4->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_4, 4, 0, 1, 1);

    loadBtn = new QPushButton(centralwidget);
    loadBtn->setObjectName(QString::fromUtf8("loadBtn"));
    loadBtn->setMaximumSize(QSize(200, 16777215));
    QFont font1;
    font1.setFamilies({QString::fromUtf8("PT Sans")});
    font1.setPointSize(16);
    font1.setBold(false);
    loadBtn->setFont(font1);
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
                          "}\n"
                          "\n"
                          ""));

    gridLayout->addWidget(loadBtn, 0, 0, 1, 1);

    predictLineEdit = new QLineEdit(centralwidget);
    predictLineEdit->setObjectName(QString::fromUtf8("predictLineEdit"));
    predictLineEdit->setMaximumSize(QSize(200, 16777215));
    QFont font2;
    font2.setFamilies({QString::fromUtf8("PT Sans")});
    font2.setPointSize(16);
    predictLineEdit->setFont(font2);
    predictLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    predictLineEdit->setReadOnly(true);

    gridLayout->addWidget(predictLineEdit, 10, 0, 1, 1);

    degreeLineEdit = new QLineEdit(centralwidget);
    degreeLineEdit->setObjectName(QString::fromUtf8("degreeLineEdit"));
    degreeLineEdit->setMaximumSize(QSize(200, 16777215));
    degreeLineEdit->setFont(font2);
    degreeLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    degreeLineEdit->setMaxLength(2);

    gridLayout->addWidget(degreeLineEdit, 7, 0, 1, 1);

    pointLineEdit = new QLineEdit(centralwidget);
    pointLineEdit->setObjectName(QString::fromUtf8("pointLineEdit"));
    pointLineEdit->setMaximumSize(QSize(200, 16777215));
    pointLineEdit->setFont(font2);
    pointLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    pointLineEdit->setMaxLength(4);

    gridLayout->addWidget(pointLineEdit, 3, 0, 1, 1);

    graphWidget = new QCustomPlot(centralwidget);
    graphWidget->setObjectName(QString::fromUtf8("graphWidget"));
    graphWidget->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(graphWidget, 0, 1, 14, 1);

    dateTimeEdit = new QDateTimeEdit(centralwidget);
    dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
    dateTimeEdit->setMaximumSize(QSize(200, 16777215));
    dateTimeEdit->setFont(font2);
    dateTimeEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    dateTimeEdit->setDateTime(QDateTime(QDate(2022, 1, 1), QTime(0, 0, 0)));
    dateTimeEdit->setDate(QDate(2022, 1, 1));
    dateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);

    gridLayout->addWidget(dateTimeEdit, 9, 0, 1, 1);

    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setMaximumSize(QSize(200, 25));
    label_3->setFont(font);
    label_3->setLayoutDirection(Qt::LeftToRight);
    label_3->setStyleSheet(
        QString::fromUtf8("color: #ff513c;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "margin-left: auto;\n"
                          "margin-right: auto;"));
    label_3->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_3, 6, 0, 1, 1);

    clearBtn = new QPushButton(centralwidget);
    clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
    clearBtn->setEnabled(false);
    clearBtn->setMaximumSize(QSize(200, 16777215));
    clearBtn->setFont(font1);
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

    gridLayout->addWidget(clearBtn, 13, 0, 1, 1);

    pointLbl = new QLabel(centralwidget);
    pointLbl->setObjectName(QString::fromUtf8("pointLbl"));
    pointLbl->setMaximumSize(QSize(200, 25));
    pointLbl->setFont(font);
    pointLbl->setLayoutDirection(Qt::LeftToRight);
    pointLbl->setStyleSheet(
        QString::fromUtf8("color: #ff513c;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "margin-left: auto;\n"
                          "margin-right: auto;"));
    pointLbl->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(pointLbl, 2, 0, 1, 1);

    label_5 = new QLabel(centralwidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setMaximumSize(QSize(200, 25));
    label_5->setFont(font);
    label_5->setLayoutDirection(Qt::LeftToRight);
    label_5->setStyleSheet(
        QString::fromUtf8("color: #ff513c;\n"
                          "text-transform: uppercase;\n"
                          "font-weight: 500;\n"
                          "margin-left: auto;\n"
                          "margin-right: auto;"));
    label_5->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_5, 8, 0, 1, 1);

    dayLineEdit = new QLineEdit(centralwidget);
    dayLineEdit->setObjectName(QString::fromUtf8("dayLineEdit"));
    dayLineEdit->setMaximumSize(QSize(200, 16777215));
    dayLineEdit->setFont(font2);
    dayLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    dayLineEdit->setMaxLength(3);

    gridLayout->addWidget(dayLineEdit, 5, 0, 1, 1);

    drawBtn = new QPushButton(centralwidget);
    drawBtn->setObjectName(QString::fromUtf8("drawBtn"));
    drawBtn->setMaximumSize(QSize(200, 16777215));
    drawBtn->setFont(font1);
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

    gridLayout->addWidget(drawBtn, 12, 0, 1, 1);

    calcBtn = new QPushButton(centralwidget);
    calcBtn->setObjectName(QString::fromUtf8("calcBtn"));
    calcBtn->setMaximumSize(QSize(200, 16777215));
    calcBtn->setFont(font1);
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

    gridLayout->addWidget(calcBtn, 11, 0, 1, 1);

    fileLineEdit = new QLineEdit(centralwidget);
    fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));
    fileLineEdit->setMaximumSize(QSize(200, 16777215));
    fileLineEdit->setFont(font2);
    fileLineEdit->setStyleSheet(
        QString::fromUtf8("color: #3c3b3a;\n"
                          "border-color: #ff513c;\n"
                          "border-width : 1.2px;\n"
                          "border-radius : 5;\n"
                          "border-style:inset;"));
    fileLineEdit->setReadOnly(true);

    gridLayout->addWidget(fileLineEdit, 1, 0, 1, 1);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1761, 24));
    menuMenu = new QMenu(menubar);
    menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
    MainWindow->setMenuBar(menubar);

    menubar->addAction(menuMenu->menuAction());
    menuMenu->addAction(actionInterpolation);
    menuMenu->addAction(actionAproximation_2);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "Aproximation", nullptr));
    actionInterpolation->setText(
        QCoreApplication::translate("MainWindow", "Interpolation", nullptr));
#if QT_CONFIG(shortcut)
    actionInterpolation->setShortcut(
        QCoreApplication::translate("MainWindow", "Meta+2", nullptr));
#endif  // QT_CONFIG(shortcut)
    actionAproximation_2->setText(
        QCoreApplication::translate("MainWindow", "Aproximation", nullptr));
#if QT_CONFIG(shortcut)
    actionAproximation_2->setShortcut(
        QCoreApplication::translate("MainWindow", "Meta+1", nullptr));
#endif  // QT_CONFIG(shortcut)
    label_4->setText(
        QCoreApplication::translate("MainWindow", "Days", nullptr));
    loadBtn->setText(
        QCoreApplication::translate("MainWindow", "Load file", nullptr));
    predictLineEdit->setText(QString());
    degreeLineEdit->setText(
        QCoreApplication::translate("MainWindow", "1", nullptr));
    pointLineEdit->setText(
        QCoreApplication::translate("MainWindow", "1000", nullptr));
    dateTimeEdit->setDisplayFormat(QCoreApplication::translate(
        "MainWindow", "yyyy/MM/dd hh:mm:ss", nullptr));
    label_3->setText(
        QCoreApplication::translate("MainWindow", "Degree", nullptr));
    clearBtn->setText(
        QCoreApplication::translate("MainWindow", "Clear", nullptr));
    pointLbl->setText(
        QCoreApplication::translate("MainWindow", "Points", nullptr));
    label_5->setText(
        QCoreApplication::translate("MainWindow", "Predict value", nullptr));
    dayLineEdit->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    drawBtn->setText(
        QCoreApplication::translate("MainWindow", "Draw", nullptr));
    calcBtn->setText(
        QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    menuMenu->setTitle(
        QCoreApplication::translate("MainWindow", "Menu", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE
