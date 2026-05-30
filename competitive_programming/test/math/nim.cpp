#include <gtest/gtest.h>

#include "math/nim.hpp"

#include <random>
#include <chrono>
#include <limits>
#include <ranges>

TEST(Nim, LoseNimTest)
{
    const std::size_t N[] = {10, 50, 100};

    for(const auto n : N)
    {
        std::vector<int> coins;
        int coins_xor {};

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> uid(0, std::numeric_limits<int>::max());

        auto view = std::views::iota(std::size_t {}, n) | std::views::transform([&](auto idx) -> int {
            if(idx == n - 1)
                return coins_xor;
            else
            {
                auto value = uid(gen);
                coins_xor ^= value;
                return value;
            }
        });

        std::ranges::copy(view, std::back_inserter(coins));

        bool is_first_winner = math::nim(coins);

        EXPECT_FALSE(is_first_winner);
    }
}

TEST(Nim, WinNimTest)
{
    const std::size_t N[] = {10, 50, 100};

    for(const auto n : N)
    {
        std::vector<int> coins;
        int coins_xor {};

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> uid(1, std::numeric_limits<int>::max());

        auto view = std::views::iota(std::size_t {}, n) | std::views::transform([&](auto idx) {
            if(idx == n - 1)
                return coins_xor ^ uid(gen);
            else
            {
                auto value = uid(gen);
                coins_xor ^= value;
                return value;
            }
        });

        std::ranges::copy(view, std::back_inserter(coins));

        bool is_first_winner = math::nim(coins);

        EXPECT_TRUE(is_first_winner);
    }
}