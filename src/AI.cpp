/*
** EPITECH PROJECT, 2022
** AI.cpp
** File description:
** AI.cpp
*/

#include "../include/AI.hpp"
#include "../include/define.hpp"
#include "../include/Printer.hpp"

void AI::turn(Board &board)
{
    // std::size_t x, y = 0;
    std::size_t x, y = std::rand()%DEFAULT_BOARD_SIZE - 1;

    while (!board.setPos(Board::CellState::SECOND_PLAYER, x, y))
        x, y = std::rand()%DEFAULT_BOARD_SIZE - 1;
    Printer::print(x, ",", y);
}