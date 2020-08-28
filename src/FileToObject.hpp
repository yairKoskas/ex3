#include <stdio.h>
#include <string>
class FileToObject {
    private:
        Matrix matrix1;
        Matrix matrix2;
        Image image;
        crc32 bitfile;

    public:
        FileToObject (std::string type, std::string pathfile1, std::string pathfile2);
};