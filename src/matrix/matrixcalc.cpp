#include "matrixcalc.hpp"

#include <vector>

struct LUPair
{
    matrixType L;
    matrixType U;
    int sign = 1;
};


void matcalc::pivot(matrixType &matrix, const int rowToSwitch) 
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


LUPair matcalc::LUdec(matrixType matrix) 
{
    matrixType L(matrix.size(), std::vector<float>(matrix.size(), 0));
    matrixType U(matrix);

    LUPair pair;

    for (uint i = 0; i < matrix.size(); i++) {
        L[i][i] = 1;
    }

    for (uint row = 0; row < matrix.size() - 1; row++) {
        for (uint col = row + 1; col < matrix.size(); col++) {
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

float matcalc::matrixDet(matrixType matrix)
{
    LUPair LUdecomposition = LUdec(matrix);
    matrixType matrixU = LUdecomposition.U;
    int sign = LUdecomposition.sign;

    float det = 1;

    for (uint i = 0; i < matrix.size(); i++) 
    {
        det *= matrixU[i][i];
    }

    det *= sign;

    return det;
}

// TODO: upewnic sie że działa dla każdego przypadku
matrixType matcalc::matrixMul(matrixType matrixA, matrixType matrixB)
{
    if (matrixA.size() == matrixB[0].size() && matrixA.size() == matrixB[0].size())
    {
        matrixType result(matrixA.size(), std::vector<float>(matrixB[0].size(), 0));

        for (uint i = 0; i < matrixA.size(); i++)
        {
            for (uint j = 0; j < matrixA.size(); j++)
            {
                for (uint k = 0; k < matrixB.size(); k++)
                {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        return result;
    }
    exit(EXIT_FAILURE);
}

matrixType matcalc::gaussElim(matrixType matrix)
{
    uint matSize = matrix.size();

    for (uint col = 0; col < matSize - 1; col++)
    {
        for (uint row = col + 1; row < matSize; row++)
        {
            if (matrix[col][col] == 0)
            {
                pivot(matrix, col);
            }

            float scal = matrix[row][col] / matrix[col][col];

            for (uint k = 0; k < matSize; k++)
            {
                matrix[row][k] -= scal * matrix[col][k];
            }
        }
    }
    return matrix;
}

int matcalc::matrixRank(matrixType matrix)
{
    matrixType mat = gaussElim(matrix);

    int rank = 0;

    for (auto line: mat)
    {
        auto it = std::find_if(line.begin(), line.end(), [](float num) { return num != 0.0; });

        if (it != line.end())
            rank++;
    }
    return rank;
}