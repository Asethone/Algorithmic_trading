#include "graph_worker.h"

namespace s21 {

GraphWorker::GraphWorker(s21::Facade *facade) : facade_(facade) {}

GraphWorker::~GraphWorker() {
  if (facade_ != nullptr) delete facade_;
}

void GraphWorker::InitGraphWorker(QCustomPlot *qcustomplot,
                                  TypeAlgorithmTraiding type) {
  qcustomplot_ = qcustomplot;
  SetBaseSettingPlots();
  facade_->InitializingAlgorithmTraiding(type);
}

QPair<bool, QString> GraphWorker::OnExportGraphInFile(const QString &filename) {
  try {
    counterGraphs_ = 0;
    ClearGraphs();
    facade_->ExportData(filename.toStdString());
    DrawExportFile();
    return {true, ""};
  } catch (std::invalid_argument &ex) {
    return {false, ex.what()};
  }
}

QPair<bool, QString> GraphWorker::OnCalculateY(time_t date, QString degreeStr,
                                               QString daysStr) {
  int degree, days;
  try {
    degree = Validator::IsInt(degreeStr);
    days = Validator::IsInt(daysStr);
  } catch (std::invalid_argument &ex) {
    return {false, ex.what()};
  }
  try {
    facade_->ClearAlgorithmData();
    QString predictStr =
        QString::number(facade_->GetAnswer(degree, date, days));
    return {true, predictStr};
  } catch (std::invalid_argument &ex) {
    return {false, ex.what()};
  }
}

QPair<bool, QString> GraphWorker::OnDrawGraph(QString pointsStr,
                                              QString degreeStr,
                                              QString daysStr) {
  int degree, points, days;
  try {
    degree = Validator::IsInt(degreeStr);
    points = Validator::IsInt(pointsStr);
    days = Validator::IsInt(daysStr);
  } catch (std::invalid_argument &ex) {
    return {false, ex.what()};
  }
  try {
    facade_->ClearAlgorithmData();
    counterGraphs_ += 1;
    DrawGraph(points, degree, days);
    return {true, ""};
  } catch (std::invalid_argument &ex) {
    return {false, ex.what()};
  }
}

void GraphWorker::OnClearGraph() {
  qcustomplot_->removeGraph(counterGraphs_);
  counterGraphs_--;
  qcustomplot_->replot();
}

void GraphWorker::CheckBtnDrawGraph(QPushButton *btnDraw,
                                    QPushButton *btnClear) {
  if (counterGraphs_ == kMaxGraphs) {
    btnDraw->setEnabled(false);
  }
  btnClear->setEnabled(true);
}

void GraphWorker::CheckBtnClearGraph(QPushButton *btnDraw,
                                     QPushButton *btnClear) {
  if (counterGraphs_ == kMinGraphs) {
    btnClear->setEnabled(false);
  }
  btnDraw->setEnabled(true);
}

QPair<QVector<double>, QVector<double>> GraphWorker::VectorToPairQVector(
    const DataPoints &vecDataPoints) {
  QVector<double> x(vecDataPoints.size());
  QVector<double> y(vecDataPoints.size());
  QPair<QVector<QCPGraphData>, QVector<double>> pair;
  for (unsigned long i = 0; i < vecDataPoints.size(); i++) {
    x[i] = vecDataPoints[i].date;
    y[i] = vecDataPoints[i].y;
  }
  return {x, y};
}

void GraphWorker::SetBaseSettingPlots() {
  QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
  dateTicker->setDateTimeFormat("dd.MMMM.yyyy");
  qcustomplot_->xAxis->setTicker(dateTicker);
  qcustomplot_->setInteraction(QCP::iRangeZoom, true);
  qcustomplot_->setInteraction(QCP::iRangeDrag, true);
  qcustomplot_->setBackground(QColor(235, 234, 230));
  qcustomplot_->legend->setVisible(true);
  qcustomplot_->replot();
}

void GraphWorker::DrawExportFile() {
  qcustomplot_->addGraph();
  qcustomplot_->graph(0)->setScatterStyle(
      (QCPScatterStyle(QCPScatterStyle::ssCircle, colorGraph[counterGraphs_],
                       colorGraph[counterGraphs_], kWidthDot)));
  qcustomplot_->graph(0)->setLineStyle(QCPGraph::lsNone);
  qcustomplot_->graph(0)->setName("Points");
  SetRangePlot();
  auto pair = VectorToPairQVector(facade_->GetDataBegin());
  qcustomplot_->graph()->addData(pair.first, pair.second);
  qcustomplot_->replot();
}

void GraphWorker::DrawGraph(int points, int degree, int days) {
  SetPen();
  auto pair = VectorToPairQVector(facade_->GetDataPoints(points, degree, days));
  SetRangePlot();
  qcustomplot_->graph(counterGraphs_)->addData(pair.first, pair.second);
  QString graphName = QString::fromStdString(facade_->GetAlgorithmName());
  if (graphName.contains("Degree")) {
    graphName.append(QString::number(degree));
  }
  qcustomplot_->graph(counterGraphs_)->setName(graphName);
  qcustomplot_->replot();
}

void GraphWorker::SetPen() {
  QPen pen;
  pen.setWidthF(kWidthGraph);
  pen.setColor(colorGraph[counterGraphs_]);
  qcustomplot_->addGraph()->setPen(pen);
}

void GraphWorker::SetRangePlot() {
  s21::MinMaxData minMaxData = facade_->GetMinMaxData();
  qcustomplot_->xAxis->setRange(minMaxData.dataMin - kShiftTime,
                                minMaxData.dataMax + kShiftTime);
  qcustomplot_->yAxis->setRange(minMaxData.yMin - kShiftY,
                                minMaxData.yMax + kShiftY);
}

void GraphWorker::ClearGraphs() {
  facade_->ClearData();
  qcustomplot_->clearGraphs();
}

int Validator::IsInt(QString argument) {
  bool check = true;
  int value = argument.toInt(&check);
  if (!check) {
    throw std::invalid_argument("Error: input int argument");
  }
  return value;
}

bool Validator::CheckFileName(QString filename) {
  if (filename.isEmpty()) {
    return false;
  }
  return true;
}

void Assistant::SetFilename(QLineEdit *lineEdit, QString fileName) {
  qsizetype n = fileName.lastIndexOf('/') + 1;
  QString filename = fileName.right(fileName.size() - n);
  lineEdit->setText(filename);
}

void Assistant::ShowMessageBox(QWidget *window, QString message) {
  QMessageBox msg_box(window);
  msg_box.setStyleSheet("background-color: #1A1D21;\n color: #FFFFFF");
  QString buttonStyle =
      "QPushButton {\nbackground-color: #ff513c;\n border-radius:0.4em;\n "
      "border: none;\n color: #ebeae6;}";
  QPushButton *btn =
      msg_box.addButton("I won't do this anymore", QMessageBox::ActionRole);
  btn->setStyleSheet(buttonStyle + QString::fromUtf8("QPushButton {\n"
                                                     "padding: 5px 10px;"
                                                     "}"));
  msg_box.setText(message);
  msg_box.exec();
}

}  // namespace s21
