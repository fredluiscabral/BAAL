// Matrix.cpp
#include "Matrix.hpp"
#include <Eigen/Dense>

//Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows * cols, 0.0) {}


// Dentro de Matrix.cpp

Eigen::MatrixXd Matrix::toEigen() const {
    Eigen::MatrixXd mat(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //mat(i, j) = data[i][j];
            mat(i, j) = data[i * cols + j];
        }
    }
    return mat;
}

/*
Matrix::Matrix(const Eigen::MatrixXd& mat) : rows(mat.rows()), cols(mat.cols()), data(rows, std::vector<double>(cols)) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = mat(i, j);
        }
    }
}
*/

Matrix::Matrix(const Eigen::MatrixXd& mat) : rows(mat.rows()), cols(mat.cols()), data(mat.size()) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i * cols + j] = mat(i, j);
        }
    }
}


/*
double Matrix::getValue(int row, int col) const {
    return data[row][col];
}

void Matrix::setValue(int row, int col, double value) {
    data[row][col] = value;
}
*/

double Matrix::getValue(int row, int col) const {
    return data[row * cols + col];
}

void Matrix::setValue(int row, int col, double value) {
    data[row * cols + col] = value;
}



int Matrix::getRows() const { return rows; }

int Matrix::getCols() const { return cols; }
