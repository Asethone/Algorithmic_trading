#pragma once

#include <vector>

#include "s21_matrix_oop.h"

namespace s21 {

class LU {
 public:
  LU() = default;
  ~LU() = default;
  std::vector<long double> GetResult(S21Matrix& A, S21Matrix& B);

 private:
  S21Matrix L_;
  S21Matrix U_;
  S21Matrix Y_;
  void GetY(S21Matrix& B);
  std::vector<long double> GetX();
  long double GetXSum(S21Matrix& X, int n);
  long double GetYSum(S21Matrix& Y, int n);
  void GetLUMatrix(S21Matrix& A);
  void SetStandartValueLU(S21Matrix& L, S21Matrix& U);
  void SetValueLU(S21Matrix& L, S21Matrix& U, S21Matrix& A);
  long double GetSum(S21Matrix& L, S21Matrix& U, int lim, int i, int j);
};

}  // namespace s21