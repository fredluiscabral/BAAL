// Matrix.hpp
#pragma once
#include <vector>
#include <stdexcept>
#include <Eigen/Dense>

class Matrix {
public:
    //std::vector<std::vector<double>> data;
    std::vector<double> data;

    int rows, cols;

    Matrix(int rows, int cols);

    // Adicionar a conversão para Eigen::MatrixXd
    Eigen::MatrixXd toEigen() const;

    // Adicionar um construtor que aceite Eigen::MatrixXd
    Matrix(const Eigen::MatrixXd& mat);

    double getValue(int row, int col) const;
    void setValue(int row, int col, double value);
    int getRows() const;
    int getCols() const;
};
