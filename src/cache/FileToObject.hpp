#include <stdio.h>
#include <string>
class FileToObject {
    Matrix matrix1;
    Matrix matrix2;
    Image image;
    crc32 bitfile;

    FileToObject (std::string type, std::string pathfile1, std::string pathfile2) {
        if (type == "matrix") {
            
        }
        if (type == "image") {
            this->image = Image(pathfile1);
        }
        if (type == "bitfile") {
            bitfile = pathfile1;
        }
    }
};