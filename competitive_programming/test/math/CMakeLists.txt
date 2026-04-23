# Binary Exponentiation
add_executable(bin-exp bin_exp.cpp)
target_include_directories(bin-exp PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(bin-exp PRIVATE GTest::gtest GTest::gtest_main)

# Miller-Rabin Prime Test
add_executable(miller-rabin miller_rabin.cpp)
target_include_directories(miller-rabin PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(miller-rabin PRIVATE GTest::gtest GTest::gtest_main)

# Euclidian Extended
add_executable(euclides-ext euclides_ext.cpp)
target_include_directories(euclides-ext PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(euclides-ext PRIVATE GTest::gtest GTest::gtest_main)

# Modular Int
add_executable(mint mint.cpp)
target_include_directories(mint PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(mint PRIVATE GTest::gtest GTest::gtest_main)

# Pollard Rho
add_executable(pollard-rho pollard_rho.cpp)
target_include_directories(pollard-rho PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(pollard-rho PRIVATE GTest::gtest GTest::gtest_main)

# FFT
add_executable(fft fft.cpp)
target_include_directories(fft PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(fft PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(bin-exp)
gtest_discover_tests(miller-rabin)
gtest_discover_tests(euclides-ext)
gtest_discover_tests(mint)
gtest_discover_tests(pollard-rho)
gtest_discover_tests(fft)