#ifndef GRPPI_TBB_SAXPY_H
#define GRPPI_TBB_SAXPY_H

#include <vector>
#include <cstddef> // Temp workaround
#include <grppi/grppi.h>

void grppi_tbb_saxpy(double a, const std::vector<double> & x, std::vector<double> & y)
{
  grppi::parallel_execution_tbb ex;
  grppi::map(ex, begin(x), end(x), begin(y), 
      [a](double valx, double valy) { return a * valx + valy; },
      begin(y)
  );
}



#endif
