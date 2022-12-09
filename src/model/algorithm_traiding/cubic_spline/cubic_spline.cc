#include "cubic_spline.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "../../thirdparty/s21_matrix_oop.h"

namespace s21 {

void CubicSpline::SetPolymomialDegree([[maybe_unused]] int degree) { return; }

void CubicSpline::CalculateCoefficient() {
  S21Matrix coeff(size_ - 1, size_ - 1), answer(size_ - 1, 1);
  for (unsigned i = 1, j = 0; i < size_; i++, j++) {
    const std::time_t stepPrev = data_[i].date - data_[i - 1].date;
    const std::time_t stepCur = data_[i + 1].date - data_[i].date;
    if (i > 1) coeff(j, j - 1) = 1.0 / 3.0 * stepPrev;
    coeff(j, j) = 2.0 / 3.0 * (stepPrev + stepCur);
    if (i < size_ - 1) coeff(j, j + 1) = 1.0 / 3.0 * stepCur;
    answer(j, 0) =
        static_cast<double>((data_[i + 1].y - data_[i].y) / stepCur -
                            (data_[i].y - data_[i - 1].y) / stepPrev);
  }
  c_ = LU_.GetResult(coeff, answer);
  c_.insert(c_.begin(), 0.0);
  c_.push_back(0.0);
  a_.resize(size_);
  b_.resize(size_);
  d_.resize(size_);
  for (unsigned i = 0; i < size_; i++) {
    const std::time_t step = data_[i + 1].date - data_[i].date;
    a_[i] = data_[i].y;
    b_[i] = (data_[i + 1].y - data_[i].y) / step -
            1.0 / 3.0 * (2.0 * c_[i] + c_[i + 1]) * step;
    d_[i] = (c_[i + 1] - c_[i]) / (3.0 * step);
  }
}

long double CubicSpline::GetAnswer(std::time_t x) {
  auto it = std::lower_bound(
      data_.begin(), data_.end(), x,
      [](const DataPoint& a, const std::time_t& b) { return a.date < b; });
  if (it == data_.begin() || it == data_.end()) return data_[0].y;
  unsigned idx = static_cast<unsigned>(std::distance(data_.begin(), it)) - 1;
  const std::time_t xx = x - data_[idx].date;
  return a_[idx] + b_[idx] * xx + c_[idx] * std::pow(xx, 2) +
         d_[idx] * std::pow(xx, 3);
}

void CubicSpline::SetDataPoints(const DataPoints& data) {
  data_ = data;
  size_ = data_.size() - 1;
}

void CubicSpline::ClearFields() {
  a_.clear();
  b_.clear();
  c_.clear();
  d_.clear();
  data_.clear();
}

}  // namespace s21
