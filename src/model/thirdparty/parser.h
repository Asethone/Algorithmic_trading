#pragma once

#include <iostream>
#include <string>

#include "datapoint.h"

namespace s21 {

constexpr char kComma = ',';
constexpr int kBaseYear = 1900;
constexpr int kBaseMonth = 1;

class Parser {
 public:
  Parser() = default;
  ~Parser() = default;

  void ExportData(const std::string& filename);
  const DataPoints& GetData();
  std::time_t GetBeginData();
  std::time_t GetEndData();
  double GetYMin();
  double GetYMax();
  void ClearData();
  int GetSizeFile();

  static std::vector<std::string> Strip(const std::string& str, char pattern);
  static std::time_t GetTimeTToStructTime(std::tm time);
  static std::tm GetTimeStructToOnlyYear(const std::string& str);
  static std::time_t GetTimeStructToDate(const std::string& data,
                                         const std::string& time);

 private:
  DataPoints data_;
  static std::pair<int, int> GetPairTime(const std::string& time);
  int sizeFile_;
};

}  // namespace s21
