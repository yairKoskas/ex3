#include "FileToObject.hpp"
#include "BMP.h"
#include "CMatrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

FileToObject::FileToObject(std::string type, std::string operation, std::vector<std::string> pathfiles,
         const std::string& outputPath1) {
    this->outputPath = outputPath1;
    this->pathfile = pathfiles;
    if (type == "matrix") {
        std::ifstream matrix;
        std::string line;

        matrix.open (pathfiles[0]);
        std::vector<std::vector<double>> mat;
        while(getline(matrix, line)) {
            std::vector<double> vec;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != ',') {
                    char* c = &line[i];
                    double num = atof(c);
                    vec.push_back(num);
                }
            }
            mat.push_back(vec);
        };
        matrix.close();
        this->matrix1 = CMatrix(mat.size(), mat[0].size());
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++){
                this->matrix1.setValue(i, j, mat[i][j]);
            }
        }

        matrix.open (pathfiles[1]);
        std::vector<std::vector<double>> mat2;
        while(getline(matrix, line)) {
            std::vector<double> vec;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != ',') {
                    char* c = &line[i];
                    double num = atof(c);
                    vec.push_back(num);
                }
            }
            mat.push_back(vec);
        };
        matrix.close(); 
        this->matrix2 = CMatrix(mat2.size(), mat2[0].size());
        for (int i = 0; i < mat2.size(); i++) {
            for (int j = 0; j < mat2[0].size(); j++){
                this->matrix2.setValue(i, j, mat2[i][j]);
            }
        }

    }
    if (type == "image") {
        this->image = pathfiles[0];
    }
    if (type == "bitfile") {
        //bitfile = pathfile1;
    }

}

std::string FileToObject :: addMatrix() {
    CMatrix mat = this->matrix1.add(this->matrix1, this->matrix2);
    std::ofstream endfile;
    endfile.open (this->outputPath);
    for (int i = 0; i < mat.getHeight(); i++) {
        for (int j = 0; j < mat.getWidth(); j++) {
            endfile << mat.getValue(i, j);
            if (j != mat.getWidth() - 1) {
                endfile << ",";
            }

        }
        endfile << "\n";
    }

    endfile.close();
    return "matrix add " + this->pathfile[0] + " " + this->pathfile[1] + this->outputPath;
}
std::string FileToObject :: multiplyMatrix() {
    CMatrix mat = this->matrix1.multMatrix(this->matrix1, this->matrix2);
    std::ofstream endfile;
    endfile.open (this->outputPath);
    for (int i = 0; i < mat.getHeight(); i++) {
        for (int j = 0; j < mat.getWidth(); j++) {
            endfile << mat.getValue(i, j);
            if (j != mat.getWidth() - 1) {
                endfile << ",";
            }

        }
        endfile << "\n";
    }

    endfile.close();
    return "matrix multiply " + this->pathfile[0] + " " + this->pathfile[1] + this->outputPath;
}

std::string FileToObject :: rotateBmp() {
    rotate_image(this->image, this->outputPath);

    return "image rotate " + this->pathfile[0] + this->outputPath;

}
std::string FileToObject :: grayBmp() {
    convert_to_grayscale(this->image, this->outputPath);

    return "image convert " + this->pathfile[0] + this->outputPath;
}