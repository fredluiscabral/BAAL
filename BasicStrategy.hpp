// BasicSumStrategy.hpp
#pragma once
#include "IStrategy.hpp"

class BasicStrategy : public IStrategy {
public:
    Matrix sum(const Matrix& m1, const Matrix& m2) const override;
    Matrix multiply(const Matrix& m1, const Matrix& m2) const override;
};
