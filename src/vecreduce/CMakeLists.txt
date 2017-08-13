add_executable(seq_vecreduce seq_vecreduce.cpp)

add_executable(omp_vecreduce omp_vecreduce.cpp)
set_target_properties(omp_vecreduce PROPERTIES COMPILE_FLAGS ${OpenMP_CXX_FLAGS})
set_target_properties(omp_vecreduce PROPERTIES LINK_FLAGS ${OpenMP_CXX_FLAGS})

add_executable(tbb_vecreduce tbb_vecreduce.cpp)
target_link_libraries(tbb_vecreduce ${TBB_LIBRARIES})

add_executable(grppi_seq_vecreduce grppi_seq_vecreduce.cpp)

add_executable(grppi_nat_vecreduce grppi_nat_vecreduce.cpp)
target_link_libraries(grppi_nat_vecreduce ${Boost_LIBRARIES} Threads::Threads)

add_executable(grppi_tbb_vecreduce grppi_tbb_vecreduce.cpp)
target_link_libraries(grppi_tbb_vecreduce ${Boost_LIBRARIES} ${TBB_LIBRARIES})
set_target_properties(grppi_tbb_vecreduce PROPERTIES COMPILE_FLAGS "-DGRPPI_TBB")

add_executable       (grppi_omp_vecreduce grppi_omp_vecreduce.cpp)
set_target_properties(grppi_omp_vecreduce PROPERTIES COMPILE_FLAGS "${OpenMP_CXX_FLAGS} -DGRPPI_OMP")
set_target_properties(grppi_omp_vecreduce PROPERTIES LINK_FLAGS ${OpenMP_CXX_FLAGS})
target_link_libraries(grppi_omp_vecreduce ${Boost_LIBRARIES})
