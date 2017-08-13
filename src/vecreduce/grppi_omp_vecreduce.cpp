#include "grppi_omp_vecreduce.h"
#include "common.h"

int main(int argc, char ** argv) 
{
  return run_vecreduce(grppi_omp_vecreduce, argc, argv);
}
