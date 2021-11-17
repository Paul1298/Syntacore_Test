cmake_minimum_required(VERSION 3.20)
project(Syntacore_Test)

set(CMAKE_CXX_STANDARD 11)

add_executable(Syntacore_Test test-main.cpp Accumulation.cpp Accumulation.h)

enable_testing()

configure_file(input1.txt input1.txt COPYONLY)
configure_file(output1.txt output1.txt COPYONLY)
add_test(Test1 Syntacore_Test input1.txt output1.txt)

set(ACCUMULATION_TIMEOUT 1)
set_tests_properties(Test1
        PROPERTIES TIMEOUT ${ACCUMULATION_TIMEOUT})

set_tests_properties(Test1 PROPERTIES
PASS_REGULAR_EXPRESSION "TestPassed"
FAIL_REGULAR_EXPRESSION "TestFailed")