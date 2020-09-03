#include <stdio.h>
#include <string>
#include "matrix/CMatrix.h"
#include "bmp/BMP.h"
#include "bmp/bmp_tester.hpp"
class FileToObject {
    private:
        CMatrix matrix1;
        CMatrix matrix2;
        std::string image;
        std::string toHash;
        std::string outputPath;
        std::vector<std::string> pathfile;



    public:
        FileToObject (std::string type, std::string operation, std::vector<std::string> pathfiles,
         const std::string& outputPath1);

        std::string addMatrix() const;
        std::string multiplyMatrix() const;

        std::string rotateBmp() const;
        std::string grayBmp() const;
        
        uint32_t calculateHash() const;
};