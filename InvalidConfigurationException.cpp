#include "InvalidConfigurationException.hpp"

InvalidConfigurationException::InvalidConfigurationException(std::string error) {
    this->m_error = error;
}

const char* InvalidConfigurationException::what() const noexcept {
    return m_error.c_str();
}

