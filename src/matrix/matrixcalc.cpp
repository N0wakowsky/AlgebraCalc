#include "matrixcalc.hpp"

#include <vector>

float determinantCalc(std::vector<std::vector<float>> matrix) {

    // check matrix size corectness
    for (auto row: matrix) {
        if (row.size() != matrix.size()) {
            return NULL;
        }
    }

    // 2x2 matrix det

    if (matrix.size() == 2) {
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }


}

std::vector<std::vector<float>> LUdecompostion(std::vector<std::vector<float>> matrix) {
    
    std::vector<std::vector<float>> L(matrix.size(), std::vector<float>(matrix.size(), 0));
    std::vector<std::vector<float>> U(matrix.size(), std::vector<float>(matrix.size(), 0));

    
}