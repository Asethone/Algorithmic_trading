#pragma once

#include <QWidget>

#include "../model/facade/facade.h"
#include "../model/thirdparty/qcustomplot.h"

namespace s21 {

constexpr int kWidthGraph = 3;
constexpr int kWidthDot = 5;
constexpr int kMaxGraphs = 5;
constexpr int kMinGraphs = 0;
constexpr long kShiftTime = 864000;
constexpr long kShiftY = 10;

class Validator {
 public:
  static int IsInt(QString argument);
  static bool CheckFileName(QString filename);
};

class Assistant {
 public:
  static void SetFilename(QLineEdit *lineEdit, QString fileName);
  static void ShowMessageBox(QWidget *window, QString message);
};

class GraphWorker {
 public:
  GraphWorker(Facade *facade);
  ~GraphWorker();

  void InitGraphWorker(QCustomPlot *qcustomplot, TypeAlgorithmTraiding type);

  QPair<bool, QString> OnExportGraphInFile(const QString &filename);
  QPair<bool, QString> OnCalculateY(time_t date, QString degree,
                                    QString days = "0");
  QPair<bool, QString> OnDrawGraph(QString points, QString degree,
                                   QString days = "0");
  void OnClearGraph();

  void CheckBtnDrawGraph(QPushButton *btnDraw, QPushButton *btnClear);
  void CheckBtnClearGraph(QPushButton *btnDraw, QPushButton *btnClear);

 private:
  Facade *facade_;
  QCustomPlot *qcustomplot_;
  QVector<QColor> colorGraph = {QColor(255, 81, 60),   QColor(32, 178, 170),
                                QColor(70, 130, 180),  QColor(244, 175, 96),
                                QColor(255, 192, 203), QColor(107, 91, 149)};
  int counterGraphs_;

  QPair<QVector<double>, QVector<double>> VectorToPairQVector(
      const DataPoints &vecDataPoints);

  void SetPen();
  void SetRangePlot();
  void SetBaseSettingPlots();
  void ClearGraphs();
  void DrawExportFile();
  void DrawGraph(int points, int degree, int days);
};

}  // namespace s21
