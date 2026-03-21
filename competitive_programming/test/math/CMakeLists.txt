add_executable(bin-exp bin_exp.cpp)

target_include_directories(bin-exp PRIVATE ${PROJECT_INCLUDE_DIR})

target_link_libraries(bin-exp PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(bin-exp)