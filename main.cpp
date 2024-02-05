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

    std::cout << "Iniciando Baal ..." << "\n\n";

    int TILE_SIZE; 
    int OMP_NUM_THREADS;

    const char* tileSizeStr = std::getenv("TILE_SIZE");
    const char* nThreadsStr = std::getenv("OMP_NUM_THREADS");

    if (tileSizeStr != nullptr) { // Verifica se TILE_SIZE foi definida
        TILE_SIZE = std::stoi(tileSizeStr); // Converte a string para int
        std::cout << "TILE_SIZE: " << TILE_SIZE  << std::endl;
    } else {
        throw std::invalid_argument("Variável de ambiente TILE_SIZE não definida.");
    }

    if (nThreadsStr != nullptr) { // Verifica se TILE_SIZE foi definida
        OMP_NUM_THREADS = std::stoi(nThreadsStr); // Converte a string para int
        std::cout << "OMP_NUM_THREADS: " << OMP_NUM_THREADS << "\n" << std::endl;
    } else {
        throw std::invalid_argument("Variável de ambiente OMP_NUM_THREADS não definida.");
    }

    try {
        Matrix m1 = readMatrixFromMTX(argv[1]);
        Matrix m2 = readMatrixFromMTX(argv[2]);

        BasicStrategy basicStrategy;

        std::cout << "Iniciando a Soma com a estratégia básica.\n" << std::endl;
        Matrix resultSum = basicStrategy.sum(m1, m2);
        std::cout << "Soma concluída usando a estratégia básica.\n" << std::endl;
        std::string sumFileName = std::string(argv[3]) + "Soma.mtx";
        //writeMatrixToMTX(sumFileName.c_str(), resultSum);

        std::cout << "Iniciando a multiplicacao com a estratégia básica.\n" << std::endl;
        Matrix resultMultiply = basicStrategy.multiply(m1, m2);
        std::cout << "Multiplicação concluída usando a estratégia básica.\n" << std::endl;
        std::string multFileName = std::string(argv[3]) + "Mult.mtx";
        //writeMatrixToMTX(multFileName.c_str(), resultMultiply);

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
