# Z function
add_executable(z-function z_function.cpp)
target_include_directories(z-function PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(z-function PRIVATE GTest::gtest GTest::gtest_main)

# KMP
add_executable(kmp kmp.cpp)
target_include_directories(kmp PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(kmp PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(z-function)
gtest_discover_tests(kmp)
