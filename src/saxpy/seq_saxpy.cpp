#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <iterator>

void print_error(const std::string & prog, const std::string & msg) {
  using namespace std;
  cerr << prog << " : " << msg;
  cerr << endl;
  cerr << prog << "  size factor" << endl;
  cerr << "\tsize: Numer of elements in vector" << endl;
  cerr << "\tfactor: Multiplication factor" << endl;
}

auto generate_vector(int sz) {
  using namespace std;
  random_device gen;
  uniform_real_distribution<double> dist{-100.0, 100.0};
  vector<double> result;
  generate_n(back_inserter(result), sz, 
      [&]() { return dist(gen); }
  );
  return result;
}

void saxpy(double a, const std::vector<double> & x, std::vector<double> & y)
{
  for (size_t i=0; i<x.size(); ++i) {
    y[i] += a * x[i];
  }
}

void stl_saxpy(double a, const std::vector<double> & x, std::vector<double> & y)
{
  transform(begin(x), end(x), begin(y), begin(y), 
      [a](double valx, double valy) { return a * valx + valy; });
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

int main(int argc, char ** argv) 
{
  using namespace std;

  cout << "SAXPY" << endl;

  if (argc!=3) {
    print_error(argv[0], "Wrong number of arguments");
    return -1;
  }
  int size = stoi(argv[1]);
  cout << "  size = " << size << endl;
  double factor = stod(argv[2]);
  cout << "  factor = " << factor << endl;

  vector<double> x = generate_vector(size);
  cout << "Generated x[] of size " << x.size() << endl;
  vector<double> y = generate_vector(size);
  cout << "Generated x[] of size " << x.size() << endl;
  print_sample(x,y);

  using namespace chrono;
  auto t1 = system_clock::now();

  saxpy(factor, x, y);  

  auto t2 = system_clock::now();

  print_sample(x,y);

  auto ellapsed = duration_cast<microseconds>(t2-t1);
  cout << "Ellapsed time: " << ellapsed.count() << " microseconds" << endl;

  return 0;
}
