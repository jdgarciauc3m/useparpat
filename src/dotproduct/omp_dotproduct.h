#ifndef SEQ_DOTPRODUCT_H
#define SEQ_DOTPRODUCT_H

#include <vector>

double omp_dotproduct(const std::vector<double> & x, const std::vector<double> & y)
{
  double result = 0.0;
  #pragma omp parallel for reduction(+:result)
  for (std::size_t i=0; i<x.size(); ++i) {
    result += x[i] * y[i];
  }
  return result;
}

#endif
