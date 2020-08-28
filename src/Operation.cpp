#include "Operation.hpp"

Operation::Operation(const std::vector<std::string>& input) {
    this->m_input = input;
} 

std::string Operation::doInput() {
    if (this->m_input[0] == "matrix : multiply") {

    }
    if (this->m_input[0] == "matrix : add") {

    }
    if (this->m_input[0] == "image : togray") {

    }
    if (this->m_input[0] == "image : rotate") {

    }
    if (this->m_input[0] == "binary : hash") {

    }
}
