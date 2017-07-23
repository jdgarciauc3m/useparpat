add_executable(seq_saxpy seq_saxpy.cpp)

add_executable(omp_saxpy omp_saxpy.cpp)
set_target_properties(omp_saxpy PROPERTIES COMPILE_FLAGS ${OpenMP_CXX_FLAGS})
set_target_properties(omp_saxpy PROPERTIES LINK_FLAGS ${OpenMP_CXX_FLAGS})

add_executable(grppi_saxpy grppi_saxpy.cpp)
target_link_libraries(grppi_saxpy ${Boost_LIBRARIES})
