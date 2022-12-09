#pragma once

#include <vector>

#include "../thirdparty/parser.h"

namespace s21 {

class AlgorithmTraiding {
 public:
  AlgorithmTraiding() = default;
  virtual ~AlgorithmTraiding() = default;
  virtual void SetPolymomialDegree(int) = 0;
  virtual long double GetAnswer(std::time_t) = 0;
  virtual void CalculateCoefficient() = 0;
  virtual void SetDataPoints(const DataPoints&) = 0;
  virtual void ClearFields() = 0;

  DataPoints GetDataPoints(int step, std::time_t minData, std::time_t maxData);
};

}  // namespace s21