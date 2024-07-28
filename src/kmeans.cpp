#include <random>
#include "kmeans.hpp"


KMeans::KMeans(const size_t clusters, const Eigen::MatrixXd data) :
    _nbClusters{clusters}, _centroids(initializeCentroids(data))
{

}

Eigen::MatrixXd KMeans::initializeCentroids(const Eigen::MatrixXd data)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, data.rows());
    
    Eigen::MatrixXd centroids = Eigen::MatrixXd::Zero(_nbClusters, data.cols());

    for (size_t i{0}; i < _centroids.rows(); i++){
        centroids.row(i) = data.row(distribution(gen));
    }
    return centroids;
}

void KMeans::updateLabels(const Eigen::MatrixXd data)
{
    Eigen::VectorXd distances(_nbClusters);
    for (size_t i{0}; i < data.rows(); i++){
        for (size_t j{0}; j < _nbClusters; j++){
            distances[j] = (data.row(i) - _centroids.row(j)).norm();
        }
        distances.minCoeff(&_labels[i]);
    }
}

void KMeans::updateCentroids(const Eigen::MatrixXd data){
    _centroids = Eigen::MatrixXd::Zero(_nbClusters, data.cols());
    for (size_t i{0}; i < _nbClusters; i++){
        int population{0};
        for (size_t j{0}; j < _labels.rows(); j++){
            if (_labels[j] == i){
                population++;
                _centroids.row(i) += data.row(j);
            }
        }
        if (population != 0) _centroids.row(i) /= population;
    }
}

Eigen::MatrixXd KMeans::gravityCenter(const Eigen::MatrixXd points) const {
    Eigen::VectorXd center = Eigen::VectorXd::Zero(points.cols());
    for (size_t i{0}; i < points.rows(); i++){
        for (size_t j{0}; j < points.cols(); j++){
            center[j] += points.row(i)[j];
        }
    }
    center /= points.rows();
    return center;
}

bool KMeans::endOfIteration(const Eigen::MatrixXd oldCentroids, const Eigen::MatrixXd newCentroids) const {
    return true;
}

void KMeans::fit(const Eigen::MatrixXd data)
{
    _labels = Eigen::VectorXi::Zero(data.rows());
    for (size_t n{0}; n < 5; n++){
        updateLabels(data);
        updateCentroids(data);
    }
}