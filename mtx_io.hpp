// mtx_io.hpp
#pragma once
#include "Matrix.hpp"
#include <string>

Matrix readMatrixFromMTX(const std::string& filename);
void writeMatrixToMTX(const std::string& filename, const Matrix& matrix);
