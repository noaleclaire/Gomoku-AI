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
        enum CellState { EMPTY, FIRST_PLAYER, SECOND_PLAYER, PLAYER };
        enum Direction { HORIZONTAL, VERTICAL, LEFTTORIGHT, RIGHTTOLEFT};
        static std::vector<std::vector<CellState>> attackPattern;
        static std::vector<std::vector<CellState>> defensePattern;
        static std::vector<std::pair<std::vector<CellState>, std::size_t>> scorePattern;
        struct CellAttribute {
            std::size_t posX;
            std::size_t posY;
            CellState field;
        };

        Board();
        ~Board() = default;

        /* Getter */
        std::pair<std::size_t, std::size_t> countFieldCell() const;
        int evaluation();
        std::vector<std::vector<CellState>> getBoard() const;
        std::vector<CellAttribute> getLineWithEndCell(Direction direction, std::size_t endCellX, std::size_t endCellY);
        std::vector<CellAttribute> getLineWithMidCell(Direction direction, std::size_t midCellX, std::size_t midCellY);
        std::vector<CellAttribute> getLineWithStartCell(Direction direction, std::size_t startCellX, std::size_t startCellY);
        std::vector<CellAttribute> getPredictedCells(CellState field);
        std::pair<std::vector<CellAttribute>, std::vector<CellAttribute>> getPredictedCells();
        bool isGameStarted() const;

        /* Setter */
        void resetBoard();
        void resetPredictionBoard();
        bool setBoard(std::size_t size);
        void setInfo(std::string keyword, std::size_t value);
        bool setPredictionPos(CellState field, std::size_t x, std::size_t y);
        bool setPos(CellState field, std::size_t x, std::size_t y);

        void printBoard();

    private:
        std::vector<std::vector<CellState>> _board;
        std::vector<std::vector<CellState>> _predictionBoard;
        std::pair<std::vector<CellAttribute>, std::vector<CellAttribute>> _cells;
        std::pair<std::vector<CellAttribute>, std::vector<CellAttribute>> _predictedCells;
        std::pair<std::size_t, std::size_t> _nbFieldCell;
        Info _gameInfos;
        bool _gameStarted;
        std::size_t _size;
};
