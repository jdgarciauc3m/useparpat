#ifndef SEQ_SAXPY_H
#define SEQ_SAXPY_H

#include <vector>
#include <cstddef>

void seq_saxpy(double a, const std::vector<double> & x, std::vector<double> & y)
{
  for (size_t i=0; i<x.size(); ++i) {
    y[i] += a * x[i];
  }
}

#endif
