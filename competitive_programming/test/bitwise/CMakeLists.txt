# Counting Bits
add_executable(counting-bits counting_bits.cpp)
target_include_directories(counting-bits PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(counting-bits PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(counting-bits)