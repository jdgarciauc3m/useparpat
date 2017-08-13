add_executable(seq_dotproduct seq_dotproduct.cpp)

add_executable(omp_dotproduct omp_dotproduct.cpp)
set_target_properties(omp_dotproduct PROPERTIES COMPILE_FLAGS ${OpenMP_CXX_FLAGS})
set_target_properties(omp_dotproduct PROPERTIES LINK_FLAGS ${OpenMP_CXX_FLAGS})

add_executable(tbb_dotproduct tbb_dotproduct.cpp)
target_link_libraries(tbb_dotproduct ${TBB_LIBRARIES})

add_executable(grppi_seq_dotproduct grppi_seq_dotproduct.cpp)

add_executable(grppi_nat_dotproduct grppi_nat_dotproduct.cpp)
target_link_libraries(grppi_nat_dotproduct ${Boost_LIBRARIES} Threads::Threads)

add_executable(grppi_tbb_dotproduct grppi_tbb_dotproduct.cpp)
target_link_libraries(grppi_tbb_dotproduct ${Boost_LIBRARIES} ${TBB_LIBRARIES})
set_target_properties(grppi_tbb_dotproduct PROPERTIES COMPILE_FLAGS "-DGRPPI_TBB")

add_executable       (grppi_omp_dotproduct grppi_omp_dotproduct.cpp)
set_target_properties(grppi_omp_dotproduct PROPERTIES COMPILE_FLAGS "${OpenMP_CXX_FLAGS} -DGRPPI_OMP")
set_target_properties(grppi_omp_dotproduct PROPERTIES LINK_FLAGS ${OpenMP_CXX_FLAGS})
target_link_libraries(grppi_omp_dotproduct ${Boost_LIBRARIES})
