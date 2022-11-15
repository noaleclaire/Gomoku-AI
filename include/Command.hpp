/*
** EPITECH PROJECT, 2022
** Command.hpp
** File description:
** Command.hpp
*/

#pragma once

#include "../include/Board.hpp"

#include <string>

class Command {
    public:
        static void execCommand(std::string line, Board &board);

    private:
        static void _start(std::string args, Board &board);
        static void _turn(std::string args, Board &board);
        static void _begin(std::string args, Board &board);
        static void _board(std::string args, Board &board);
        static void _info(std::string args, Board &board);
        static void _end(std::string args, Board &board);
        static void _about(std::string args, Board &board);
};
