/*
** EPITECH PROJECT, 2020
** WTU
** File description:
** CoinFlipper
*/

#include "CoinFlipper.hpp"

CoinFlipper::CoinFlipper(Rng &gen) : _generator(gen)
{ }

Result CoinFlipper::flipCoin()
{
    return (_generator.generate(0.0, 1.0) > 0.5 ? HEAD : TAIL);
}
