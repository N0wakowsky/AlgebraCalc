#pragma once
#include "matrixedit.hpp"

#include <QTextEdit>
#include <QLineEdit>
#include <QWidget>
#include <QString>
#include <QGroupBox>

class MatrixEdit : public QWidget {
    Q_OBJECT

public:
    MatrixEdit(QWidget *parent = nullptr);
    std::vector<std::vector<float>> getMatrixToVec();

public slots:
    void callDetCalc();
        
private:
    QString getMatrixFromTextEdit();
    QTextEdit *_matrixEdit;
};