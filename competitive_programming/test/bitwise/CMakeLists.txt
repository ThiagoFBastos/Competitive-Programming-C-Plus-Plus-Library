# Counting Bits
add_executable(counting-bits counting_bits.cpp)
target_include_directories(counting-bits PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(counting-bits PRIVATE GTest::gtest GTest::gtest_main)

# Maximum Xor Subset
add_executable(maximum-xor-subset maximum_xor_subset.cpp)
target_include_directories(maximum-xor-subset PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(maximum-xor-subset PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(counting-bits)
gtest_discover_tests(maximum-xor-subset)