#include "matrixcalc.hpp"

#include <QLayout>

#include <vector>
#include <string>

MatrixEdit::MatrixEdit(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout();

    textMatrix = new QTextEdit(QString("Type matrix"));
    layout->addWidget(textMatrix);

    setLayout(layout);
}

QString MatrixEdit::getMatrixFromTextEdit()
{
    return textMatrix->toPlainText();
}

matrixType MatrixEdit::getMatrixToVec()
{
    QString qStringMatrix = getMatrixFromTextEdit();

    matrixType matrixVec;
    QStringList matrixSplitLines = qStringMatrix.split("\n");

    for (QString line : matrixSplitLines)
    {
        QStringList lineElems = line.split(' ', Qt::SkipEmptyParts);
        std::vector<float> lineElemsFloat;

        for (QString str : lineElems)
        {
            lineElemsFloat.push_back(std::stof(str.toStdString()));
        }
        matrixVec.push_back(lineElemsFloat);
    }

    return matrixVec;
}

QString MatrixEdit::getMatrixToQString(matrixType matrix)
{   
    QString qStrMat;

    for (auto row: matrix)
    {
        for (auto i: row)
        {
            qStrMat.append(QString::number(i));
            qStrMat.append(' ');
        }
        qStrMat.append('\n');
    }

    return qStrMat;
}