#include "matrixedit.hpp"
#include "matrixcalc.hpp"

#include <QTextStream>
#include <QTextEdit>
#include <QPushButton>
#include <QString>
#include <QLayout>

#include <vector>
#include <iostream>

MatrixEdit::MatrixEdit(QWidget *parent) : QWidget(parent){
    QGridLayout *layout = new QGridLayout();

    _matrixEdit = new QTextEdit(QString("Type matrix")); 
    layout->addWidget(_matrixEdit);
    
    setLayout(layout);
}

QString MatrixEdit::getMatrixFromTextEdit() {   
    return _matrixEdit->toPlainText();
}

std::vector<std::vector<float>> MatrixEdit::getMatrixToVec() {
    QString qStringMatrix = getMatrixFromTextEdit();

    std::vector<std::vector<float>> matrixVec;
    QStringList matrixSplitLines = qStringMatrix.split("\n");

    for (QString line: matrixSplitLines) 
    {
        QStringList lineElems = line.split(' ', Qt::SkipEmptyParts);
        std::vector<float> lineElemsFloat;

        for (QString str: lineElems) 
        {
            lineElemsFloat.push_back(std::stof(str.toStdString()));
        }
        matrixVec.push_back(lineElemsFloat);
    }

    return matrixVec;
}

void MatrixEdit::callDetCalc() {
    std::vector<std::vector<float>> matrix = getMatrixToVec();

    // adding zeros, if a row is shorter than other
    for (auto line: matrix)
    {
        while (line.size() < matrix.size())
        {
            line.push_back(0);
        }
    }

    float det = matrixDet(matrix);
}
