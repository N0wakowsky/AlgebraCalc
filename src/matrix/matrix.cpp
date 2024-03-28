#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>

#include "matrix.hpp"
#include "matrixedit.hpp"

Matrix::Matrix(QWidget *parent) : QWidget(parent) { 

    createMatrixBox("Matrix A", matrixALayout);
    createMatrixBox("Matrix B", matrixBLayout);

    QGridLayout *matrixCalcLayout = new QGridLayout();

    matrixCalcLayout->addWidget(matrixALayout, 0, 0);
    matrixCalcLayout->addWidget(matrixBLayout, 0, 1);

    _result = new QLabel("result", this);

    matrixCalcLayout->addWidget(_result, 1, 1);
    
    setLayout(matrixCalcLayout);
}  

void Matrix::createMatrixBox(QString boxLabel, QGroupBox *&dest) {
    dest = new QGroupBox();
    QLabel *label = new QLabel(boxLabel);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);

    MatrixEdit *matrixEdit = new MatrixEdit();

    layout->addWidget(matrixEdit);

    QGridLayout *optionLayout = new QGridLayout();

    QPushButton *detButton = new QPushButton("Determinant", this);
    QPushButton *invButton = new QPushButton("Inverse");
    QPushButton *transpButton = new QPushButton("Transposition");
    QPushButton *rankButton = new QPushButton("Rank");

    optionLayout->addWidget(detButton, 0, 0);
    optionLayout->addWidget(invButton, 0, 1);
    optionLayout->addWidget(transpButton, 1, 0);
    optionLayout->addWidget(rankButton, 1, 1);

    connect(detButton, &QPushButton::clicked, matrixEdit, &MatrixEdit::callDetCalc);

    layout->addLayout(optionLayout);

    dest->setLayout(layout);
}  