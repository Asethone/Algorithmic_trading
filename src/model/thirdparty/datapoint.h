#include <ctime>
#include <vector>

struct DataPoint {
  long double y;
  std::time_t date;

  DataPoint(double y_, std::time_t date_) : y(y_), date(date_) {}
};

using DataPoints = std::vector<DataPoint>;