#include "grppi_omp_saxpy.h"
#include "common.h"

int main(int argc, char ** argv) 
{
  return run_saxpy(grppi_omp_saxpy, argc, argv);
}
