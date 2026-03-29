# Disjoint Set
add_executable(disjoint-set disjoint_set.cpp)
target_include_directories(disjoint-set PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(disjoint-set PRIVATE GTest::gtest GTest::gtest_main)

# Sparse Table
add_executable(sparse-table sparse_table.cpp)
target_include_directories(sparse-table PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(sparse-table PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(disjoint-set)
gtest_discover_tests(sparse-table)