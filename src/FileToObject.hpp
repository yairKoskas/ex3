#include <stdio.h>
#include <string>
#include "CMatrix.h"
#include "BMP.h"
class FileToObject {
    private:
        CMatrix matrix1;
        CMatrix matrix2;
        BMP image;
        crc32 bitfile;

    public:
        FileToObject (std::string type, std::string pathfile1, std::string pathfile2);
};s