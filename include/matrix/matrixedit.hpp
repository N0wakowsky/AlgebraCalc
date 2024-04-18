#pragma once
#include "matrixedit.hpp"
#include "matrixcalc.hpp"
#include "matrixlayout.hpp"

#include <QTextEdit>

class MatrixEdit : public QWidget {
    Q_OBJECT

public:
    MatrixEdit(QWidget *parent = nullptr);
    std::vector<std::vector<float>> getMatrixToVec();
        
private:
    QString getMatrixFromTextEdit();
    QTextEdit *textMatrix;
};