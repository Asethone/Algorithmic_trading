#pragma once

#include <QMainWindow>

#include "../model/facade/facade.h"
#include "graph_worker.h"
#include "interpolationwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_calcBtn_clicked();
  void on_loadBtn_clicked();
  void on_drawBtn_clicked();
  void on_clearBtn_clicked();
  void on_actionInterpolation_triggered();
  void on_actionAproximation_2_triggered();

 private:
  Ui::MainWindow *ui;
  s21::GraphWorker *graphWorker_;
  InterpolationWindow *interpolationWindow_;

  bool checkFileName();
};

}  // namespace s21
