#ifndef OMP_SAXPY_H
#define OMP_SAXPY_H

#include <vector>
#include <cstddef>

void omp_saxpy(double a, const std::vector<double> & x, std::vector<double> & y)
{
  #pragma omp parallel for
  for (size_t i=0; i<x.size(); ++i) {
    y[i] += a * x[i];
  }
}

#endif
