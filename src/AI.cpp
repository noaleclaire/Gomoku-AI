/*
** EPITECH PROJECT, 2022
** AI.cpp
** File description:
** AI.cpp
*/

#include "../include/AI.hpp"
#include "../include/BrainCommand.hpp"
#include "../include/define.hpp"
#include "../include/Printer.hpp"

void AI::turn(Board &board)
{
    // std::size_t x = 0, y = 0;
    std::size_t x = std::rand()%DEFAULT_BOARD_SIZE, y = std::rand()%DEFAULT_BOARD_SIZE;

    while (!board.setPos(Board::CellState::SECOND_PLAYER, x, y)) {
        x = std::rand()%DEFAULT_BOARD_SIZE;
        y = std::rand()%DEFAULT_BOARD_SIZE;
    }
    Printer::print(x, ",", y);
}