#ifndef GRPPI_SEQ_DOTPRODUCT_H
#define GRPPI_SEQ_DOTPRODUCT_H

#include <vector>
#include <grppi/grppi.h>

double grppi_seq_dotproduct(const std::vector<double> & x, const std::vector<double> & y)
{
  grppi::sequential_execution seq;
  return grppi::map_reduce(seq, std::begin(x), std::end(x), 0.0,
      [](double valx, double valy) { return valx * valy; },
      [](double valx, double valy) { return valx + valy; },
      std::begin(y));
}

#endif
