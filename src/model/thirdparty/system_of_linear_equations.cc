#include "system_of_linear_equations.h"

namespace s21 {

std::vector<long double> matrixToVector(S21Matrix& matrix) {
  std::vector<long double> result;
  auto size = matrix.getRows();
  result.resize(size);
  for (auto i = 0; i < size; i++) {
    result[i] = matrix(i, 0);
  }
  return result;
}

std::vector<long double> LU::GetResult(S21Matrix& A, S21Matrix& B) {
  GetLUMatrix(A);
  GetY(B);
  return GetX();
}

void LU::GetY(S21Matrix& B) {
  S21Matrix Y(B);
  for (int i = 0; i < Y.getRows(); i++) {
    Y(i, 0) = B(i, 0) - GetYSum(Y, i);
  }
  Y_ = Y;
}

std::vector<long double> LU::GetX() {
  S21Matrix X(Y_);
  for (int i = X.getRows() - 1; i >= 0; i--) {
    X(i, 0) = (Y_(i, 0) - GetXSum(X, i)) / U_(i, i);
  }
  return matrixToVector(X);
}

long double LU::GetXSum(S21Matrix& X, int n) {
  long double sum = 0;
  for (int i = n + 1; i < X.getRows(); i++) {
    sum += X(i, 0) * U_(n, i);
  }
  return sum;
}

long double LU::GetYSum(S21Matrix& Y, int n) {
  long double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += Y(i, 0) * L_(n, i);
  }
  return sum;
}

void LU::GetLUMatrix(S21Matrix& A) {
  S21Matrix L(A);
  S21Matrix U(A);
  SetStandartValueLU(L, U);
  SetValueLU(L, U, A);
  L_ = L;
  U_ = U;
}

void LU::SetStandartValueLU(S21Matrix& L, S21Matrix& U) {
  for (int i = 0; i < L.getRows(); i++) {
    for (int j = 0; j < L.getCols(); j++) {
      U(i, j) = 0;
      L(i, j) = 0;
      if (i == j) {
        L(i, j) = 1;
      }
    }
  }
}

void LU::SetValueLU(S21Matrix& L, S21Matrix& U, S21Matrix& A) {
  for (int i = 0; i < L.getRows(); i++) {
    for (int j = 0; j < L.getCols(); j++) {
      if (i <= j) {
        U(i, j) = A(i, j) - GetSum(L, U, i, i, j);
      }
      if (i > j) {
        L(i, j) = (A(i, j) - GetSum(L, U, j, i, j)) / U(j, j);
      }
    }
  }
}

long double LU::GetSum(S21Matrix& L, S21Matrix& U, int lim, int i, int j) {
  long double sum = 0;
  for (int k = 0; k < lim; k++) {
    sum += L(i, k) * U(k, j);
  }
  return sum;
}

}  // namespace s21
