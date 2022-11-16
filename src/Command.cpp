/*
** EPITECH PROJECT, 2022
** Command.cpp
** File description:
** Command.cpp
*/

#include "../include/AI.hpp"
#include "../include/BrainCommand.hpp"
#include "../include/Command.hpp"
#include "../include/define.hpp"
#include "../include/Printer.hpp"

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
        std::string cmd = "", args = "";

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
}

void Command::_start(std::string args, Board &board)
{
    try {
        if (std::stoi(args) == DEFAULT_BOARD_SIZE) {
            // if (board.setBoard(_convert(args)))
            //     Printer::print("OK - everything is good");
            if (board.setBoard(std::stoi(args)))
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
    std::size_t x = 0, y = 0;

    try {
        if (args.find(",") != args.npos && std::stoi(args.substr(0, args.find(","))) < DEFAULT_BOARD_SIZE) {
            x = _convert(args.substr(0, args.find(",")));
        } else {
            return;
        }
        args = args.substr(args.find(",") + 1, args.size() - (args.find(",") + 1));
        if (std::stoi(args) < DEFAULT_BOARD_SIZE) {
            y = _convert(args);
        } else {
            return;
        }
        if (board.setPos(Board::CellState::FIRST_PLAYER, x, y)) {
            AI::turn(board);
        }
    } catch (const std::invalid_argument &e) {}
}

void Command::_begin(std::string args, Board &board)
{
    static_cast<void>(args);
    if (board.isGameStarted())
        AI::turn(board);
}

void Command::_board(std::string args, Board &board)
{
    std::string cmd = "";
    std::size_t x = 0, y = 0, field = 0;

    static_cast<void>(args);
    while (1) {
        std::cin.clear();
        std::getline(std::cin, cmd);
        if (std::cin.bad() || std::cin.fail())
            continue;
        if (cmd == "DONE")
            break;
        try {
            if (cmd.find(",") != cmd.npos && std::stoi(cmd.substr(0, cmd.find(","))) < DEFAULT_BOARD_SIZE)
                x = _convert(cmd.substr(0, cmd.find(",")));
            else
                continue;
            cmd = cmd.substr(cmd.find(",") + 1, cmd.size() - (cmd.find(",") + 1));
            if (cmd.find(",") != cmd.npos && std::stoi(cmd.substr(0, cmd.find(","))) < DEFAULT_BOARD_SIZE)
                y = _convert(cmd.substr(0, cmd.find(",")));
            else
                continue;
            cmd = cmd.substr(cmd.find(",") + 1, cmd.size() - (cmd.find(",") + 1));
            if (cmd.size() > 0 && (std::stoi(cmd) == 1 || std::stoi(cmd) == 2))
                field = _convert(cmd);
            else
                continue;
            board.setPos(static_cast<Board::CellState>(field), x, y);
        } catch (const std::invalid_argument &e) {}
    }
    AI::turn(board);
}

void Command::_info(std::string args, Board &board)
{
    std::string keyword = "";
    std::size_t value = 0;

    if (args.find(" ") != args.npos) {
        keyword = args.substr(0, args.find(" "));
        args = args.substr(args.find(" ") + 1, args.size() - (args.find(" ") + 1));
    } else {
        return;
    }
    try {
        value = _convert(args);
        board.setInfo(keyword, value);
    } catch (const std::invalid_argument &e) {}
}

void Command::_end(std::string args, Board &board)
{
    static_cast<void>(args);
    static_cast<void>(board);
    exit(0);
}

void Command::_about(std::string args, Board &board)
{
    static_cast<void>(args);
    static_cast<void>(board);
    Printer::print("name=\"TROUVER UN NOM\", version=\"1.0\", author=\"NEM\", country=\"France\"");
}

std::size_t Command::_convert(std::string str)
{
    for (auto &it : str) {
        if (it < '0' || it > '9')
            throw std::invalid_argument("{ERROR} The string doesn't contain only digit");
    }
    return (std::stoi(str));
}
