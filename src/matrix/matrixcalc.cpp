#include "matrixcalc.hpp"

#include <vector>

struct LUPair
{
    std::vector<std::vector<float>> L;
    std::vector<std::vector<float>> U;
    int sign = 1;
};


void pivot(std::vector<std::vector<float>> &matrix, const uint rowToSwitch) 
{
    uint idx = 0;
    const uint col = rowToSwitch;
    float biggestElem = 0;
    for (uint row = 0; row < matrix.size(); row++) 
    {
        if (std::abs(matrix[row][col]) > biggestElem) 
        {
            biggestElem = matrix[row][col];
            idx = row;
        }
    }

    std::vector<float> buff = matrix[rowToSwitch];
    matrix[rowToSwitch] = matrix[idx];
    matrix[idx] = buff;
}


LUPair LUdec(std::vector<std::vector<float>> matrix) 
{
    std::vector<std::vector<float>> L(matrix.size(), std::vector<float>(matrix.size(), 0));
    std::vector<std::vector<float>> U(matrix);

    LUPair pair;

    for (uint i = 0; i < matrix.size(); i++) {
        L[i][i] = 1;
    }

    for (uint row = 0; row < matrix.size() -1; row++) {
        for (uint col = row+1; col < matrix.size(); col++) {
            if (U[row][row] == 0)
            {
                pivot(U, row);
                pair.sign *= -1;
            }
            L[col][row] = U[col][row] / U[row][row];
                
            for (uint i = 0; i < matrix.size(); i++) {
                U[col][i] -= L[col][row] * U[row][i];
            }                
        }
    }

    pair.L = L;
    pair.U = U;

    return pair;
}

float matrixDet(std::vector<std::vector<float>> matrix)
{
    LUPair LUdecomposition = LUdec(matrix);
    std::vector<std::vector<float>> matrixU = LUdecomposition.U;
    int sign = LUdecomposition.sign;

    float det = 1;

    for (uint i = 0; i < matrix.size(); i++) 
    {
        det *= matrixU[i][i];
    }

    det *= sign;

    return det;
}