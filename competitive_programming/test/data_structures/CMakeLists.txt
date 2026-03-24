# Disjoint Set
add_executable(disjoint-set disjoint_set.cpp)
target_include_directories(disjoint-set PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(disjoint-set PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(disjoint-set)