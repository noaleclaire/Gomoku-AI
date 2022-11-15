/*
** EPITECH PROJECT, 2022
** Board.cpp
** File description:
** Board.cpp
*/

#include "../include/Board.hpp"
#include "../include/BrainCommand.hpp"

Board::Board() : _gameStarted(false)
{
}

/* Getter */
bool Board::empty() const
{
    return (_board.empty());
}

bool Board::isGameStarted() const
{
    return (_gameStarted);
}

/* Setter */
void Board::setBoard(std::size_t size)
{
    if (!empty()) {
        BrainCommand::ERROR("unsupported size or other error");
        return;
    }
    for (std::size_t idx = 0; idx < size; idx++)
        _board.push_back(std::vector<CellState>(size, CellState::EMPTY));
    _gameStarted = true;
}

void Board::setPos(CellState cell, std::size_t x, std::size_t y)
{
    if (!_gameStarted)
        return;
    _board.at(x).at(y) = cell;
}
