/*
** EPITECH PROJECT, 2020
** WTU
** File description:
** CoinFlipper
*/

#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "Rng.hpp"

enum Result {
    HEAD, TAIL
};

class CoinFlipper
{
    private:
        Rng &_generator;
    public:

        CoinFlipper(Rng &generator);
        ~CoinFlipper() = default;

        Result flipCoin();
};