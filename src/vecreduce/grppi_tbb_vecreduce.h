#ifndef GRPPI_TBB_VECREDUCE_H
#define GRPPI_TBB_VECREDUCE_H

#include <vector>

#include <grppi/grppi.h>

double grppi_tbb_vecreduce(const std::vector<double> & x)
{
  grppi::parallel_execution_tbb ex;
  return grppi::reduce(ex, begin(x), end(x),0.0,
      [](double valx, double valy) { return valx + valy; });
}

#endif
