#include "parser.h"

#include <algorithm>
#include <fstream>
#include <sstream>

namespace s21 {

std::vector<std::string> Parser::Strip(const std::string& str, char pattern) {
  std::vector<std::string> listStr;
  std::istringstream iss(str);
  std::string token;
  while (std::getline(iss, token, pattern)) {
    listStr.push_back(token);
  }
  return listStr;
}

std::tm Parser::GetTimeStructToOnlyYear(const std::string& str) {
  auto time = Strip(str, '-');
  if (time.size() != 3) {
    throw std::invalid_argument(
        "Error: the string must be in the format %Y-%m-%d");
  }
  std::tm date{};
  date.tm_year = std::stoi(time[0]) - 1900;
  date.tm_mon = std::stoi(time[1]) - 1;
  date.tm_mday = std::stoi(time[2]);
  return date;
}

std::pair<int, int> Parser::GetPairTime(const std::string& str) {
  auto time = Strip(str, ':');
  if (time.size() != 2) {
    throw std::invalid_argument(
        "Error: the string must be in the format %h %m");
  }
  return {std::stoi(time[0]), std::stoi(time[1])};
}

void Parser::ExportData(const std::string& filename) {
  std::string line;
  std::ifstream in(filename);
  sizeFile_ = 0;
  if (!in.is_open()) {
    throw std::invalid_argument("Error:" + filename + " dont exist!");
  }
  while (getline(in, line)) {
    if (line == "Date,Close") {
      continue;
    }
    auto listStr = Strip(line, kComma);
    if (listStr.size() != 2) {
      throw std::invalid_argument("Error: invalid file str");
    }
    sizeFile_++;
    auto time =
        Parser::GetTimeTToStructTime(GetTimeStructToOnlyYear(listStr[0]));
    data_.emplace_back(std::stod(listStr[1]), time);
  }
  if (sizeFile_ < 2) {
    throw std::invalid_argument("Error:" + filename +
                                "contains a small number of lines");
  }
}

const std::vector<DataPoint>& Parser::GetData() { return data_; }

std::time_t Parser::GetTimeStructToDate(const std::string& data,
                                        const std::string& time) {
  std::tm data_struct = GetTimeStructToOnlyYear(data);
  auto time_pair = GetPairTime(time);
  data_struct.tm_hour = time_pair.first;
  data_struct.tm_min = time_pair.second;
  return std::mktime(&data_struct);
}

std::time_t Parser::GetBeginData() { return data_[0].date; }

double Parser::GetYMin() {
  auto result = std::min_element(
      data_.begin(), data_.end(),
      [](DataPoint first, DataPoint second) { return first.y < second.y; });
  return data_[std::distance(data_.begin(), result)].y;
}

double Parser::GetYMax() {
  auto result = std::min_element(
      data_.begin(), data_.end(),
      [](DataPoint first, DataPoint second) { return first.y > second.y; });
  return data_[std::distance(data_.begin(), result)].y;
}

std::time_t Parser::GetEndData() { return data_[data_.size() - 1].date; }

std::time_t Parser::GetTimeTToStructTime(std::tm time) {
  return std::mktime(&time);
}

void Parser::ClearData() {
  data_.clear();
  sizeFile_ = 0;
}

int Parser::GetSizeFile() { return sizeFile_; }

}  // namespace s21
