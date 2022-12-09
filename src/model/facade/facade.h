#pragma once

#include <memory>

#include "../algorithm_traiding/algorithm_traiding.h"
#include "../thirdparty/parser.h"

namespace s21 {

constexpr long kSecInDay = 86400;

enum TypeAlgorithmTraiding { kCubicSpline, kNewtonPolynomial, kLeastSquares };

struct MinMaxData {
  double yMax;
  double yMin;
  std::time_t dataMin;
  std::time_t dataMax;
};

class Facade {
 public:
  explicit Facade(Parser* parser);
  ~Facade();

  void InitializingAlgorithmTraiding(
      TypeAlgorithmTraiding typeAlgorithmTraiding);
  void ExportData(const std::string& filename);
  const DataPoints& GetDataBegin();
  void ClearData();
  void ClearAlgorithmData();
  double GetAnswer(int size, time_t timeValue, int days = 0);
  std::string GetAlgorithmName();
  DataPoints GetDataPoints(int step, int size, int days = 0);
  MinMaxData GetMinMaxData();

 private:
  Parser* parser_;
  std::unique_ptr<AlgorithmTraiding> algorithmTraiding_;

  void CalculateCoefficient(const DataPoints& data, int size);
  void ValidatorStep(int step);
  void ValidatorSize(int size);
  void ValidatorTime(time_t timeValue, int days);
  void ValidatorData(const DataPoints& data);
  time_t GetEndData(int days);
};

}  // namespace s21
