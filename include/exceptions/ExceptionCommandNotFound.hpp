/*
** EPITECH PROJECT, 2022
** ExceptionCommandNotFound.hpp
** File description:
** ExceptionCommandNotFound.hpp
*/

#pragma once

#include "Exception.hpp"

class ExceptionCommandNotFound : public Exception {
  public:
    /**
     * @brief Construct a new Exception Component Null object
     *
     * @param message
     * @param location
     */
    ExceptionCommandNotFound(const std::string &message, const std::string &location) : Exception(message, location){};
    /**
     * @brief Destroy the Exception Component Null object
     *
     */
    ~ExceptionCommandNotFound() = default;

  protected:
  private:
};
