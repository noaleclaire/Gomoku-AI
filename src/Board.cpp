/*
** EPITECH PROJECT, 2022
** Board.cpp
** File description:
** Board.cpp
*/

#include "../include/Board.hpp"
#include "../include/BrainCommand.hpp"

#include <stdexcept>

#include <iostream>

Board::Board() : _gameStarted(false)
{
}

/* Getter */
std::pair<std::size_t, std::size_t> Board::getFieldCell() const
{
    std::pair<std::size_t, std::size_t> fieldCells = {0, 0};

    for (auto &it : _board) {
        for (auto &elem : it) {
            if (elem == CellState::FIRST_PLAYER)
                fieldCells.first++;
            if (elem == CellState::SECOND_PLAYER)
                fieldCells.second++;
        }
    }
    return (fieldCells);
}

bool Board::isGameStarted() const
{
    return (_gameStarted);
}

/* Setter */
void Board::resetBoard()
{
    for (auto &it : _board)
        it.clear();
    _board.clear();
    for (std::size_t idx = 0; idx < _size; idx++)
        _board.push_back(std::vector<CellState>(_size, CellState::EMPTY));
}

bool Board::setBoard(std::size_t size)
{
    if (_gameStarted) {
        BrainCommand::ERROR("unsupported size or other error");
        return (false);
    }
    for (std::size_t idx = 0; idx < size; idx++)
        _board.push_back(std::vector<CellState>(size, CellState::EMPTY));
    _gameStarted = true;
    _size = size;
    return (true);
}

void Board::setInfo(std::string keyword, std::size_t value)
{
    _gameInfos.set(keyword, value);
}

bool Board::setPos(CellState field, std::size_t x, std::size_t y)
{
    if (!_gameStarted)
        return false;
    try {
        if (_board.at(x).at(y) == CellState::EMPTY) {
            _board.at(x).at(y) = field;
            return (true);
        }
    } catch (const std::out_of_range &e) {
        return (false);
    }
    return (false);
}

void Board::printBoard()
{
    for (auto &it : _board) {
        for (auto &elem : it) {
            if (elem == CellState::EMPTY)
                std::cout << ".";
            if (elem == CellState::FIRST_PLAYER)
                std::cout << "O";
            if (elem == CellState::SECOND_PLAYER)
                std::cout << "X";
        }
        std::cout << std::endl;
    }
}
