/*
** EPITECH PROJECT, 2022
** AI.hpp
** File description:
** AI.hpp
*/

#pragma once

#include "Board.hpp"

class AI {
    public:
        static void turn(Board &board);
        static void turn(Board &board, std::size_t playerX, std::size_t playerY);

    private:
        static void _start(Board &board, std::size_t &x, std::size_t &y, std::size_t playerX, std::size_t playerY);
};
