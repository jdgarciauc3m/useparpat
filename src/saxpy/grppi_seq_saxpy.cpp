#include "grppi_seq_saxpy.h"
#include "common.h"

int main(int argc, char ** argv) 
{
  return run_saxpy(grppi_seq_saxpy, argc, argv);
}
