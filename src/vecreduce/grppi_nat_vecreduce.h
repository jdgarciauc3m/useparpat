#ifndef GRPPI_NAT_VECREDUCE_H
#define GRPPI_NAT_VECREDUCE_H

#include <vector>

#include <grppi/grppi.h>

double grppi_native_vecreduce(const std::vector<double> & x)
{
  grppi::parallel_execution_native ex;
  return grppi::reduce(ex, begin(x), end(x), 0.0,
      [](double valx, double valy) { return valx + valy; });
}

#endif
