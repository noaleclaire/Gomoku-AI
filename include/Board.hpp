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
        bool empty() const;
        bool isGameStarted() const;

        /* Setter */
        void setBoard(std::size_t size);
        void setInfo(std::string keyword, std::size_t value);
        void setPos(CellState cell, std::size_t x, std::size_t y);

    private:
        std::vector<std::vector<CellState>> _board;
        Info _gameInfos;
        bool _gameStarted;
};
