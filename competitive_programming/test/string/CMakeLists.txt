add_executable(z-function z_function.cpp)

target_include_directories(z-function PRIVATE ${PROJECT_INCLUDE_DIR})

target_link_libraries(z-function PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(z-function)