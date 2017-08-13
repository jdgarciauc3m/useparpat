#ifndef GRPPI_TBB_DOTPRODUCT_H
#define GRPPI_TBB_DOTPRODUCT_H

#include <vector>
#include <grppi/grppi.h>

double grppi_tbb_dotproduct(const std::vector<double> & x, const std::vector<double> & y)
{
  grppi::parallel_execution_tbb ex;
  return grppi::map_reduce(ex, std::begin(x), std::end(x), 0.0,
      [](double valx, double valy) { return valx * valy; },
      [](double valx, double valy) { return valx + valy; },
      std::begin(y));
}

#endif
