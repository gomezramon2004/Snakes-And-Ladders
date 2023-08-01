#include "EndGameException.hpp"

EndGameException::EndGameException(std::string error) {
    this->m_error = error;
}

const char* EndGameException::what() const noexcept {
    return this->m_error.c_str();
}

