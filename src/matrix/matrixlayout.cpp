#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>

#include "matrixlayout.hpp"
#include "matrixedit.hpp"
#include "matrixcalc.hpp"


MatrixLayout::MatrixLayout(QWidget *parent) : QWidget(parent) 
{   
    QGridLayout *matrixCalcLayout = new QGridLayout();

    matrixAEdit = new MatrixEdit();
    matrixBEdit = new MatrixEdit();

    QGridLayout *matrixAButtons = new QGridLayout();
    QGridLayout *matrixBButtons = new QGridLayout();


    QPushButton *detAButton = new QPushButton("Determinant", this);
    QPushButton *invAButton = new QPushButton("Inverse", this);
    QPushButton *transpAButton = new QPushButton("Transposition", this);
    QPushButton *rankAButton = new QPushButton("Rank", this);

    QPushButton *detBButton = new QPushButton("Determinant", this);
    QPushButton *invBButton = new QPushButton("Inverse", this);
    QPushButton *transpBButton = new QPushButton("Transposition", this);
    QPushButton *rankBButton = new QPushButton("Rank", this);


    matrixAButtons->addWidget(detAButton, 0, 0);
    matrixAButtons->addWidget(invAButton, 0, 1);
    matrixAButtons->addWidget(transpAButton, 1, 0);
    matrixAButtons->addWidget(rankAButton, 1, 1);

    connect(detAButton, &QPushButton::clicked, this, &MatrixLayout::calcDetA);
    connect(invAButton, &QPushButton::clicked, this, &MatrixLayout::calcInvA);
    connect(transpAButton, &QPushButton::clicked, this, &MatrixLayout::calcTranspA);
    connect(rankAButton, &QPushButton::clicked, this, &MatrixLayout::calcRankA);


    matrixBButtons->addWidget(detBButton, 0, 0);
    matrixBButtons->addWidget(invBButton, 0, 1);
    matrixBButtons->addWidget(transpBButton, 1, 0);
    matrixBButtons->addWidget(rankBButton, 1, 1);

    connect(detBButton, &QPushButton::clicked, this, &MatrixLayout::calcDetB);
    connect(invBButton, &QPushButton::clicked, this, &MatrixLayout::calcInvB);
    connect(transpBButton, &QPushButton::clicked, this, &MatrixLayout::calcTranspB);
    connect(rankBButton, &QPushButton::clicked, this, &MatrixLayout::calcRankB);


    matrixCalcLayout->addWidget(matrixAEdit, 0, 0);
    matrixCalcLayout->addWidget(matrixBEdit, 0, 1);

    matrixCalcLayout->addLayout(matrixAButtons, 2, 0);
    matrixCalcLayout->addLayout(matrixBButtons, 2, 1);

    resultDisp = new QLabel("", this);

    matrixCalcLayout->addWidget(resultDisp, 4, 1, 4, 2);
    
    setLayout(matrixCalcLayout);
}  

// TODO: wprowadzić obsługe wyjątków
 
void MatrixLayout::calcDetA()
{   
    try
    {
        matrixType matA = matrixAEdit->getMatrixToVec();
        float detA = matcalc::matrixDet(matA);
        resultDisp->setText(QString::number(detA));
    }
    catch (const std::string &e)
    {
        resultDisp->setText(QString::fromStdString(e));
    }
    catch (const std::invalid_argument &e)
    {
        resultDisp->setText(QString("Incorrect input data"));
    }
}

void MatrixLayout::calcDetB()
{
    try
    {
        matrixType matB = matrixBEdit->getMatrixToVec();
        float detB = matcalc::matrixDet(matB);
        resultDisp->setText(QString::number(detB));
    }
    catch (const std::string &e)
    {
        resultDisp->setText(QString::fromStdString(e));
    }
    catch (const std::invalid_argument &e)
    {
        resultDisp->setText(QString("Incorrect input data"));
    }
}

void MatrixLayout::calcRankA()
{
    try
    {
        matrixType matA = matrixAEdit->getMatrixToVec();
        if (matA.size() == 0)
            throw std::string("No given matrix");

        int rankA = matcalc::matrixRank(matA);
        resultDisp->setText(QString::number(rankA));
    }
    catch (const std::invalid_argument &e)
    {
        resultDisp->setText(QString("Incorrect input data"));
    }
    catch (const std::string &e)
    {
        resultDisp->setText(QString::fromStdString(e));
    }
}

void MatrixLayout::calcRankB()
{
    try
    {
        matrixType matB = matrixBEdit->getMatrixToVec();
        if (matB.size() == 0)
            throw std::string("No given matrix");
            
        int rankB = matcalc::matrixRank(matB);
        resultDisp->setText(QString::number(rankB));
    }
    catch (const std::invalid_argument &e)
    {
        resultDisp->setText(QString("Incorrect input data"));
    }
    catch (const std::string &e)
    {
        resultDisp->setText(QString::fromStdString(e));
    }
}

void MatrixLayout::calcInvA()
{

} 

void MatrixLayout::calcInvB()
{

}

void MatrixLayout::calcTranspA()
{
    matrixType matA = matrixAEdit->getMatrixToVec();
    matrixType matAT = matcalc::matrixTranspose(matA);
    QString QStrMatAT = MatrixEdit::getMatrixToQString(matAT);
    resultDisp->setText(QStrMatAT);
}

void MatrixLayout::calcTranspB()
{
    matrixType matB = matrixBEdit->getMatrixToVec();
    matrixType matBT = matcalc::matrixTranspose(matB);
    QString QStrMatBT = MatrixEdit::getMatrixToQString(matBT);
    resultDisp->setText(QStrMatBT);
}