#ifndef UTIL_HPP
#define UTIL_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Eigen/Core>


template<typename T> using Matrix = std::vector<std::vector<T>>;

template <typename T>
Matrix<T> readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    Matrix<T> data;

    if (!file.is_open()) {
        std::cerr << "Error opening the file" << std::endl;
        return data;
    }
    
    std::getline(file, line); // skip the headers
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<T> row;
        while (std::getline(lineStream, cell, ',')) {
            std::stringstream cellStream(cell);
            T value;
            cellStream >> value;
            row.push_back(value);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}

template <typename T>
Eigen::MatrixXd convertToEigen(const Matrix<T> stdvector) {
    Eigen::MatrixXd eigenMatrix(stdvector.size(), stdvector[0].size());
    for (size_t i = 0; i < stdvector.size(); ++i) {
        for (size_t j = 0; j < stdvector[i].size(); ++j) {
            eigenMatrix(i, j) = stdvector[i][j];
        }
    }
    return eigenMatrix;
}


#endif // !UTIL_HPP
