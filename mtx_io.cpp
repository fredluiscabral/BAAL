// mtx_io.cpp
#include "mtx_io.hpp"
#include <fstream>
#include <sstream>
#include <string>

Matrix readMatrixFromMTX(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '%') continue; // Ignora comentários e linhas vazias
        break;
    }

    int rows, cols, entries;
    std::istringstream iss(line);
    iss >> rows >> cols >> entries;

    Matrix matrix(rows, cols);
    int row, col;
    double value;
    while (file >> row >> col >> value) {
        matrix.setValue(row - 1, col - 1, value); // Ajusta para índice base-0
    }

    return matrix;
}

void writeMatrixToMTX(const std::string& filename, const Matrix& matrix) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo " + filename);
    }

    // Escreve o cabeçalho .mtx (ignorando o total de entradas não-nulas por simplicidade)
    file << matrix.getRows() << " " << matrix.getCols() << " " << matrix.getRows() * matrix.getCols() << "\n";

    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            double value = matrix.getValue(i, j);
            if (value != 0) { // Opcional: escrever apenas entradas não-nulas
                file << i + 1 << " " << j + 1 << " " << value << "\n"; // Ajuste para índice base-1
            }
        }
    }
}
