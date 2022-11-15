/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main.cpp
*/

#include "include/Command.hpp"
#include "include/Printer.hpp"
#include "include/exceptions/Exception.hpp"
#include "include/exceptions/ExceptionCommandNotFound.hpp"

#include <iostream>

int main(int ac, char **av)
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
        } catch (const ExceptionCommandNotFound &e) {
        } catch (const Exception &e) {}
    }
    return (0);
}