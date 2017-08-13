#ifndef GRPPI_SEQ_VECREDUCE_H
#define GRPPI_SEQ_VECREDUCE_H

#include <vector>

#include <grppi/grppi.h>

double grppi_seq_vecreduce(const std::vector<double> & x)
{
  grppi::sequential_execution ex;
  return grppi::reduce(ex, begin(x), end(x), 0.0,
      [](double valx, double valy) { return valx + valy; });
}

#endif
