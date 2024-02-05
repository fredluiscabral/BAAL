#include "EigenSumStrategy.hpp"

Matrix EigenSumStrategy::sum(const Matrix& m1, const Matrix& m2) const {
    // Assume que Matrix tem um construtor que aceita Eigen::MatrixXd
    // e um método toEigen() que converte para Eigen::MatrixXd
    Eigen::MatrixXd eigenMat1 = m1.toEigen();
    Eigen::MatrixXd eigenMat2 = m2.toEigen();

    Eigen::MatrixXd resultMat = eigenMat1 + eigenMat2;

    return Matrix(resultMat); // Convertendo de volta para Matrix
}
