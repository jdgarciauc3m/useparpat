#ifndef SEQ_VECREDUCE_H
#define SEQ_VECREDUCE_H

#include <vector>

double seq_vecreduce(const std::vector<double> & x)
{
  double result = 0.0;
  for (std::size_t i=0; i<x.size(); ++i) {
    result += x[i];
  }
  return result;
}

#endif
