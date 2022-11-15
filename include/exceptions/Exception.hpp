/*
** EPITECH PROJECT, 2022
** Exception.hpp
** File description:
** Exception.hpp
*/

#pragma once

#include <string>

class Exception : public std::exception {
    public:
    /**
        * @brief Construct a new Exception object
        *
        * @param message
        * @param location
        */
    Exception(const std::string &message, const std::string &location)
    {
        _message = message;
        _location = location;
    };
    /**
        * @brief Destroy the Exception object
        *
        */
    ~Exception() = default;
    /**
        * @brief
        *
        * @return const char*
        */
    const char *what() const noexcept override
    {
        return (_message.c_str());
    };
    /**
        * @brief
        *
        * @return const char*
        */
    const char *where() const noexcept
    {
        return (_location.c_str());
    };

    protected:
    private:
    std::string _message;
    std::string _location;
};
