#include "mainwindow.h"

#include <QMessageBox>

#include "../view/ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  graphWorker_ = new s21::GraphWorker(new s21::Facade(new s21::Parser));
  interpolationWindow_ = new InterpolationWindow;
  graphWorker_->InitGraphWorker(ui->graphWidget, s21::kLeastSquares);
}

MainWindow::~MainWindow() {
  delete ui;
  delete interpolationWindow_;
  delete graphWorker_;
}

void MainWindow::on_calcBtn_clicked() {
  if (!checkFileName()) {
    return;
  }
  time_t date = ui->dateTimeEdit->dateTime().toSecsSinceEpoch();
  QString days = ui->dayLineEdit->text();
  auto pair =
      graphWorker_->OnCalculateY(date, ui->degreeLineEdit->text(), days);
  if (pair.first) {
    ui->predictLineEdit->setText(pair.second);
  } else {
    s21::Assistant::ShowMessageBox(this, pair.second);
  }
}

void MainWindow::on_loadBtn_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, ("Open the file"),
                                                  QDir::homePath(), "*.csv");
  if (fileName.isEmpty()) {
    return;
  }
  auto pair = graphWorker_->OnExportGraphInFile(fileName);
  if (pair.first) {
    s21::Assistant::SetFilename(ui->fileLineEdit, fileName);
  } else {
    s21::Assistant::ShowMessageBox(this, pair.second);
  }
}

void MainWindow::on_drawBtn_clicked() {
  if (!checkFileName()) {
    return;
  }
  QString points = ui->pointLineEdit->text();
  QString degree = ui->degreeLineEdit->text();
  QString days = ui->dayLineEdit->text();
  auto pair = graphWorker_->OnDrawGraph(points, degree, days);
  if (!pair.first) {
    s21::Assistant::ShowMessageBox(this, pair.second);
  }
  graphWorker_->CheckBtnDrawGraph(ui->drawBtn, ui->clearBtn);
}

void MainWindow::on_clearBtn_clicked() {
  graphWorker_->OnClearGraph();
  graphWorker_->CheckBtnClearGraph(ui->drawBtn, ui->clearBtn);
}

void MainWindow::on_actionInterpolation_triggered() {
  hide();
  interpolationWindow_->show();
}

void MainWindow::on_actionAproximation_2_triggered() {
  interpolationWindow_->hide();
  show();
}

bool MainWindow::checkFileName() {
  if (!s21::Validator::CheckFileName(ui->fileLineEdit->text())) {
    s21::Assistant::ShowMessageBox(this, "Error: need upload file");
    return false;
  }
  return true;
}

}  // namespace s21
