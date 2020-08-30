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


    public:
        FileToObject (std::string type, std::string pathfile1, std::string pathfile2,
         const std::string& outputPath1);

        CMatrix addMatrix();
        CMatrix multiplyMatrix();

        void rotateBmp();
        void grayBmp();
};