# Edit Distance
add_executable(dp-edit-distance edit_distance.cpp)
target_include_directories(dp-edit-distance PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(dp-edit-distance PRIVATE GTest::gtest GTest::gtest_main)

# Longest Commom Subsequence
add_executable(dp-lcs longest_commom_subsequence.cpp)
target_include_directories(dp-lcs PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(dp-lcs PRIVATE GTest::gtest GTest::gtest_main)

# Rectangle Cutting
add_executable(dp-rectangle-cutting rectangle_cutting.cpp)
target_include_directories(dp-rectangle-cutting PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(dp-rectangle-cutting PRIVATE GTest::gtest GTest::gtest_main)

# Number of Subsequences
add_executable(dp-number-of-subsequences number_of_subsequences.cpp)
target_include_directories(dp-number-of-subsequences PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(dp-number-of-subsequences PRIVATE GTest::gtest GTest::gtest_main)

# Removing Digits
add_executable(dp-removing-digits removing_digits.cpp)
target_include_directories(dp-removing-digits PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(dp-removing-digits PRIVATE GTest::gtest GTest::gtest_main)

# Removal Game
add_executable(dp-removal-game removal_game.cpp)
target_include_directories(dp-removal-game PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(dp-removal-game PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(dp-edit-distance)
gtest_discover_tests(dp-lcs)
gtest_discover_tests(dp-rectangle-cutting)
gtest_discover_tests(dp-number-of-subsequences)
gtest_discover_tests(dp-removing-digits)
gtest_discover_tests(dp-removal-game)