/*
** EPITECH PROJECT, 2022
** BrainCommand.hpp
** File description:
** BrainCommand.hpp
*/

#pragma once

#include <string>

class BrainCommand {
    public:
        static void ERROR(std::string error_message);
        static void UNKNOWN(std::string error_message);
        static void MESSAGE(std::string message);
        static void DEBUG(std::string message);
        static void SUGGEST(std::size_t x, std::size_t y);
};
