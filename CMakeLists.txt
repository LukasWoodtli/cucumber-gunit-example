cmake_minimum_required(VERSION 3.11)

project(GUnitCucumberExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)


# GUnit
FetchContent_Declare(gunit
        GIT_REPOSITORY https://github.com/cpp-testing/GUnit
        )

FetchContent_GetProperties(gunit)
if(NOT gunit_POPULATED)
    FetchContent_Populate(gunit)
    add_subdirectory(${gunit_SOURCE_DIR} ${gunit_BINARY_DIR} ${gunit_DIR})
endif()

include_directories(${GUnit_SOURCE_DIR}/include SYSTEM)
include_directories(${gmock_SOURCE_DIR}/include SYSTEM)
include_directories(${gtest_SOURCE_DIR}/include SYSTEM)


# Gherkin-C
#FetchContent_Declare(gherkin-c
#        GIT_REPOSITORY https://github.com/cucumber/gherkin-c
#        )

#FetchContent_GetProperties(gherkin-c)
#if(NOT gherkin-c_POPULATED)
#    FetchContent_Populate(gherkin-c)
#    add_subdirectory(${gherkin-c_SOURCE_DIR} ${gherkin-c_BINARY_DIR} ${gherkin-c_DIR})
#endif()

#add_library(gherkin::gherkin ALIAS gherkin)

enable_testing()

# Examples

add_executable(TestGunit test_gunit.cpp)
target_link_libraries(TestGunit gtest gtest_main)
add_test(TestGunit TestGunit)