#include "newton_polynomial.h"

#include <algorithm>
#include <cmath>

namespace s21 {

static long double factorial(long double n) {
  long double f = 1;
  for (int i = 1; i <= n; ++i) f *= i;
  return f;
}

void NewtonPolynomial::ClearFields() {
  finite_differences_.clear();
  x_.clear();
  y_.clear();
}

void NewtonPolynomial::SetPolymomialDegree(int degree) { degree_ = degree; }

void NewtonPolynomial::SetStep(time_t step) { step_ = step; }

void NewtonPolynomial::SetSize(size_t size) { size_ = static_cast<int>(size); }

void NewtonPolynomial::SetDataPoints(const DataPoints& data) {
  SetStep(data.at(1).date - data.at(0).date);
  time_t lastX = 0;
  double lastY = 0.;
  for (const auto& point : data) {
    AddWeekends(point.date, lastX, lastY);
    lastX = x_.emplace_back(point.date);
    lastY = y_.emplace_back(point.y);
  }
  SetSize(x_.size());
}

void NewtonPolynomial::AddWeekends(time_t x, time_t lastX, double lastY) {
  if (x_.empty()) return;
  while (x > lastX + step_) {
    if (x_.empty()) break;
    lastX += step_;
    x_.emplace_back(lastX);
    y_.emplace_back(lastY);
  }
}

void NewtonPolynomial::CalculateCoefficient() {
  finite_differences_.emplace_back(y_);
  for (int i = 1; i < size_; i++) {
    auto& cur = finite_differences_.emplace_back();
    auto& prev = finite_differences_[i - 1];
    for (size_t j = 0; j < prev.size() - 1; j++) {
      cur.push_back(prev[j + 1] - prev[j]);
    }
  }
}

long double NewtonPolynomial::GetAnswer(time_t x) {
  int start = FindStart(x);
  long double result = y_[start];
  long double q = (x - x_[start]) / static_cast<long double>(step_);
  int end = std::min(degree_ + 1, size_);
  for (int i = 1; i < end; i++) {
    long double buffer = q;
    for (int j = 1; j < i; j++) buffer *= (q - j);
    buffer /= factorial(i);
    buffer *= finite_differences_[i][start];
    result += buffer;
  }
  return result;
}

int NewtonPolynomial::FindStart(time_t x) {
  if (degree_ >= size_) return 0;
  int nearestIndex = FindNearest(x);
  if (x_[nearestIndex] == x) return nearestIndex;
  int start = std::max(nearestIndex - (degree_ / 2), 0);
  if (start + degree_ > size_) start = size_ - degree_;
  return start;
}

int NewtonPolynomial::FindNearest(time_t x) {
  time_t minimum = abs(x_[0] - x);
  int nearestIndex = 0;
  for (int i = 1; i < size_ && minimum != 0; i++) {
    time_t current = abs(x_[i] - x);
    if (current < minimum) {
      minimum = current;
      nearestIndex = i;
    }
  }
  return nearestIndex;
}

}  // namespace s21
