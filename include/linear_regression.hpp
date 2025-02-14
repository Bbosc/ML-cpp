#include <Eigen/Dense>
#include <tuple>


typedef Eigen::VectorXd vector;
typedef std::tuple<double, double> params;

class LinearRegression {
    public:
        LinearRegression(const double lr);
        ~LinearRegression();
         params fit(vector& X, vector& y);

    private:
        vector forward(const vector& X, const double w, const double b);
        params backward(const vector& X, const vector& y, const vector& yHat);
        void update(double& w, double& b, const double dw, const double db);
        double lr;
};
