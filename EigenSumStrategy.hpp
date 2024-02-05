#pragma once
#include "IStrategy.hpp"
#include "Matrix.hpp"
#include <Eigen/Dense>

class EigenSumStrategy : public IStrategy {
public:
    Matrix sum(const Matrix& m1, const Matrix& m2) const override;
};
