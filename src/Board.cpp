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
bool Board::isGameStarted() const
{
    return (_gameStarted);
}

/* Setter */
bool Board::setBoard(std::size_t size)
{
    if (_gameStarted) {
        BrainCommand::ERROR("unsupported size or other error");
        return (false);
    }
    for (std::size_t idx = 0; idx < size; idx++)
        _board.push_back(std::vector<CellState>(size, CellState::EMPTY));
    _gameStarted = true;
    return (true);
}

void Board::setInfo(std::string keyword, std::size_t value)
{
    _gameInfos.set(keyword, value);
}

bool Board::setPos(CellState cell, std::size_t x, std::size_t y)
{
    if (!_gameStarted)
        return false;
    if (_board.at(x).at(y) == CellState::EMPTY) {
        _board.at(x).at(y) = cell;
        return (true);
    }
    return (false);
}
