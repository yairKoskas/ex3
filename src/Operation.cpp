#include "Operation.hpp"

Operation::Operation(const std::vector<std::string>& input) {
    this->m_input = input;
} 

std::string Operation::doInput() {
    FileToObject object;
    if (this->m_input[0] == "matrix") {
        object = FileToObject("matrix", this->m_input[1], this->m_input[2]);
        if (this->m_input[1] == "add") {
            object.addMatrix();

        }
        if (this->m_input[1] == "multiply") {
            object.multiplyMatrix();

        }


    }
    if (this->m_input[0] == "image") {
        object = FileToObject("image", this->m_input[1], this->m_input[2]);
        if (this->m_input[1] == "togray") {
            object.grayBmp();
        }
        if (this->m_input[1] == "rotate") {
            object.rotateBmp();
        }

    }
    if (this->m_input[0] == "binary : hash") {

    }
}
