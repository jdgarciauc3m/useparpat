#ifndef TBB_VECREDUCE_H
#define TBB_VECREDUCE_H

#include <vector>

#include <tbb/tbb.h>

double tbb_vecreduce(const std::vector<double> & v)
{
  using namespace tbb;
  return parallel_reduce(blocked_range<std::size_t>(0,v.size()),
      0.0,
      [&](const blocked_range<std::size_t> & r, double valx) {
        for (auto i=r.begin(); i!=r.end(); ++i) {
          valx += v[i];
        }
        return valx;
      },
      [](double valx, double valy) { return valx + valy; }
  );
}

#endif
