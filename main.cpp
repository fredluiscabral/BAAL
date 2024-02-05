// main.cpp
#include "Matrix.hpp"
#include "BasicStrategy.hpp"
#include "EigenSumStrategy.hpp" 
#include "mtx_io.hpp"
#include <iostream>
#include <memory>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_entrada_matriz1> <arquivo_entrada_matriz2> <arquivo_saida_soma>" << std::endl;
        return 1;
    }

    try {
        Matrix m1 = readMatrixFromMTX(argv[1]);
        Matrix m2 = readMatrixFromMTX(argv[2]);

        BasicStrategy basicStrategy;

        Matrix resultSum = basicStrategy.sum(m1, m2);
        std::cout << "Soma concluída usando a estratégia básica.\n" << std::endl;
        std::string sumFileName = std::string(argv[3]) + "Soma.mtx";
        writeMatrixToMTX(sumFileName.c_str(), resultSum);

        Matrix resultMultiply = basicStrategy.multiply(m1, m2);
        std::cout << "Multiplicação concluída usando a estratégia básica.\n" << std::endl;
        std::string multFileName = std::string(argv[3]) + "Mult.mtx";
        writeMatrixToMTX(multFileName.c_str(), resultMultiply);

        // Soma usando a estratégia Eigen
        /*
        EigenSumStrategy eigenStrategy;
        Matrix resultEigen = eigenStrategy.sum(m1, m2);
        std::cout << "Soma concluída usando a estratégia Eigen." << std::endl;

        std::unique_ptr<ISumStrategy> sumStrategy = std::make_unique<BasicSumStrategy>();
        Matrix result = sumStrategy->sum(m1, m2);
        */
    

    } catch (const std::exception& e) {
    }
}
