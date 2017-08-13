#include "omp_dotproduct.h"
#include "common.h"

int main(int argc, char ** argv) 
{
  return run_dotproduct(omp_dotproduct, argc, argv);
}
