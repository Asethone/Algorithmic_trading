#pragma once

#include <vector>

#include "../../thirdparty/s21_matrix_oop.h"
#include "../../thirdparty/system_of_linear_equations.h"
#include "../algorithm_traiding.h"

namespace s21 {

class LeastSquares : public AlgorithmTraiding {
 public:
  LeastSquares() = default;
  virtual ~LeastSquares() = default;
  long double GetAnswer(std::time_t x) override;
  void SetPolymomialDegree(int size) override;
  void CalculateCoefficient() override;
  void SetDataPoints(const DataPoints& data) override;
  void ClearFields() override;

 private:
  std::vector<long double> coefficient_;
  DataPoints data_;
  int sizePolinom_;
  LU LU_;

  long double SumOfDegree(int degree, bool checkY);
  S21Matrix GetDependentMatrix();
  S21Matrix GetExplainedAnswer();
};

}  // namespace s21