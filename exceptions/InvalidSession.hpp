#pragma once

#include <exception>

class InvalidSessionException : public std::exception {
public:
  InvalidSessionException() {}
};