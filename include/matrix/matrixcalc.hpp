#pragma once

#include "matrixedit.hpp"

#include <vector>

struct LUPair;

float matrixDet(std::vector<std::vector<float>>);

void pivot(std::vector<std::vector<float>>&, const uint);

LUPair LUdec(std::vector<std::vector<float>>); 