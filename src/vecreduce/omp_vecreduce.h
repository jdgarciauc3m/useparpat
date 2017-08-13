#ifndef OMP_VECREDUCE_H
#define OMP_VECREDUCE_H

#include <vector>

double omp_vecreduce(const std::vector<double> & x)
{
  const std::size_t max = x.size();
  double result = 0.0;
  #pragma omp parallel for reduction(+:result)
  for (std::size_t i=0; i<max; ++i) {
    result += x[i];
  }
  return result;
}

#endif
