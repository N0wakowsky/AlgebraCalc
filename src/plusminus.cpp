#include <QGridLayout>
#include <QWidget>
#include <QPushButton>

#include "plusminus.h"

#include "plusminus.moc"

PlusMinus::PlusMinus(QWidget *parent) : QWidget(parent) {
    auto *plusBtn = new QPushButton("+", this);
    auto *minusBtn = new QPushButton("-", this);
    lbl = new QLabel("0", this);

    auto *grid = new QGridLayout(this);
    grid->addWidget(plusBtn, 0, 0);
    grid->addWidget(minusBtn, 0, 1);
    grid->addWidget(lbl, 1, 1);

    setLayout(grid);

    connect(plusBtn, &QPushButton::clicked, this, &PlusMinus::OnPlus);
    connect(minusBtn, &QPushButton::clicked, this, &PlusMinus::OnMinus);
}

void PlusMinus::OnPlus() {
    int val = lbl->text().toInt();
    val++;
    lbl->setText(QString::number(val));
}
void PlusMinus::OnMinus() {
    int val = lbl->text().toInt();
    val--;
    lbl->setText(QString::number(val));
}