# Tree Center
add_executable(tree-center tree_center.cpp)
target_include_directories(tree-center PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(tree-center PRIVATE GTest::gtest GTest::gtest_main)

# Ahu
add_executable(ahu ahu.cpp)
target_include_directories(ahu PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(ahu PRIVATE GTest::gtest GTest::gtest_main)

# Dijkstra
add_executable(dijkstra dijkstra.cpp)
target_include_directories(dijkstra PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(dijkstra PRIVATE GTest::gtest GTest::gtest_main)

# Centroid
add_executable(centroid centroid.cpp)
target_include_directories(centroid PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(centroid PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(tree-center)
gtest_discover_tests(ahu)
gtest_discover_tests(dijkstra)
gtest_discover_tests(centroid)