#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QString>
#include <QGroupBox>
#include <QString>

class Matrix : public QWidget {
    Q_OBJECT
    friend class MatrixEdit;

    static void setResult(float number) { return resultDisp->setText(QString::number(number)); }

public:
    Matrix(QWidget *parent = nullptr);

private:
    void createMatrixBox(QString boxLabel, QGroupBox *&destination);

    QGroupBox *matrixALayout;
    QGroupBox *matrixBLayout;

    static QLabel *resultDisp;
};