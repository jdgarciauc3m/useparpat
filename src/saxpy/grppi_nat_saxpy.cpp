#include "grppi_nat_saxpy.h"
#include "common.h"

int main(int argc, char ** argv) 
{
  return run_saxpy(grppi_native_saxpy, argc, argv);
}
