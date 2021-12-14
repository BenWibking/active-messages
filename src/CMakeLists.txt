include_directories(SYSTEM ${MPI_INCLUDE_PATH})

add_executable(test_am main.cpp)
target_link_libraries(test_am PUBLIC MPI::MPI_CXX)

include(CTest)
message(DEBUG "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
add_test(NAME ActiveMessages COMMAND test_am)
