/*
** EPITECH PROJECT, 2022
** Printer.hpp
** File description:
** Printer.hpp
*/

#pragma once

#include <iostream>

class Printer {
    public:
        static void print()
        {
            std::cout << std::endl;
        };
        template <class T, class... Params>
        static void print(const T &first, Params &&...args)
        {
            std::cout << first << std::flush;
            print(args...);
        }
        static void printErr()
        {
            std::cerr << std::endl;
        };
        template <class T, class... Params>
        static void printErr(const T &first, Params &&...args)
        {
            std::cerr << first << std::flush;
            print(args...);
        }
};
