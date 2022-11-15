/*
** EPITECH PROJECT, 2022
** Info.cpp
** File description:
** Info.cpp
*/

#include "../include/Info.hpp"

#include <stdexcept>

Info::Info()
{
    _infos = {{"timeout_turn", 5000}, {"timeout_match", 0}, {"max_memory", 70000000}, {"game_type", 1}};
}

/* Getter */

/* Setter */
void Info::set(std::string keyword, std::size_t value)
{
    try {
        _infos.at(keyword) = value;
    } catch (const std::out_of_range &e) {}
}
