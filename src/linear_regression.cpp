#include "linear_regression.hpp"
#include <tuple>


LinearRegression::LinearRegression(const double lr)
    : lr(lr)
{
}

LinearRegression::~LinearRegression() {}



vector LinearRegression::forward(const vector& X, const double w, const double b) {
    return w*X + vector::Constant(X.size(), b);
}


params LinearRegression::backward(const vector& X, const vector& y, const vector& yHat) {
    vector dy = yHat - y;
    double dw = 2 * (X.array() * dy.array()).mean();
    double db = 2 * dy.mean();
    return std::make_tuple(dw, db);
}

void LinearRegression::update(double& w, double& b, const double dw, const double db) {
    w = w - lr * dw;
    b = b - lr * db;
}

params LinearRegression::fit(vector& X, vector& y) {
    double w = 0;
    double b = 0;
    for (int i = 0; i < 10; i++) {
        vector yHat = forward(X, w, b);
        params weights = backward(X, y, yHat);
        update(w, b, std::get<0>(weights), std::get<1>(weights));
    }
    return std::make_tuple(w, b);
}
