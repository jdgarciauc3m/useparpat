#ifndef TBB_SAXPY_H
#define TBB_SAXPY_H

#include <vector>

#include <tbb/tbb.h>

void tbb_saxpy(double a, const std::vector<double> & x, std::vector<double> & y)
{
  using namespace tbb;
  parallel_for(blocked_range<std::size_t>(0,x.size()),
      [&](blocked_range<std::size_t> r) {
        for (auto i=r.begin(); i!=r.end(); ++i) {
          y[i] += a * x[i];
        }
      }
  );
}

#endif
