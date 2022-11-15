/*
** EPITECH PROJECT, 2022
** BrainCommand.cpp
** File description:
** BrainCommand.cpp
*/

#include "../include/BrainCommand.hpp"
#include "../include/Printer.hpp"

void BrainCommand::ERROR(std::string error_message)
{
    Printer::print("ERROR message - ", error_message);
}

void BrainCommand::UNKNOWN(std::string error_message)
{
    Printer::print("UNKNOWN message - ", error_message);
}

void BrainCommand::MESSAGE(std::string message)
{
    Printer::print("MESSAGE ", message);
}

void BrainCommand::DEBUG(std::string message)
{
    Printer::print("DEBUG ", message);
}

void BrainCommand::SUGGEST(std::size_t x, std::size_t y)
{
    Printer::print("SUGGEST ", x, ",", y);
}
