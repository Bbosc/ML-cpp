#include <iostream>
#include <fstream>
#include <vector>
#include "kmeans.hpp"


void writeEigenMatrixToFile(Eigen::MatrixXd const data, std::string filename){
    std::ofstream file(filename);
    if (file){
        for (size_t i{0}; i < data.rows(); i++){
            for (size_t j{0}; j < data.cols(); j++){
                file << data.row(i)[j] << "\n";
            }
        }
        file.close();
    }
}

void writeEigenVectorToFile(Eigen::VectorXi const data, std::string filename){
    std::ofstream file(filename);
    if (file){
        file << data;
        file.close();
    }
}

Eigen::MatrixXd getDataFromFile(const std::string& filename){
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    
    std::string line;
    std::vector<std::vector<double>> content;

    int rows = 0;
    int cols = -1;
    
    while (std::getline(file, line)){
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<double> row;

        while (std::getline(lineStream, cell, ' ')){
            row.push_back(std::stod(cell));
        }

        if (cols == -1)
            cols = row.size();
        
        content.push_back(row);
        ++rows;
    }

    file.close();

    Eigen::MatrixXd data(rows, cols);
    for (size_t i{0}; i < rows; i++){
        for (size_t j{0}; j < cols; j++){
            data(i, j) = content[i][j];
        }
    }
    return data;
}

int main(int argc, char* argv[])
{
    int clusters{3};
    Eigen::MatrixXd data = getDataFromFile("datasets/clustering-S/s1.txt");
    std::cout << data.rows() << ", " << data.cols() << std::endl;
    return 0;
}