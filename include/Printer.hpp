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
        static void print() {};
        template <class T, class... Params>
        static void print(const T &first, Params &&...args)
        {
            std::cout << first << std::flush;
            print(args...);
            std::cout << std::endl;
        }
        static void printErr() {};
        template <class T, class... Params>
        static void printErr(const T &first, Params &&...args)
        {
            std::cerr << first << std::flush;
            print(args...);
            std::cerr << std::endl;
        }
};
