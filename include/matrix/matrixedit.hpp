#pragma once
#include "matrixedit.hpp"
#include "matrixcalc.hpp"
#include "matrixlayout.hpp"

#include <QTextEdit>

typedef std::vector<std::vector<float>> matrixType;

class MatrixEdit : public QWidget {
    Q_OBJECT

public:
    MatrixEdit(QWidget *parent = nullptr);
    matrixType getMatrixToVec();
    static QString getMatrixToQString(matrixType);
        
private:
    QString getMatrixFromTextEdit();
    QTextEdit *textMatrix;
};