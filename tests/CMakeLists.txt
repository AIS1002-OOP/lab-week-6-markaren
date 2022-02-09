
include_directories("${PROJECT_SOURCE_DIR}/include")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data/hello.txt" DESTINATION "${CMAKE_BINARY_DIR}/bin/data")

add_executable(exercise1 test_exercise1.cpp)
add_executable(exercise2 test_exercise2.cpp)
add_executable(exercise3 test_exercise3.cpp)
add_executable(exercise4 test_exercise4.cpp)
target_link_libraries(exercise4 PRIVATE ais1002_lib)
