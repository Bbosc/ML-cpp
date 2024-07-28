#pragma once
#include <iostream>
#include <Eigen/Dense>

class KMeans{
public:
    KMeans(size_t clusters, Eigen::MatrixXd data);
    size_t getNbClusters() const {return _nbClusters;}
    Eigen::MatrixXd getCentroids() const {return _centroids;}
    Eigen::VectorXi getLabels() const { return _labels; }
    void fit(Eigen::MatrixXd data);

private:
    size_t _nbClusters{};
    Eigen::VectorXi _labels;
    Eigen::MatrixXd _centroids;

    Eigen::MatrixXd initializeCentroids(const Eigen::MatrixXd data);
    void updateLabels(const Eigen::MatrixXd data);
    void updateCentroids(const Eigen::MatrixXd data);
    bool endOfIteration(const Eigen::MatrixXd oldCentroids, const Eigen::MatrixXd newCentroids) const;
    Eigen::MatrixXd gravityCenter(const Eigen::MatrixXd points) const;

};
