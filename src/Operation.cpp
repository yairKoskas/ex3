#include "Operation.hpp"
#include "FileToObject.hpp"
#include "crc32.h"

#include <iostream>
#include <string>
Operation::Operation(const std::vector<std::string>& input) {
    this->m_input = input;
} 

std::string Operation::doInput() {
    std::vector<std::string> path;
    if (this->m_input[0] == "matrix") {
        path.push_back(this->m_input[2]);
        path.push_back(this->m_input[3]);
        FileToObject object = FileToObject("matrix", this->m_input[1], path, this->m_input[4]);
        if (this->m_input[1] == "add") {
            return object.addMatrix();

        }
        if (this->m_input[1] == "multiply") {
            return object.multiplyMatrix();

        }


    }
    if (this->m_input[0] == "image") {
        path.push_back(this->m_input[2]);
        FileToObject object = FileToObject("image", this->m_input[1], path, this->m_input[3]);
        if (this->m_input[1] == "convert") {
            return object.grayBmp();
        }
        if (this->m_input[1] == "rotate") {
            return object.rotateBmp();
        }

    }
    if (this->m_input[0] == "hash") {
        FileToObject object = FileToObject("hash", this->m_input[1], path, this->m_input[3]);
        return std::to_string(object.calculateHash());
    }
}
