/*
** EPITECH PROJECT, 2022
** Board.cpp
** File description:
** Board.cpp
*/

#include "Board.hpp"
#include "BrainCommand.hpp"
#include "define.hpp"

#include <stdexcept>

#include <iostream>

std::vector<std::vector<Board::CellState>> Board::attackPattern = {
        {Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::EMPTY},
        {Board::CellState::EMPTY, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER},
        {Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::EMPTY, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER},
        {Board::CellState::SECOND_PLAYER, Board::CellState::EMPTY, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER},
        {Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::SECOND_PLAYER, Board::CellState::EMPTY, Board::CellState::SECOND_PLAYER}
    };

std::vector<std::vector<Board::CellState>> Board::defensePattern = {
        {Board::CellState::EMPTY, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::EMPTY},
        {Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::EMPTY, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER},
        {Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::EMPTY, Board::CellState::FIRST_PLAYER, Board::CellState::EMPTY},
        {Board::CellState::EMPTY, Board::CellState::FIRST_PLAYER, Board::CellState::EMPTY, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER},
        {Board::CellState::FIRST_PLAYER, Board::CellState::EMPTY, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER},
        {Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::EMPTY, Board::CellState::FIRST_PLAYER},
        {Board::CellState::EMPTY, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER},
        {Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::FIRST_PLAYER, Board::CellState::EMPTY}
    };

std::vector<std::pair<std::vector<Board::CellState>, std::size_t>> Board::scorePattern = {
        {{Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER}, 1},// x . . . x
        {{Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::EMPTY}, 2},// x . . x .
        {{Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER}, 2},// . x . . x
        {{Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY}, 3},// x . x . .
        {{Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::PLAYER}, 3},// . . x . x
        {{Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::EMPTY}, 3},// . x . x .
        {{Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::EMPTY}, 4},// x x . . .
        {{Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER}, 4},// . . . x x
        {{Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY}, 4},// . x x . .
        {{Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY}, 4},// . . x x .
        {{Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::PLAYER}, 6},// x . x . x
        {{Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY}, 7},// x x x . .
        {{Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER}, 7},// . . x x x
        {{Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY}, 7},// . x x x .
        {{Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER}, 8},// x x . . x
        {{Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER}, 8},// x . . x x
        {{Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER}, 100},// x x . x x
        {{Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY}, 100},// x x x x .
        {{Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER}, 100},// . x x x x
        {{Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::PLAYER}, 100},// x x x . x
        {{Board::CellState::PLAYER, Board::CellState::EMPTY, Board::CellState::PLAYER, Board::CellState::PLAYER, Board::CellState::PLAYER}, 100}// x . x x x
    };

Board::Board() : _nbField({0, 0}), _gameStarted(false)
{
}

/* Getter */
int Board::evaluation()
{
    int score = 0;
    std::vector<CellAttribute> line = {};
    std::vector<Direction> directions = {Direction::HORIZONTAL, Direction::VERTICAL,
                                                Direction::LEFTTORIGHT, Direction::RIGHTTOLEFT};

    for (std::size_t i = 0; i < _predictionBoard.size(); i++) {
        for (std::size_t j = 0; j < _predictionBoard.at(i).size(); j++) {
            for (auto &dir : directions) {
                line = getLineWithStartCell(dir, j, i);
                if (line.size() < 5)
                    continue;
                for (auto &pattern : scorePattern) {
                    for (std::size_t state = static_cast<std::size_t>(CellState::FIRST_PLAYER); state <= static_cast<std::size_t>(CellState::SECOND_PLAYER); state++) {
                        for (std::size_t ptnIndex = 0; ptnIndex < 5; ptnIndex++) {
                            if ((pattern.first.at(ptnIndex) == CellState::PLAYER && line.at(ptnIndex).field != static_cast<CellState>(state)) ||
                                (pattern.first.at(ptnIndex) != CellState::PLAYER && line.at(ptnIndex).field != pattern.first.at(ptnIndex)))
                                break;
                            if (ptnIndex == 4 && static_cast<CellState>(state) == CellState::FIRST_PLAYER)
                                score -= pattern.second;
                            if (ptnIndex == 4 && static_cast<CellState>(state) == CellState::SECOND_PLAYER)
                                score += pattern.second;
                        }
                    }
                }
            }
        }
    }
    return (score);
}

std::vector<std::vector<Board::CellState>> Board::getBoard() const
{
    return (_board);
}

std::pair<std::size_t, std::size_t> Board::getFieldCell() const
{
    return (_nbField);
}

std::vector<Board::CellAttribute> Board::getLineWithMidCell(Direction direction, std::size_t midCellX, std::size_t midCellY)
{
    std::vector<CellAttribute> line = {};
    std::pair<std::size_t, std::size_t> xAmplitude = {0, 0};
    std::pair<std::size_t, std::size_t> yAmplitude = {0, 0};
    int xStep = 0, yStep = 0;
    bool lineFull = false;

    switch (direction) {
        case Direction::VERTICAL:
            if (static_cast<int>(midCellX) - 4 >= 0)
                xAmplitude.first = midCellX - 4;
            if (midCellX + 4 < DEFAULT_BOARD_SIZE)
                xAmplitude.second = midCellX + 4;
            else
                xAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            yAmplitude = {midCellY, midCellY};
            xStep = 1;
            break;
        case Direction::HORIZONTAL:
            if (static_cast<int>(midCellY) - 4 >= 0)
                yAmplitude.first = midCellY - 4;
            if (midCellY + 4 < DEFAULT_BOARD_SIZE)
                yAmplitude.second = midCellY + 4;
            else
                yAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            xAmplitude = {midCellX, midCellX};
            yStep = 1;
            break;
        case Direction::RIGHTTOLEFT:
            if (static_cast<int>(midCellX) - 4 >= 0)
                xAmplitude.second = midCellX - 4;
            if (midCellX + 4 < DEFAULT_BOARD_SIZE)
                xAmplitude.first = midCellX + 4;
            else
                xAmplitude.first = DEFAULT_BOARD_SIZE - 1;
            if (static_cast<int>(midCellY) - 4 >= 0)
                yAmplitude.first = midCellY - 4;
            if (midCellY + 4 < DEFAULT_BOARD_SIZE)
                yAmplitude.second = midCellY + 4;
            else
                yAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            xStep = -1;
            yStep = 1;
            break;
        case Direction::LEFTTORIGHT:
            if (static_cast<int>(midCellX) - 4 >= 0)
                xAmplitude.first = midCellX - 4;
            if (midCellX + 4 < DEFAULT_BOARD_SIZE)
                xAmplitude.second = midCellX + 4;
            else
                xAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            if (static_cast<int>(midCellY) - 4 >= 0)
                yAmplitude.first = midCellY - 4;
            if (midCellY + 4 < DEFAULT_BOARD_SIZE)
                yAmplitude.second = midCellY + 4;
            else
                yAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            xStep = 1;
            yStep = 1;
            break;
        default:
            break;
    }
    for (std::size_t x = xAmplitude.first, y = yAmplitude.first; !lineFull; x += xStep, y += yStep) {
        if ((x == xAmplitude.second && xStep != 0) || (y == yAmplitude.second && yStep != 0))
            lineFull = true;
        line.push_back({x, y, _board.at(y).at(x)});
    }
    return (line);
}

std::vector<Board::CellAttribute> Board::getLineWithStartCell(Board::Direction direction, std::size_t startCellX, std::size_t startCellY)
{
    std::vector<CellAttribute> line = {};
    std::pair<std::size_t, std::size_t> xAmplitude = {0, 0};
    std::pair<std::size_t, std::size_t> yAmplitude = {0, 0};
    int xStep = 0, yStep = 0;
    bool lineFull = false;

    switch (direction) {
        case Direction::VERTICAL:
            if (startCellX + 4 < DEFAULT_BOARD_SIZE)
                xAmplitude.second = startCellX + 4;
            else
                xAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            xAmplitude.first = startCellX;
            yAmplitude = {startCellY, startCellY};
            xStep = 1;
            break;
        case Direction::HORIZONTAL:
            if (startCellY + 4 < DEFAULT_BOARD_SIZE)
                yAmplitude.second = startCellY + 4;
            else
                yAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            yAmplitude.first = startCellY;
            xAmplitude = {startCellX, startCellX};
            yStep = 1;
            break;
        case Direction::RIGHTTOLEFT:
            if (static_cast<int>(startCellX) - 4 >= 0)
                xAmplitude.second = startCellX - 4;
            if (startCellY + 4 < DEFAULT_BOARD_SIZE)
                yAmplitude.second = startCellY + 4;
            else
                yAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            xAmplitude.first = startCellX;
            yAmplitude.first = startCellY;
            xStep = -1;
            yStep = 1;
            break;
        case Direction::LEFTTORIGHT:
            if (startCellX + 4 < DEFAULT_BOARD_SIZE)
                xAmplitude.second = startCellX + 4;
            else
                xAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            if (startCellY + 4 < DEFAULT_BOARD_SIZE)
                yAmplitude.second = startCellY + 4;
            else
                yAmplitude.second = DEFAULT_BOARD_SIZE - 1;
            xAmplitude.first = startCellX;
            yAmplitude.first = startCellY;
            xStep = 1;
            yStep = 1;
            break;
        default:
            break;
    }
    for (std::size_t x = xAmplitude.first, y = yAmplitude.first; !lineFull; x += xStep, y += yStep) {
        if ((x == xAmplitude.second && xStep != 0) || (y == yAmplitude.second && yStep != 0))
            lineFull = true;
        line.push_back({x, y, _predictionBoard.at(y).at(x)});
    }
    return (line);
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

void Board::resetPredictionBoard()
{
    _predictionBoard = _board;
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

bool Board::setPredictionPos(CellState field, std::size_t x, std::size_t y)
{
    if (!_gameStarted)
        return false;
    try {
        if (_predictionBoard.at(y).at(x) == CellState::EMPTY) {
            _predictionBoard.at(y).at(x) = field;
            return (true);
        }
    } catch (const std::out_of_range &e) {
        return (false);
    }
    return (false);
}

bool Board::setPos(CellState field, std::size_t x, std::size_t y)
{
    if (!_gameStarted)
        return false;
    try {
        if (_board.at(y).at(x) == CellState::EMPTY) {
            _board.at(y).at(x) = field;
            if (field == CellState::FIRST_PLAYER)
                _nbField.first++;
            else
                _nbField.second++;
            _predictionBoard = _board;
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
