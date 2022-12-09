#include "facade.h"

#include "../algorithm_traiding/cubic_spline/cubic_spline.h"
#include "../algorithm_traiding/least_squares/least_squares.h"
#include "../algorithm_traiding/newton_polynomial/newton_polynomial.h"

namespace s21 {

Facade::Facade(Parser* parser) : parser_(parser) {}

Facade::~Facade() { delete parser_; }

double Facade::GetAnswer(int size, time_t timeValue, int days) {
  ValidatorSize(size);
  CalculateCoefficient(GetDataBegin(), size);
  ValidatorTime(timeValue, days);
  return algorithmTraiding_->GetAnswer(timeValue);
}

DataPoints Facade::GetDataPoints(int step, int size, int days) {
  ValidatorSize(size);
  ValidatorStep(step);
  CalculateCoefficient(GetDataBegin(), size);
  return algorithmTraiding_->GetDataPoints(step, parser_->GetBeginData(),
                                           GetEndData(days));
}

void Facade::InitializingAlgorithmTraiding(
    TypeAlgorithmTraiding typeAlgorithmTraiding) {
  switch (typeAlgorithmTraiding) {
    case kCubicSpline:
      algorithmTraiding_ = std::make_unique<CubicSpline>();
      break;
    case kNewtonPolynomial:
      algorithmTraiding_ = std::make_unique<NewtonPolynomial>();
      break;
    case kLeastSquares:
      algorithmTraiding_ = std::make_unique<LeastSquares>();
      break;
  }
}

void Facade::ExportData(const std::string& filename) {
  parser_->ExportData(filename);
}

const DataPoints& Facade::GetDataBegin() {
  ValidatorData(parser_->GetData());
  return parser_->GetData();
}

void Facade::ClearData() { parser_->ClearData(); }

void Facade::CalculateCoefficient(const DataPoints& data, int size) {
  algorithmTraiding_->SetDataPoints(data);
  algorithmTraiding_->SetPolymomialDegree(size);
  algorithmTraiding_->CalculateCoefficient();
}

void Facade::ClearAlgorithmData() { algorithmTraiding_->ClearFields(); }

MinMaxData Facade::GetMinMaxData() {
  MinMaxData minMaxData;
  minMaxData.dataMin = parser_->GetBeginData();
  minMaxData.dataMax = parser_->GetEndData();
  minMaxData.yMin = parser_->GetYMin();
  minMaxData.yMax = parser_->GetYMax();
  return minMaxData;
}

void Facade::ValidatorStep(int step) {
  if (step < parser_->GetSizeFile()) {
    throw std::invalid_argument(
        "Error: the count points should be in more then count points is file");
  }
}

void Facade::ValidatorSize(int size) {
  if (size < 1 || size > 16) {
    throw std::invalid_argument(
        "Error: the degree of the polynomial should be in the range from 1 to "
        "16");
  }
}

void Facade::ValidatorData(const DataPoints& data) {
  if (data.empty()) {
    throw std::invalid_argument("Error: upload a file");
  }
}

void Facade::ValidatorTime(time_t timeValue, int days) {
  if (parser_->GetBeginData() > timeValue || GetEndData(days) < timeValue) {
    throw std::invalid_argument("Error: the value is out of range time");
  }
}

time_t Facade::GetEndData(int days) {
  return parser_->GetEndData() + days * kSecInDay;
}

std::string Facade::GetAlgorithmName() {
  auto* alg = algorithmTraiding_.get();
  if (dynamic_cast<CubicSpline*>(alg))
    return "Cubic Spline";
  else if (dynamic_cast<NewtonPolynomial*>(alg))
    return "Newton Polynomial | Degree: ";
  else if (dynamic_cast<LeastSquares*>(alg))
    return "Least Squares | Degree: ";
  return "";
}

}  // namespace s21
