#ifndef GRPPI_OMP_SAXPY_H
#define GRPPI_OMP_SAXPY_H

#include <vector>

#include <grppi/grppi.h>

void grppi_omp_saxpy(double a, const std::vector<double> & x, std::vector<double> & y)
{
  grppi::parallel_execution_omp ex;
  grppi::map(ex, begin(x), end(x), begin(y), 
      [a](double valx, double valy) { return a * valx + valy; },
      begin(y)
  );
}

#endif
