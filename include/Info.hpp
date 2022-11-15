/*
** EPITECH PROJECT, 2022
** Info.hpp
** File description:
** Info.hpp
*/

#pragma once

#include <map>
#include <string>

class Info {
    public:
        Info();
        ~Info() = default;

        /* Getter */

        /* Setter */

    private:
        std::map<std::string, std::size_t> _infos;
        // std::map<std::string, std::any> _infos; -> si folder et evaluation
};
