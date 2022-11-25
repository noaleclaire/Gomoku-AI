/*
** EPITECH PROJECT, 2022
** AI.cpp
** File description:
** AI.cpp
*/

#include "AI.hpp"
#include "BrainCommand.hpp"
#include "define.hpp"
#include "Printer.hpp"

#include <algorithm>
#include <cmath>

void AI::turn(Board &board, std::size_t playerX, std::size_t playerY)
{
    std::size_t x = 0, y = 0;
    std::pair<std::size_t, std::size_t> nbFieldCell = board.countFieldCell();

    if (nbFieldCell.first == 0 && nbFieldCell.second == 0) {
        x = std::rand()%static_cast<int>(std::ceil(DEFAULT_BOARD_SIZE/3)) + static_cast<int>(std::ceil(DEFAULT_BOARD_SIZE/3));
        y = std::rand()%static_cast<int>(std::ceil(DEFAULT_BOARD_SIZE/3)) + static_cast<int>(std::ceil(DEFAULT_BOARD_SIZE/3));
        std::srand(time(NULL));
    } else if (nbFieldCell.first == 1 && nbFieldCell.second == 0) {
        _start(board, x, y, playerX, playerY);
    } else {
        // if (_attack(board, x, y) == false) {
        //     if (_defend(board, x, y) == false) {
        //         _turn(board, x, y);
        //     }
        // }
        if (yesy(board, x, y) == false)
            _turn(board, x, y);
    }
    board.setPos(Board::CellState::SECOND_PLAYER, x, y);
    // board.printBoard();
    Printer::print(x, ",", y);
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

bool AI::_attack(Board &board, std::size_t &x, std::size_t &y)
{
    std::vector<Board::CellAttribute> line = {};
    std::vector<Board::Direction> directions = {Board::Direction::HORIZONTAL, Board::Direction::VERTICAL,
                                                Board::Direction::LEFTTORIGHT, Board::Direction::RIGHTTOLEFT};

    for (std::size_t i = 0; i < board.getBoard().size(); i++) {
        for (std::size_t j = 0; j < board.getBoard().at(i).size(); j++) {
            for (auto &dir : directions) {
                line = board.getLineWithMidCell(dir, j, i);
                if (line.size() < 5)
                    continue;
                for (std::size_t lineIndex = 0; line.size() - lineIndex > 5; lineIndex++) {
                    for (auto &pattern : Board::attackPattern) {
                        for (std::size_t ptnIndex = 0; ptnIndex < 5; ptnIndex++) {
                            if (line.at(lineIndex + ptnIndex).field != pattern.at(ptnIndex))
                                break;
                            if (line.at(lineIndex + ptnIndex).field == Board::CellState::EMPTY) {
                                x = line.at(lineIndex + ptnIndex).posX;
                                y = line.at(lineIndex + ptnIndex).posY;
                            }
                            if (ptnIndex == 4)
                                return (true);
                        }
                    }
                }
            }
        }
    }
    return (false);
}

bool AI::_defend(Board &board, std::size_t &x, std::size_t &y)
{
    std::vector<Board::CellAttribute> line = {};
    std::vector<Board::Direction> directions = {Board::Direction::HORIZONTAL, Board::Direction::VERTICAL,
                                                Board::Direction::LEFTTORIGHT, Board::Direction::RIGHTTOLEFT};

    for (std::size_t i = 0; i < board.getBoard().size(); i++) {
        for (std::size_t j = 0; j < board.getBoard().at(i).size(); j++) {
            for (auto &dir : directions) {
                line = board.getLineWithMidCell(dir, j, i);
                if (line.size() < 5)
                    continue;
                for (std::size_t lineIndex = 0; line.size() - lineIndex > 5; lineIndex++) {
                    for (auto &pattern : Board::defensePattern) {
                        for (std::size_t ptnIndex = 0; ptnIndex < 5; ptnIndex++) {
                            if (line.at(lineIndex + ptnIndex).field != pattern.at(ptnIndex))
                                break;
                            if (line.at(lineIndex + ptnIndex).field == Board::CellState::EMPTY) {
                                x = line.at(lineIndex + ptnIndex).posX;
                                y = line.at(lineIndex + ptnIndex).posY;
                            }
                            if (ptnIndex == 4)
                                return (true);
                        }
                    }
                }
            }
        }
    }
    return (false);
}

bool AI::yesy(Board &board, std::size_t &x, std::size_t &y)
{
    bool def = false;
    std::size_t defX = 0, defY = 0;
    std::vector<Board::CellAttribute> line = {};
    std::vector<Board::Direction> directions = {Board::Direction::HORIZONTAL, Board::Direction::VERTICAL,
                                                Board::Direction::LEFTTORIGHT, Board::Direction::RIGHTTOLEFT};

    for (std::size_t i = 0; i < board.getBoard().size(); i++) {
        for (std::size_t j = 0; j < board.getBoard().at(i).size(); j++) {
            for (auto &dir : directions) {
                line = board.getLineWithMidCell(dir, j, i);
                if (line.size() < 5)
                    continue;
                for (std::size_t lineIndex = 0; line.size() - lineIndex > 5; lineIndex++) {
                    for (auto &pattern : Board::attackPattern) {
                        for (std::size_t ptnIndex = 0; ptnIndex < 5; ptnIndex++) {
                            if (line.at(lineIndex + ptnIndex).field != pattern.at(ptnIndex))
                                break;
                            if (line.at(lineIndex + ptnIndex).field == Board::CellState::EMPTY) {
                                x = line.at(lineIndex + ptnIndex).posX;
                                y = line.at(lineIndex + ptnIndex).posY;
                            }
                            if (ptnIndex == 4)
                                return (true);
                        }
                    }
                    for (auto &pattern : Board::defensePattern) {
                        for (std::size_t ptnIndex = 0; ptnIndex < 5; ptnIndex++) {
                            std::size_t emptyX = 0, emptyY = 0;
                            if (line.at(lineIndex + ptnIndex).field != pattern.at(ptnIndex))
                                break;
                            if (line.at(lineIndex + ptnIndex).field == Board::CellState::EMPTY) {
                                emptyX = line.at(lineIndex + ptnIndex).posX;
                                emptyY = line.at(lineIndex + ptnIndex).posY;
                            }
                            if (ptnIndex == 4 && def == false) {
                                defX = emptyX;
                                defY = emptyY;
                                def = true;
                            }
                        }
                    }
                }
            }
        }
    }
    if (def == true) {
        x = defX;
        y = defY;
    }
    return (def);
}

void AI::_turn(Board &board, std::size_t &x, std::size_t &y)
{
    // x = std::rand()%DEFAULT_BOARD_SIZE;
    // y = std::rand()%DEFAULT_BOARD_SIZE;
    // while (!board.setPos(Board::CellState::SECOND_PLAYER, x, y)) {
    //     x = std::rand()%DEFAULT_BOARD_SIZE;
    //     y = std::rand()%DEFAULT_BOARD_SIZE;
    // }
    int score = -9999;

    // Exploration a un de profondeur
    for (std::size_t i = 0; i < board.getBoard().size(); i++) {
        for (std::size_t j = 0; j < board.getBoard().at(i).size(); j++) {
            board.resetPredictionBoard();
            if (board.setPredictionPos(Board::CellState::SECOND_PLAYER, j, i) == false)
                continue;
            int tmpScore = board.evaluation();
            if (score < tmpScore) {
                score = tmpScore;
                x = j;
                y = i;
            }
        }
    }
}
