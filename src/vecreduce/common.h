#ifndef VECREDUCE_COMMON_H
#define VECREDUCE_COMMON_H

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
  cerr << prog << "  size" << endl;
  cerr << "\tsize: Numer of elements in vector" << endl;
}

auto get_arguments(char ** argv) {
  using namespace std;
  int size = stoi(argv[1]);
  return make_tuple(size);
}

auto generate_vector(int sz) {
  using namespace std;
  mt19937_64 gen;
  uniform_real_distribution<double> dist{-100.0, 100.0};
  vector<double> result;
  result.reserve(sz);
  generate_n(back_inserter(result), sz, 
      [&]() { return dist(gen); }
  );
  return result;
}

template <typename F>
int run_vecreduce(F fun, int argc, char ** argv) {
  using namespace std;

  cout << "vector reduction" << endl;

  if (argc!=2) {
    print_error(argv[0], "Wrong number of arguments");
    return -1;
  }

  int size;
  tie(size) = get_arguments(argv);
  cout << "  size = " << size << endl;

  auto v = generate_vector(size);

  using namespace chrono;
  auto t1 = system_clock::now();

  auto result = fun(v);  

  auto t2 = system_clock::now();

  cout << "result =" << result << endl;

  auto ellapsed = duration_cast<microseconds>(t2-t1);
  cout << "Ellapsed time: " << ellapsed.count() << " microseconds" << endl;

  return 0;
}

#endif
