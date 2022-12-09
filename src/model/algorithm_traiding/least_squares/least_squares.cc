#include "least_squares.h"

#include <cmath>

namespace s21 {

void LeastSquares::SetDataPoints(const DataPoints& data) { data_ = data; }

long double LeastSquares::SumOfDegree(int degree, bool checkY) {
  long double sumResult = 0;
  for (auto& i : data_) {
    if (checkY) {
      sumResult += pow(i.date, degree) * i.y;
    } else {
      sumResult += pow(i.date, degree);
    }
  }
  return sumResult;
}

S21Matrix LeastSquares::GetDependentMatrix() {
  S21Matrix dependent(sizePolinom_, sizePolinom_);
  for (auto i = 0; i < sizePolinom_; i++) {
    for (auto j = 0; j < sizePolinom_; j++) {
      dependent(i, j) = SumOfDegree(i + j, false);
    }
  }
  return dependent;
}

S21Matrix LeastSquares::GetExplainedAnswer() {
  S21Matrix explained(sizePolinom_, 1);
  for (auto i = 0; i < sizePolinom_; i++) {
    explained(i, 0) = SumOfDegree(i, true);
  }
  return explained;
}

void LeastSquares::CalculateCoefficient() {
  S21Matrix dependent = GetDependentMatrix();
  S21Matrix explained = GetExplainedAnswer();
  coefficient_ = LU_.GetResult(dependent, explained);
}

void LeastSquares::SetPolymomialDegree(int size) { sizePolinom_ = size + 1; }

long double LeastSquares::GetAnswer(std::time_t x) {
  long double answer = 0;
  for (auto i = 0; i < sizePolinom_; i++) {
    answer += coefficient_[i] * pow(x, i);
  }
  return answer;
}

void LeastSquares::ClearFields() {
  coefficient_.clear();
  data_.clear();
}

}  // namespace s21