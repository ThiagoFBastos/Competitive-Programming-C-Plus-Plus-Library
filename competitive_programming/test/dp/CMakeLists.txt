add_executable(dp-edit-distance edit_distance.cpp)

target_include_directories(dp-edit-distance PRIVATE ${PROJECT_INCLUDE_DIR})

target_link_libraries(dp-edit-distance PRIVATE GTest::gtest GTest::gtest_main)

add_executable(dp-lcs longest_commom_subsequence.cpp)

target_include_directories(dp-lcs PRIVATE ${PROJECT_INCLUDE_DIR})

target_link_libraries(dp-lcs PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(dp-edit-distance)
gtest_discover_tests(dp-lcs)