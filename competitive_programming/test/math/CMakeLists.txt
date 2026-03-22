# Binary Exponentiation
add_executable(bin-exp bin_exp.cpp)
target_include_directories(bin-exp PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(bin-exp PRIVATE GTest::gtest GTest::gtest_main)

# Miller-Rabin Prime Test
add_executable(miller-rabin miller_rabin.cpp)
target_include_directories(miller-rabin PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(miller-rabin PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(bin-exp)
gtest_discover_tests(miller-rabin)