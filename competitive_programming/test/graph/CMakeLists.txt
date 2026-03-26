add_executable(tree-center tree_center.cpp)

target_include_directories(tree-center PRIVATE ${PROJECT_INCLUDE_DIR})

target_link_libraries(tree-center PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(tree-center)