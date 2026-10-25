cmake_minimum_required(VERSION 3.14)
project(LR4 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_library(lr4_core STATIC ${SOURCES})
target_include_directories(lr4_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(lr4_core PRIVATE --coverage -g -O0)
endif()

add_executable(LR4 src/main.cpp)
target_link_libraries(LR4 PRIVATE lr4_core)
target_link_options(LR4 PRIVATE -mconsole)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_link_options(LR4 PRIVATE --coverage)
endif()

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

if(TEST_SOURCES)
    add_executable(LR4_tests ${TEST_SOURCES})
    
    target_link_libraries(LR4_tests PRIVATE 
        lr4_core
        GTest::gtest 
        GTest::gtest_main
    )
    
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(LR4_tests PRIVATE --coverage -g -O0)
        target_link_options(LR4_tests PRIVATE --coverage)
    endif()

    include(GoogleTest)
    gtest_discover_tests(LR4_tests)
endif()
