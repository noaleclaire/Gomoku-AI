/*
** EPITECH PROJECT, 2022
** Command.cpp
** File description:
** Command.cpp
*/

#include "../include/BrainCommand.hpp"
#include "../include/Command.hpp"
#include "../include/define.hpp"
#include "../include/Printer.hpp"
#include "../include/exceptions/ExceptionCommandNotFound.hpp"

#include <cmath>
#include <functional>
#include <iostream>
#include <map>

typedef std::function<void(std::string, Board &)> fptr;
typedef std::map<std::string, fptr> MapCall;

void Command::execCommand(std::string line, Board &board)
{
        MapCall creator = {{"START", &_start}, {"TURN", &_turn}, {"BEGIN", &_begin},
            {"BOARD", &_board}, {"INFO", &_info}, {"END", &_end}, {"ABOUT", &_about}};
        MapCall::const_iterator call;

        std::string cmd = "";
        std::string args = "";
        if (line.find(" ") == line.npos)
            cmd = line;
        else {
            cmd = line.substr(0, line.find(" "));
            args = line.substr(line.find(" ") + 1, line.size());
        }
        call = creator.find(cmd);
        if (call != creator.end()) {
            return (call->second(args, board));
        }
        throw ExceptionCommandNotFound("This command doesn't exist in ", "void Command::execCommand(std::string cmd)");
}

void Command::_start(std::string args, Board &board)
{
    try {
        if (args == "" || args.find(" ") > 0 || std::stoi(args) != DEFAULT_BOARD_SIZE) {
            board.setBoard(std::stoi(args));
            Printer::print("OK - everything is good");
        } else {
            BrainCommand::ERROR("unsupported size or other error");
        }
    } catch (const std::invalid_argument &e) {
        BrainCommand::ERROR("unsupported size or other error");
    }
}

void Command::_turn(std::string args, Board &board)
{
    std::size_t x = 0;
    std::size_t y = 0;

    try {
        if (args == "" || args.find(" ") != args.npos || std::stoi(args.substr(0, args.find(","))) > DEFAULT_BOARD_SIZE) {
            board.setBoard(std::stoi(args));
        } else {
            BrainCommand::ERROR("unsupported size or other error");
        }
        if (args == "" || args.find(",") != args.npos || std::stoi(args) > DEFAULT_BOARD_SIZE) {
            board.setBoard(std::stoi(args));
        } else {
            BrainCommand::ERROR("unsupported size or other error");
        }
    } catch (const std::invalid_argument &e) {
        BrainCommand::ERROR("unsupported size or other error");
    }
    Printer::print("turn");
}

void Command::_begin(std::string args, Board &board)
{
    Printer::print("begin");
}

void Command::_board(std::string args, Board &board)
{
    std::string cmd = "";
    std::size_t x, y, field = 0;

    while (1) {
        std::cin.clear();
        std::getline(std::cin, cmd);
        if (std::cin.bad() || std::cin.fail())
            continue;
        if (cmd == "DONE")
            break;
        try {
            if (cmd.find(",") != cmd.npos)
                x = std::stoi(cmd.substr(0, cmd.find(",")));
            else
                continue;
            cmd = cmd.substr(cmd.find(",") + 1, cmd.size() - (cmd.find(",") + 1));
            if (cmd.find(",") != cmd.npos)
                y = std::stoi(cmd.substr(0, cmd.find(",")));
            else
                continue;
            cmd = cmd.substr(cmd.find(",") + 1, cmd.size() - (cmd.find(",") + 1));
            if (cmd.size() > 0)
                field = std::stoi(cmd);
            else
                continue;
            board.setPos(static_cast<Board::CellState>(field), x, y);
        } catch (const std::invalid_argument &e) {}
    }
}

void Command::_info(std::string args, Board &board)
{
    Printer::print("info");
}

void Command::_end(std::string args, Board &board)
{
    Printer::print("end");
}

void Command::_about(std::string args, Board &board)
{
    Printer::print("about");
}
