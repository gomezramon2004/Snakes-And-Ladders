#include "InvalidOptionException.hpp"

InvalidOptionException::InvalidOptionException(std::string error) {
    this->m_error = error;
}

const char* InvalidOptionException::what() const noexcept {
    return this->m_error.c_str();
}

