#include "algorithm_traiding.h"

#include <cmath>

namespace s21 {

DataPoints AlgorithmTraiding::GetDataPoints(int step, std::time_t minData,
                                            std::time_t maxData) {
  std::time_t divisionPrice = (maxData - minData) / step;
  DataPoints result;
  for (auto i = minData; i <= maxData; i += divisionPrice) {
    result.emplace_back(GetAnswer(i), i);
  }
  if (!result.empty() && result.at(result.size() - 1).date != maxData)
    result.emplace_back(GetAnswer(maxData), maxData);
  return result;
}

}  // namespace s21
