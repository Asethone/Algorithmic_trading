#include "s21_matrix_oop.h"

#include <cmath>
#include <stdexcept>

// Constructors
S21Matrix::S21Matrix() { newMatrix(3, 3); }

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows > 0 && cols > 0) {
    newMatrix(rows, cols);
  } else {
    throw std::out_of_range(
        "Incorrect input, matrix should have both sizes > 0");
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other._rows, other._cols) {
  copyMatrix(other._matrix);
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  _rows = other._rows;
  _cols = other._cols;
  _matrix = other._matrix;
  other._matrix = nullptr;
}

// Destructor
S21Matrix::~S21Matrix() {
  if (_matrix) {
    destroyMatrix();
  }
}

// Methods
bool S21Matrix::eq_matrix(const S21Matrix& other) const {
  bool result = true;
  if (isEqualSizes(other)) {
    for (int i = 0; i < _rows && result; i++) {
      for (int j = 0; j < _cols && result; j++) {
        if (fabs(_matrix[i][j] - other._matrix[i][j]) > 1e-7) result = false;
      }
    }
  } else {
    result = false;
  }
  return result;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (isEqualSizes(other)) {
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        _matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
      }
    }
  } else {
    throw std::invalid_argument(
        "Invalid argument, matrices must be equal sizes");
  }
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
  if (isEqualSizes(other)) {
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        _matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
      }
    }
  } else {
    throw std::invalid_argument(
        "Invalid argument, matrices must be equal sizes");
  }
}

void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] *= num;
    }
  }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
  if (_cols == other._rows) {
    S21Matrix result(_rows, other._cols);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < other._cols; j++) {
        for (int c = 0; c < _cols; c++)
          result._matrix[i][j] += _matrix[i][c] * other._matrix[c][j];
      }
    }
    *this = result;
  } else {
    throw std::invalid_argument(
        "Invalid argument, number of cols of the first matrix must be equal to "
        "number of rows of the "
        "second matrix");
  }
}

S21Matrix S21Matrix::transpose() const {
  S21Matrix result(_cols, _rows);
  for (int i = 0; i < _rows; i++)
    for (int j = 0; j < _cols; j++) result._matrix[j][i] = _matrix[i][j];
  return result;
}

double S21Matrix::determinant() const {
  if (isSquareMatrix()) {
    double result = _matrix[0][0];
    if (_rows > 1 && _cols > 1) {
      result = 0.0;
      for (int j = 0; j < _cols; j++) {
        S21Matrix minor = getMinor(0, j);
        if (j % 2 == 0)
          result += _matrix[0][j] * minor.determinant();
        else
          result -= _matrix[0][j] * minor.determinant();
      }
    }
    return result;
  } else {
    throw std::invalid_argument("Invalid argument, matrix must be square");
  }
}

S21Matrix S21Matrix::calc_complements() const {
  if (isSquareMatrix() && _rows > 1) {
    S21Matrix result(_rows, _cols);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        S21Matrix minor = getMinor(i, j);
        if ((i + j) % 2 == 0) {
          result._matrix[i][j] = minor.determinant();
        } else {
          result._matrix[i][j] = -minor.determinant();
        }
      }
    }
    return result;
  } else {
    throw std::invalid_argument(
        "Invalid argument, matrix must be square and > 1 size");
  }
}

S21Matrix S21Matrix::inverse_matrix() const {
  if (fabs(determinant()) > 1e-7) {
    S21Matrix result(1, 1);
    if (_rows > 1) {
      S21Matrix complem = calc_complements();
      S21Matrix buffer = complem.transpose();
      buffer.mul_number(1.0 / determinant());
      result = buffer;
    } else {
      result._matrix[0][0] = 1.0 / _matrix[0][0];
    }
    return result;
  } else {
    throw std::invalid_argument(
        "Invalid argument, matrix determinant equals zero");
  }
}

// Accessors
int S21Matrix::getRows() const { return _rows; }

int S21Matrix::getCols() const { return _cols; }

// Operators
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result = *this;
  result.sum_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result = *this;
  result.sub_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result = *this;
  result.mul_matrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result = *this;
  result.mul_number(num);
  return result;
}

S21Matrix operator*(double num, const S21Matrix& other) {
  S21Matrix result = other;
  result.mul_number(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return eq_matrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    destroyMatrix();
    newMatrix(other._rows, other._cols);
    copyMatrix(other._matrix);
  }
  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  sum_matrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  sub_matrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  mul_matrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  mul_number(num);
  return *this;
}

const double& S21Matrix::operator()(int i, int j) const {
  if (i >= 0 && i < _rows && j >= 0 && j < _cols) {
    return _matrix[i][j];
  } else {
    throw std::out_of_range("Incorrect input, index out of matrix sizes");
  }
}

double& S21Matrix::operator()(int i, int j) {
  if (i >= 0 && i < _rows && j >= 0 && j < _cols) {
    return _matrix[i][j];
  } else {
    throw std::out_of_range("Incorrect input, index out of matrix sizes");
  }
}

// Other
inline bool S21Matrix::isEqualSizes(const S21Matrix& other) const {
  return (_rows == other._rows && _cols == other._cols);
}

inline bool S21Matrix::isSquareMatrix() const { return (_rows == _cols); }

void S21Matrix::newMatrix(int rows, int cols) {
  _rows = rows;
  _cols = cols;
  _matrix = new double*[_rows];
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[_cols]();
  }
}

void S21Matrix::destroyMatrix() {
  for (int i = 0; i < _rows; i++) {
    delete[] _matrix[i];
  }
  delete[] _matrix;
}

void S21Matrix::copyMatrix(double** other_matrix) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = other_matrix[i][j];
    }
  }
}

S21Matrix S21Matrix::getMinor(int line, int col) const {
  S21Matrix minor(_rows - 1, _cols - 1);
  int l = 0;
  for (int i = 0; i < _rows; i++) {
    int c = 0;
    for (int j = 0; j < _cols && i != line; j++) {
      if (j != col) {
        minor._matrix[l][c] = _matrix[i][j];
        c++;
      }
    }
    if (i != line) l++;
  }
  return minor;
}

void S21Matrix::print() {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      std::cout << _matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}
