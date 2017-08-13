#include "tbb_vecreduce.h"
#include "common.h"

int main(int argc, char ** argv) 
{
  return run_vecreduce(tbb_vecreduce, argc, argv);
}
