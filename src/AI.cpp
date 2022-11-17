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

#include <algorithm>
#include <cmath>

void AI::turn(Board &board)
{
    std::size_t x = std::rand()%static_cast<int>(std::ceil(DEFAULT_BOARD_SIZE/3)) + static_cast<int>(std::ceil(DEFAULT_BOARD_SIZE/3));
    std::size_t y = std::rand()%static_cast<int>(std::ceil(DEFAULT_BOARD_SIZE/3)) + static_cast<int>(std::ceil(DEFAULT_BOARD_SIZE/3));
    std::srand(time(NULL));

    board.setPos(Board::CellState::SECOND_PLAYER, x, y);
    Printer::print(x, ",", y);
}

void AI::turn(Board &board, std::size_t playerX, std::size_t playerY)
{
    std::size_t x = 0, y = 0;
    std::pair<std::size_t, std::size_t> fieldCells = board.getFieldCell();

    if (fieldCells.first == 1 && fieldCells.second == 0) {
        _start(board, x, y, playerX, playerY);
    // } else {
    }
    Printer::print(x, ",", y);
    board.printBoard();
}

void AI::_start(Board &board, std::size_t &x, std::size_t &y, std::size_t playerX, std::size_t playerY)
{
    std::vector<int> possibleX = {-1, 0, 1}, possibleY = {-1, 0, 1};
    std::srand(time(NULL));

    if (playerX == 0)
        possibleX.erase(std::find(possibleX.begin(), possibleX.end(), -1));
    if (playerX == DEFAULT_BOARD_SIZE - 1)
        possibleX.erase(std::find(possibleX.begin(), possibleX.end(), 1));
    if (playerY == 0)
        possibleY.erase(std::find(possibleY.begin(), possibleY.end(), -1));
    if (playerY == DEFAULT_BOARD_SIZE - 1)
        possibleY.erase(std::find(possibleY.begin(), possibleY.end(), 1));
    x = playerX + possibleX.at(std::rand()%possibleX.size());
    y = playerY + possibleY.at(std::rand()%possibleY.size());
    while (!board.setPos(Board::CellState::SECOND_PLAYER, x, y)) {
        x = playerX + possibleX.at(std::rand()%possibleX.size());
        y = playerY + possibleY.at(std::rand()%possibleY.size());
    }
}
