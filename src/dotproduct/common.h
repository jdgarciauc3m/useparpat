#ifndef DOTPRODUCT_COMMON_H
#define DOTPRODUCT_COMMON_H

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

template <typename RG>
auto generate_vector(RG & gen, int sz) {
  using namespace std;
  uniform_real_distribution<double> dist{-100.0, 100.0};
  vector<double> result;
  result.reserve(sz);
  generate_n(back_inserter(result), sz, 
      [&]() { return dist(gen); }
  );
  return result;
}

template <typename F>
int run_dotproduct(F dotproduct_fun, int argc, char ** argv) {
  using namespace std;

  cout << "DOTPRODUCT" << endl;

  if (argc!=2) {
    print_error(argv[0], "Wrong number of arguments");
    return -1;
  }

  int size;
  tie(size) = get_arguments(argv);
  cout << "  size = " << size << endl;

  mt19937_64 ran_gen;
  auto x = generate_vector(ran_gen, size);
  auto y = generate_vector(ran_gen, size);

  using namespace chrono;
  auto t1 = system_clock::now();

  auto result = dotproduct_fun(x, y);  

  auto t2 = system_clock::now();

  cout << "Result= " << result << endl;

  auto ellapsed = duration_cast<microseconds>(t2-t1);
  cout << "Ellapsed time: " << ellapsed.count() << " microseconds" << endl;

  return 0;
}

#endif
