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

        Board();
        ~Board() = default;

        /* Getter */
        std::vector<std::pair<std::size_t, std::size_t>> getPlayerPos(CellState field) const;
        bool isGameStarted() const;

        /* Setter */
        void resetBoard();
        bool setBoard(std::size_t size);
        void setInfo(std::string keyword, std::size_t value);
        bool setPos(CellState field, std::size_t x, std::size_t y);

    private:
        std::vector<std::vector<CellState>> _board;
        std::pair<std::vector<std::pair<std::size_t, std::size_t>>, std::vector<std::pair<std::size_t, std::size_t>>> _playersPos;
        Info _gameInfos;
        bool _gameStarted;
        std::size_t _size;
};
