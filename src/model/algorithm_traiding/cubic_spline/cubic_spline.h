#pragma once

#include <vector>

#include "../../thirdparty/system_of_linear_equations.h"
#include "../algorithm_traiding.h"

namespace s21 {

class CubicSpline : public AlgorithmTraiding {
 public:
  CubicSpline() = default;
  ~CubicSpline() = default;

  void SetPolymomialDegree(int degree) override;
  void CalculateCoefficient() override;

  long double GetAnswer(std::time_t x) override;
  void SetDataPoints(const DataPoints &data) override;
  void ClearFields() override;

 private:
  std::vector<long double> a_, b_, c_, d_;
  unsigned size_;
  DataPoints data_;
  LU LU_;
};

}  // namespace s21
