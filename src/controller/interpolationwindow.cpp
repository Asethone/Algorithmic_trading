#include "interpolationwindow.h"

#include "../view/ui_interpolationwindow.h"

namespace s21 {

InterpolationWindow::InterpolationWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::InterpolationWindow) {
  ui->setupUi(this);
  graphWorker_ = new s21::GraphWorker(new s21::Facade(new s21::Parser));
  graphWorker_->InitGraphWorker(ui->graphWidget, s21::kCubicSpline);
}

InterpolationWindow::~InterpolationWindow() {
  delete ui;
  delete graphWorker_;
}

void InterpolationWindow::on_loadBtn_clicked() {
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

void InterpolationWindow::on_calcBtn_clicked() {
  if (!checkFileName()) {
    return;
  }
  time_t date = ui->dateTimeEdit->dateTime().toSecsSinceEpoch();
  auto pair = graphWorker_->OnCalculateY(date, ui->degreeLineEdit->text());
  if (pair.first) {
    ui->predictLineEdit->setText(pair.second);
  } else {
    s21::Assistant::ShowMessageBox(this, pair.second);
  }
}

void InterpolationWindow::on_drawBtn_clicked() {
  if (!checkFileName()) {
    return;
  }
  QString points = ui->pointLineEdit->text();
  QString degree = ui->degreeLineEdit->text();
  auto pair = graphWorker_->OnDrawGraph(points, degree);
  if (!pair.first) {
    s21::Assistant::ShowMessageBox(this, pair.second);
  }
  graphWorker_->CheckBtnDrawGraph(ui->drawBtn, ui->clearBtn);
}

void InterpolationWindow::on_clearBtn_clicked() {
  graphWorker_->OnClearGraph();
  graphWorker_->CheckBtnClearGraph(ui->drawBtn, ui->clearBtn);
}

void InterpolationWindow::on_newtonRBtn_toggled(bool checked) {
  auto type = checked ? s21::kNewtonPolynomial : s21::kCubicSpline;
  graphWorker_->InitGraphWorker(ui->graphWidget, type);
}

void InterpolationWindow::on_splineRBtn_toggled(bool checked) {
  ui->degreeLineEdit->setReadOnly(checked);
}

bool InterpolationWindow::checkFileName() {
  if (!s21::Validator::CheckFileName(ui->fileLineEdit->text())) {
    s21::Assistant::ShowMessageBox(this, "Error: need upload file");
    return false;
  }
  return true;
}

}  // namespace s21
