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
        void set(std::string keyword, std::size_t value);

    private:
        std::map<std::string, std::size_t> _infos;
};
