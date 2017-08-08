#ifndef OMP_SAXPY_H
#define OMP_SAXPY_H

#include <vector>

void omp_saxpy(double a, const std::vector<double> & x, std::vector<double> & y)
{
  const std::size_t max = x.size();
  #pragma omp parallel for
  for (std::size_t i=0; i<max; ++i) {
    y[i] += a * x[i];
  }
}

#endif
