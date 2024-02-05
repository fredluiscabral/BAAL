// BasicSumStrategy.cpp
#include "Matrix.hpp"
#include "BasicStrategy.hpp"
#include "mtx_io.hpp"
#include <iostream>
#include <memory>
#include <omp.h>

Matrix BasicStrategy::sum(const Matrix& m1, const Matrix& m2) const {

    int TILE_SIZE; 
//    int OMP_NUM_THREADS;

    const char* tileSizeStr = std::getenv("TILE_SIZE");
//    const char* nThreadsStr = std::getenv("OMP_NUM_THREADS");

//    OMP_NUM_THREADS = std::stoi(nThreadsStr); // Converte a string para int
//    std::cout << "OMP_NUM_THREADS: " << OMP_NUM_THREADS << std::endl;
/*
    if (tileSizeStr != nullptr) { // Verifica se TILE_SIZE foi definida
        TILE_SIZE = std::stoi(tileSizeStr); // Converte a string para int
        std::cout << "TILE_SIZE: " << TILE_SIZE << "\n" << std::endl;
    } else {
        throw std::invalid_argument("Variável de ambiente TILE_SIZE não definida.");
    }
*/

    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols()) {
        throw std::invalid_argument("As dimensões das matrizes devem ser iguais.");
    }

    Matrix result(m1.getRows(), m1.getCols());
    int n_threads, start, end;

    double start_time = omp_get_wtime();
    #pragma omp parallel private(start, end, n_threads)
    {
        n_threads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();
        int rows_per_thread = m1.getRows() / n_threads;
        int remainder = m1.getRows() % n_threads;
        start = thread_id * rows_per_thread + std::min(thread_id, remainder);
        end = start + rows_per_thread + (thread_id < remainder ? 1 : 0);
        for (int i = start; i < end; i += TILE_SIZE) {
            for (int j = 0; j < m1.getCols(); j += TILE_SIZE) {
                for (int ti = i; ti < std::min(i + TILE_SIZE, end); ++ti) {
                    for (int tj = j; tj < std::min(j + TILE_SIZE, m1.getCols()); ++tj) {
                        result.setValue(ti, tj, m1.getValue(ti, tj) + m2.getValue(ti, tj));
                    }
                }
            }
        }
 
    }
    double stop_time = omp_get_wtime();
    std::cout << "Tempo de execução: " << (stop_time - start_time) << " segundos." << std::endl;

    return result;
}


Matrix BasicStrategy::multiply(const Matrix& m1, const Matrix& m2) const {
    int rows = m1.getRows();
    int cols = m2.getCols();
    Matrix result(rows, cols); // Inicializa a matriz de resultado

    double start_time = omp_get_wtime();

    #pragma omp parallel
    {
        int n_threads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();
        int rows_per_thread = rows / n_threads;
        int remainder = rows % n_threads;
        int start = thread_id * rows_per_thread + std::min(thread_id, remainder);
        int end = start + rows_per_thread + (thread_id < remainder ? 1 : 0);

        for (int i = start; i < end; ++i) {
            for (int j = 0; j < cols; ++j) {
                double sum = 0.0;
                for (int k = 0; k < m1.getCols(); ++k) {
                    sum += m1.getValue(i, k) * m2.getValue(k, j);
                }
                result.setValue(i, j, sum);
            }
        }
    }

    double stop_time = omp_get_wtime();
    std::cout << "Tempo de execução: " << (stop_time - start_time) << " segundos." << std::endl;

    return result;

}    