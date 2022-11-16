/*
** EPITECH PROJECT, 2022
** Board.cpp
** File description:
** Board.cpp
*/

#include "../include/Board.hpp"
#include "../include/BrainCommand.hpp"

#include <stdexcept>

Board::Board() : _gameStarted(false)
{
}

/* Getter */
std::vector<std::pair<std::size_t, std::size_t>> Board::getPlayerPos(CellState field) const
{
    switch (field) {
        case CellState::FIRST_PLAYER:
            return (_playersPos.first);
            break;
        case CellState::SECOND_PLAYER:
            return (_playersPos.second);
            break;
        default: break;
    }
    throw std::invalid_argument("{ERROR} CellState field == EMPTY");
}

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

bool Board::setPos(CellState field, std::size_t x, std::size_t y)
{
    if (!_gameStarted)
        return false;
    try {
        if (_board.at(x).at(y) == CellState::EMPTY) {
            _board.at(x).at(y) = field;
            switch (field) {
                case CellState::FIRST_PLAYER:
                    _playersPos.first.push_back({x, y});
                    break;
                case CellState::SECOND_PLAYER:
                    _playersPos.second.push_back({x, y});
                    break;
                default: break;
            }
            return (true);
        }
    } catch (const std::out_of_range &e) {
        return (false);
    }
    return (false);
}
