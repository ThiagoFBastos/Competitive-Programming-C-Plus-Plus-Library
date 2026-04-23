# Point
add_executable(point point.cpp)
target_include_directories(point PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(point PRIVATE GTest::gtest GTest::gtest_main)

# Circle
add_executable(circle circle.cpp)
target_include_directories(circle PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(circle PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(point)
gtest_discover_tests(circle)