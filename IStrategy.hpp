// ISumStrategy.hpp
#pragma once
#include "Matrix.hpp"

class IStrategy {
public:
    virtual ~IStrategy() = default;
    virtual Matrix sum(const Matrix& m1, const Matrix& m2) const = 0;
    virtual Matrix multiply(const Matrix& m1, const Matrix& m2) const = 0; // Adicionado
};