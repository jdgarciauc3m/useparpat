#ifndef GRPPI_OMP_VECREDUCE_H
#define GRPPI_OMP_VECREDUCE_H

#include <vector>

#include <grppi/grppi.h>

double grppi_omp_vecreduce(const std::vector<double> & x)
{
  grppi::parallel_execution_omp ex;
  return grppi::reduce(ex, begin(x), end(x), 0.0,
      [](double valx, double valy) { return valx + valy; });
}

#endif
