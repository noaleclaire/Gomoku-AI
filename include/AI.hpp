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
        static void _turn(Board &board, std::size_t &x, std::size_t &y);
        static bool _attack(std::size_t &x, std::size_t &y, std::vector<Board::CellAttribute> line, std::size_t lineIndex);
        static bool _defend(std::size_t &defX, std::size_t &defY, std::vector<Board::CellAttribute> line, std::size_t lineIndex);
        static void _exploration(Board &board, std::size_t &x, std::size_t &y);


        static std::tuple<int, std::size_t, std::size_t> test(Board board, std::size_t i, std::size_t j);
};
