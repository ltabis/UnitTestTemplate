/*
** EPITECH PROJECT, 2020
** WTU
** File description:
** unit test for obj
*/

#include <gtest/gtest.h>

#include "MockRng.hpp"
#include "CoinFlipper.hpp"

// https://github.com/google/googletest/blob/master/googlemock/docs/for_dummies.md

TEST(CoinFlipper, default_behaviour)
{
    MockRng rng;

    // Exceptation(s)
    EXPECT_CALL(rng, generate(testing::DoubleEq(0.0), testing::DoubleEq(1.0)))
        .Times(testing::Exactly(1))
        .WillOnce(testing::Return(0.25));

    CoinFlipper cf(rng);

    //assert
    EXPECT_EQ(Result::TAIL, cf.flipCoin());
}

TEST(CoinFlipper, multiple_call)
{
    MockRng rng;

    // Exceptation(s)
    EXPECT_CALL(rng, generate(testing::DoubleEq(0.0), testing::DoubleEq(1.0)))
        .Times(testing::Exactly(4))
        .WillOnce(testing::Return(0.0))
        .WillRepeatedly(testing::Return(1.0));

    CoinFlipper cf(rng);

    //asserts
    EXPECT_EQ(Result::TAIL, cf.flipCoin());
    EXPECT_EQ(Result::HEAD, cf.flipCoin());
    EXPECT_EQ(Result::HEAD, cf.flipCoin());
    EXPECT_EQ(Result::HEAD, cf.flipCoin());
}