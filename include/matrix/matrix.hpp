#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QString>
#include <QGroupBox>

class Matrix : public QWidget {
    Q_OBJECT

public:
    Matrix(QWidget *parent = nullptr);

private:
    void createMatrixBox(QString boxLabel, QGroupBox *&destination);

    QGroupBox *matrixALayout;
    QGroupBox *matrixBLayout;

    QLabel *_result;
};