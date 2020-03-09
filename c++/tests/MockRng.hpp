/*
** EPITECH PROJECT, 2020
** WTU
** File description:
** Mock for rng
*/

#pragma once

#include <gmock/gmock.h>

#include "Rng.hpp"

class MockRng : public Rng {
    public:
        MOCK_METHOD2(generate, double(double, double));
};
