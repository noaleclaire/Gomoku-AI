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
    std::size_t x = std::rand()%DEFAULT_BOARD_SIZE - 1, y = std::rand()%DEFAULT_BOARD_SIZE - 1;

    Printer::print("DEBUG ", "IA: x=", x, ", y=", y);
    while (!board.setPos(Board::CellState::SECOND_PLAYER, x, y)) {
        x = std::rand()%DEFAULT_BOARD_SIZE - 1;
        y = std::rand()%DEFAULT_BOARD_SIZE - 1;
        Printer::print("DEBUG ", "Boucle IA: x=", x, ", y=", y);
    }
    Printer::print(x, ",", y);
}