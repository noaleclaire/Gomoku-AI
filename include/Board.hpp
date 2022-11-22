/*
** EPITECH PROJECT, 2022
** Board.hpp
** File description:
** Board.hpp
*/

#pragma once

#include "Info.hpp"

#include <string>
#include <vector>

class Board {
    public:
        enum CellState { EMPTY, FIRST_PLAYER, SECOND_PLAYER };
        enum Direction { HORIZONTAL, VERTICAL, LEFTTORIGHT, RIGHTTOLEFT};
        static std::vector<std::vector<CellState>> attackPattern;
        static std::vector<std::vector<CellState>> defensePattern;
        struct CellAttribute {
            std::size_t posX;
            std::size_t posY;
            CellState field;
        };

        Board();
        ~Board() = default;

        /* Getter */
        std::vector<std::vector<CellState>> getBoard() const;
        std::pair<std::size_t, std::size_t> getFieldCell() const;
        std::vector<CellAttribute> getLine(Direction direction, std::size_t midCellX, std::size_t midCellY);
        bool isGameStarted() const;

        /* Setter */
        void resetBoard();
        bool setBoard(std::size_t size);
        void setInfo(std::string keyword, std::size_t value);
        bool setPos(CellState field, std::size_t x, std::size_t y);

        void printBoard();

    private:
        std::vector<std::vector<CellState>> _board;
        Info _gameInfos;
        bool _gameStarted;
        std::size_t _size;
};
