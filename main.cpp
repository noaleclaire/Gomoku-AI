/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main.cpp
*/

#include "Command.hpp"
#include "Printer.hpp"

#include <iostream>

int main(void)
{
    std::string cmd = "";
    Board board;

    while (1) {
        std::cin.clear();
        std::getline(std::cin, cmd);
        if (std::cin.bad() || std::cin.fail())
            continue;
        try {
            Command::execCommand(cmd, board);
        } catch (const std::exception &e) {}
    }
    return (0);
}