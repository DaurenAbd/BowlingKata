//
// Created by daurenabd on 18. 7. 2.
//

#include <gtest/gtest.h>
#include "Bowling.h"

class BowlingTest : public ::testing::Test {
protected:
    Bowling game;

    void SetUp() override {}

    void TearDown() override {}

    void rollMultipleTimes(int n, int points) {
        for (int i = 0; i < n; ++i) {
            game.roll(points);
        }
    }

    void rollSpare() {
        rollMultipleTimes(2, 5);
    }

    void rollStrike() {
        game.roll(10);
    }
};

TEST_F(BowlingTest, testAllZeroes) { // NOLINT
    rollMultipleTimes(20, 0);
    EXPECT_EQ(game.score(), 0);
}

TEST_F(BowlingTest, testAllOnes) { // NOLINT
    rollMultipleTimes(20, 1);
    EXPECT_EQ(game.score(), 20);
}

TEST_F(BowlingTest, testSingleSpare) { // NOLINT
    rollSpare();
    game.roll(3);
    rollMultipleTimes(17, 0);
    EXPECT_EQ(game.score(), 16);
}

TEST_F(BowlingTest, testSingleStrike) { // NOLINT
    rollStrike();
    game.roll(3);
    game.roll(4);
    rollMultipleTimes(17, 0);
    EXPECT_EQ(game.score(), 24);
}

TEST_F(BowlingTest, testPerfectGame) { // NOLINT
    rollMultipleTimes(21, 10);
    EXPECT_EQ(game.score(), 300);
}