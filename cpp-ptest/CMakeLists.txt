#project
    project(ptest_tests)
    cmake_minimum_required(VERSION 2.8)
    include(../cmake-utils/cmake-utils.cmake)

#compiler
    use_cpp11()
    optimize_release_for_speed()
    
#target
    include_directories(./)
    file(GLOB PTEST_TESTS_SOURCE tests/*)
    add_gtest_executable(ptest_tests "${PTEST_TESTS_SOURCE}")
    run_after_build(ptest_tests)

