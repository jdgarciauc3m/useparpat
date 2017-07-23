#include "grppi_tbb_saxpy.h"
#include "common.h"

int main(int argc, char ** argv) 
{
  return run_saxpy(grppi_tbb_saxpy, argc, argv);
}
