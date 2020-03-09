/*
** EPITECH PROJECT, 2020
** WTU
** File description:
** Rng
*/

#pragma once

class Rng {
    public:
        
        virtual ~Rng() = default;
        virtual double generate(double min, double max) = 0;
};
