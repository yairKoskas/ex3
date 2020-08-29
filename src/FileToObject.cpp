#include "FileToObject.hpp"
#include "BMP.h"
#include "CMatrix.h"
FileToObject::FileToObject(std::string type, std::string pathfile1, std::string pathfile2) {
    if (type == "matrix") {
        
    }
    if (type == "image") {
        this->image = BMP(pathfile1);
    }
    if (type == "bitfile") {
        bitfile = pathfile1;
    }
}