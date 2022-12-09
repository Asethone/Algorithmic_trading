QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = Algorithm_traiding
INCLUDEPATH += .

CONFIG += c++17

SOURCES += \
    ../src/controller/graph_worker.cpp \
    ../src/controller/interpolationwindow.cpp \
    ../src/controller/mainwindow.cpp \
    ../src/main.cpp \
    ../src/model/algorithm_traiding/algorithm_traiding.cc \
    ../src/model/algorithm_traiding/cubic_spline/cubic_spline.cc \
    ../src/model/algorithm_traiding/least_squares/least_squares.cc \
    ../src/model/algorithm_traiding/newton_polynomial/newton_polynomial.cc \
    ../src/model/facade/facade.cc \
    ../src/model/thirdparty/parser.cc \
    ../src/model/thirdparty/qcustomplot.cpp \
    ../src/model/thirdparty/s21_matrix_oop.cc \
    ../src/model/thirdparty/system_of_linear_equations.cc \

HEADERS += \
   ../src/controller/graph_worker.h \
    ../src/controller/interpolationwindow.h \
    ../src/controller/mainwindow.h \
    ../src/model/algorithm_traiding/algorithm_traiding.h \
    ../src/model/algorithm_traiding/cubic_spline/cubic_spline.h \
    ../src/model/algorithm_traiding/least_squares/least_squares.h \
    ../src/model/facade/facade.h \
    ../src/model/thirdparty/datapoint.h \
    ../src/model/thirdparty/parser.h \
    ../src/model/thirdparty/qcustomplot.h \
    ../src/model/thirdparty/s21_matrix_oop.h \
    ../src/model/thirdparty/system_of_linear_equations.h \
    ../src/view/ui_interpolationwindow.h \
    ../src/view/ui_mainwindow.h

ICON = ../src/icon.icns