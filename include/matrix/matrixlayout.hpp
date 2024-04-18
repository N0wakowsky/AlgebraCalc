#pragma once

#include "matrixlayout.hpp"
#include "matrixedit.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QString>
#include <QGroupBox>
#include <QString>

class MatrixEdit;

class MatrixLayout : public QWidget {
    Q_OBJECT

public:
    MatrixLayout(QWidget *parent = nullptr);

public slots:
    void calcDetA(); 
    void calcDetB(); 

    void calcRankA(); 
    void calcRankB(); 

    void calcInvA(); 
    void calcInvB(); 

    void calcTranspA(); 
    void calcTranspB(); 

private:
    MatrixEdit *matrixAEdit;
    MatrixEdit *matrixBEdit;

    QLabel *resultDisp;
};