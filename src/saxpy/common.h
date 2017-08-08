#ifndef SAXPY_COMMON_H
#define SAXPY_COMMON_H

#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <tuple>
#include <chrono>
#include <algorithm>
#include <iterator>

void print_error(const std::string & prog, const std::string & msg) {
  using namespace std;
  cerr << prog << " : " << msg;
  cerr << endl;
  cerr << prog << "  size factor" << endl;
  cerr << "\tsize: Numer of elements in vector" << endl;
  cerr << "\tfactor: Multiplication factor" << endl;
}

std::tuple<int,double> get_arguments(char ** argv) {
  using namespace std;
  int size = stoi(argv[1]);
  double factor = stod(argv[2]);
  return make_tuple(size,factor);
}

auto generate_vector(int sz) {
  using namespace std;
  random_device gen;
  uniform_real_distribution<double> dist{-100.0, 100.0};
  vector<double> result;
  result.reserve(sz);
  generate_n(back_inserter(result), sz, 
      [&]() { return dist(gen); }
  );
  return result;
}

void print_sample(const std::vector<double> & x, 
                  const std::vector<double> & y)
{
  using namespace std;
  cout << "X = ";
  copy(begin(x), begin(x)+5, ostream_iterator<double>(cout, " , "));
  cout << "...\n";
  cout << "Y = ";
  copy(begin(y), begin(y)+5, ostream_iterator<double>(cout, " , "));
  cout << "...\n";
}

template <typename F>
int run_saxpy(F saxpy_fun, int argc, char ** argv) {
  using namespace std;

  cout << "SAXPY" << endl;

  if (argc!=3) {
    print_error(argv[0], "Wrong number of arguments");
    return -1;
  }

  int size;
  double factor;
  tie(size,factor) = get_arguments(argv);
  cout << "  size = " << size << endl;
  cout << "  factor = " << factor << endl;

  auto x = generate_vector(size);
  auto y = generate_vector(size);

  cout << "x[0]=" << x[0] << endl;
  cout << "y[0]=" << y[0] << endl;
  cout << "x[" << x.size()-1 << "]=" << x[x.size()-1] << endl;
  cout << "y[" << y.size()-1 << "]=" << y[y.size()-1] << endl;

  using namespace chrono;
  auto t1 = system_clock::now();

  saxpy_fun(factor, x, y);  

  auto t2 = system_clock::now();

  cout << "x[0]=" << x[0] << endl;
  cout << "y[0]=" << y[0] << endl;
  cout << "x[" << x.size()-1 << "]=" << x[x.size()-1] << endl;
  cout << "y[" << y.size()-1 << "]=" << y[y.size()-1] << endl;

  auto ellapsed = duration_cast<microseconds>(t2-t1);
  cout << "Ellapsed time: " << ellapsed.count() << " microseconds" << endl;

  return 0;
}

#endif
