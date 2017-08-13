#ifndef GRPPI_NATIVE_DOTPRODUCT_H
#define GRPPI_NATIVE_DOTPRODUCT_H

#include <vector>
#include <grppi/grppi.h>

double grppi_native_dotproduct(const std::vector<double> & x, const std::vector<double> & y)
{
  grppi::parallel_execution_native ex;
  return grppi::map_reduce(ex, std::begin(x), std::end(x), 0.0,
      [](double valx, double valy) { return valx * valy; },
      [](double valx, double valy) { return valx + valy; },
      std::begin(y));
}

#endif
