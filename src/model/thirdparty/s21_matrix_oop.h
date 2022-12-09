#pragma once

#include <iostream>

class S21Matrix {
 private:
  int _rows, _cols;
  double** _matrix;

 public:
  // Constructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  // Destructor
  ~S21Matrix();
  // Methods
  bool eq_matrix(const S21Matrix& other) const;
  void sum_matrix(const S21Matrix& other);
  void sub_matrix(const S21Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& other);
  S21Matrix transpose() const;
  S21Matrix calc_complements() const;
  double determinant() const;
  S21Matrix inverse_matrix() const;
  // Accessors
  int getRows() const;
  int getCols() const;
  // Operators
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  friend S21Matrix operator*(const double num, const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  const double& operator()(int i, int j) const;
  double& operator()(int i, int j);
  // Other
  void print();

 private:
  inline bool isEqualSizes(const S21Matrix& other) const;
  inline bool isSquareMatrix() const;
  void newMatrix(int rows, int cols);
  void destroyMatrix();
  void copyMatrix(double** other_matrix);
  S21Matrix getMinor(int line, int col) const;
};

S21Matrix operator*(double num, const S21Matrix& other);
