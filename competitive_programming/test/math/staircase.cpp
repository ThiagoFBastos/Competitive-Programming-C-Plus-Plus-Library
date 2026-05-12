#include <gtest/gtest.h>

#include "math/staircase.hpp"

#include <random>
#include <chrono>
#include <limits>
#include <algorithm>

TEST(Staircase, LoseStairCaseTest)
{
    const std::size_t N[] = {10, 50, 100};

    for(const auto n : N)
    {
        std::vector<int> coins;
        int coins_xor {};

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> uid(0, std::numeric_limits<int>::max());

        std::ranges::for_each(std::views::iota(std::size_t {}, n), [&](auto idx) {
            if(idx & 1)
            {
                if(idx == n - ~n % 2)
                    coins.push_back(coins_xor);
                else
                {
                    int value = uid(gen);
                    coins.push_back(value);
                    coins_xor ^= value;
                }
            }
            else
                coins.push_back(uid(gen));
        });

        bool is_first_winner = math::staircase(coins);

        EXPECT_FALSE(is_first_winner);
    }
}

TEST(Staircase, WinStairCaseTest)
{
    const std::size_t N[] = {10, 50, 100};

    for(const auto n : N)
    {
        std::vector<int> coins;
        int coins_xor {};

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> uid(1, std::numeric_limits<int>::max());

        std::ranges::for_each(std::views::iota(std::size_t {}, n), [&](auto idx) {
            if(idx & 1)
            {
                int value = uid(gen);

                if(idx == n - ~n % 2)
                    coins.push_back(coins_xor ^ value);
                else
                {
                    coins.push_back(value);
                    coins_xor ^= value;
                }
            }
            else
                coins.push_back(uid(gen));
        });

        bool is_first_winner = math::staircase(coins);

        EXPECT_TRUE(is_first_winner);
    }
}