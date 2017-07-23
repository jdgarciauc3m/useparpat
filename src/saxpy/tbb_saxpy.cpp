#include "tbb_saxpy.h"
#include "common.h"

int main(int argc, char ** argv) 
{
  return run_saxpy(tbb_saxpy, argc, argv);
}
