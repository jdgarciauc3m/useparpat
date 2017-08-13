#ifndef TBB_DOTPRODUCT_H
#define TBB_DOTPRODUCT_H

#include <vector>
#include <numeric>

#include <tbb/tbb.h>

double tbb_dotproduct(const std::vector<double> & x, const std::vector<double> & y)
{
  return tbb::parallel_reduce(
      tbb::blocked_range<std::size_t>(0,x.size()),
      0.0,
      [=](const tbb::blocked_range<std::size_t> & r, double val) {
        for (auto i=r.begin(); i!=r.end(); ++i) {
          val += x[i] * y[i];
        }
        return val;
      },
      [](double vx, double vy) { return vx + vy; }
  );
}

#endif
