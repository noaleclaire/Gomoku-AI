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
        static void turn(Board &board, std::size_t playerX = 0, std::size_t playerY = 0);

    private:
        static void _start(Board &board, std::size_t &x, std::size_t &y, std::size_t playerX, std::size_t playerY);
        static bool _attack(Board &board, std::size_t &x, std::size_t &y);
        static bool _defend(Board &board, std::size_t &x, std::size_t &y);
        static void _turn(Board &board, std::size_t &x, std::size_t &y);

        static bool yesy(Board &board, std::size_t &x, std::size_t &y);
};
