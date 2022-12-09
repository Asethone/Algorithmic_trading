#pragma once

#include <QDialog>

#include "graph_worker.h"

namespace Ui {
class InterpolationWindow;
}

namespace s21 {

class InterpolationWindow : public QDialog {
  Q_OBJECT

 public:
  explicit InterpolationWindow(QWidget *parent = nullptr);
  ~InterpolationWindow();

 private slots:
  void on_loadBtn_clicked();

  void on_calcBtn_clicked();

  void on_drawBtn_clicked();

  void on_clearBtn_clicked();

  void on_newtonRBtn_toggled(bool checked);

  void on_splineRBtn_toggled(bool checked);

 private:
  Ui::InterpolationWindow *ui;
  s21::GraphWorker *graphWorker_;

  bool checkFileName();
};

}  // namespace s21
