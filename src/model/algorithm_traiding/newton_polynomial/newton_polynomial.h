#pragma once

#include <vector>

#include "../algorithm_traiding.h"

namespace s21 {

class NewtonPolynomial : public AlgorithmTraiding {
 public:
  NewtonPolynomial() = default;
  ~NewtonPolynomial() = default;

  void SetPolymomialDegree(int degree) override;
  void CalculateCoefficient() override;

  long double GetAnswer(std::time_t) override;
  void SetDataPoints(const DataPoints &data) override;
  void ClearFields() override;

 private:
  std::vector<std::vector<double>> finite_differences_;

  std::vector<time_t> x_;
  std::vector<double> y_;

  int size_ = 0.;
  time_t step_ = 0.;
  int degree_ = 6;

  void SetStep(time_t step);
  void SetSize(size_t size);
  int FindNearest(time_t x);
  int FindStart(time_t x);
  void AddWeekends(time_t x, time_t lastX, double lastY);
};

}  // namespace s21