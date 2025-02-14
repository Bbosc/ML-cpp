#include <iostream>
#include "utils.hpp"
#include "linear_regression.hpp"


int main (int argc, char *argv[]) {
    LinearRegression lr(0.0001);
    std::string filename = "datasets/data_for_lr.csv";
    Matrix<double> data = readCSV<double>(filename);
    Eigen::MatrixXd eigenData = convertToEigen<double>(data);

    Eigen::VectorXd X = eigenData.col(0);
    Eigen::VectorXd y = eigenData.col(1);
    params weights = lr.fit(X, y);
    std::cout << "coefficient: " << std::get<0>(weights) << std::endl;
    std::cout << "intercept: " << std::get<1>(weights) << std::endl;

    return 0;
}
