#pragma once

#include "matrixedit.hpp"
#include <exception>

#include <vector>

typedef std::vector<std::vector<float>> matrixType;

struct LUPair;

namespace matcalc
{
    float matrixDet(matrixType);

    void pivot(matrixType &, const int);

    LUPair LUdec(matrixType); 

    matrixType matrixMul(matrixType, matrixType);

    matrixType gaussElim(matrixType);

    int matrixRank(matrixType);

    matrixType matrixTranspose(matrixType);

    void repairMatrix(matrixType &);
}