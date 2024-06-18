#project
    project(cpp-any)
    cmake_minimum_required(VERSION 2.8)
    include(../cmake-utils/cmake-utils.cmake)
    include_directories(.)

#compiler
    use_cpp11()
    
#hpp
    file(GLOB HPP ./*.hpp)
    add_custom_target(src SOURCES ${HPP})
    
#unit_tests
    file(GLOB UNIT_TESTS ./*_tests.cpp)
    add_gtest_executable(unit_tests "${UNIT_TESTS}")
    run_after_build(unit_tests)
