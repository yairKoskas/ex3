#include <stdio.h>
#include <string>
#include "matrix/CMatrix.h"
#include "BMP.h"
#include "bmp_tester.hpp"
class FileToObject {
    private:
        CMatrix matrix1;
        CMatrix matrix2;
        std::string image;
        //crc32 bitfile;
        std::string outputPath;
        std::vector<std::string> pathfile;



    public:
        FileToObject (std::string type, std::string operation, std::vector<std::string> pathfiles,
         const std::string& outputPath1);

        std::string addMatrix();
        std::string multiplyMatrix();

        std::string rotateBmp();
        std::string grayBmp();
};