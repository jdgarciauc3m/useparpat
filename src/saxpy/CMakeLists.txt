add_executable(seq_saxpy seq_saxpy.cpp)

add_executable(omp_saxpy omp_saxpy.cpp)
set_target_properties(omp_saxpy PROPERTIES COMPILE_FLAGS ${OpenMP_CXX_FLAGS})
set_target_properties(omp_saxpy PROPERTIES LINK_FLAGS ${OpenMP_CXX_FLAGS})

add_executable(tbb_saxpy tbb_saxpy.cpp)
target_link_libraries(tbb_saxpy ${TBB_LIBRARIES})

add_executable(grppi_seq_saxpy grppi_seq_saxpy.cpp)
target_link_libraries(grppi_seq_saxpy ${Boost_LIBRARIES})

add_executable(grppi_nat_saxpy grppi_nat_saxpy.cpp)
target_link_libraries(grppi_nat_saxpy ${Boost_LIBRARIES})

add_executable(grppi_tbb_saxpy grppi_tbb_saxpy.cpp)
target_link_libraries(grppi_tbb_saxpy ${Boost_LIBRARIES} ${TBB_LIBRARIES})
set_target_properties(grppi_tbb_saxpy PROPERTIES COMPILE_FLAGS "-DGRPPI_TBB")

add_executable(grppi_omp_saxpy grppi_omp_saxpy.cpp)
target_link_libraries(grppi_omp_saxpy ${Boost_LIBRARIES})
set_target_properties(grppi_omp_saxpy PROPERTIES COMPILE_FLAGS ${OpenMP_CXX_FLAGS})
set_target_properties(grppi_omp_saxpy PROPERTIES LINK_FLAGS ${OpenMP_CXX_FLAGS})
set_target_properties(grppi_omp_saxpy PROPERTIES COMPILE_FLAGS "-DGRPPI_OMP")
