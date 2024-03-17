#ifndef PLUS_MINUS_
#define PLUS_MINUS_

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "plusminus.h"


class PlusMinus : public QWidget {

    Q_OBJECT

    public:
        PlusMinus(QWidget *parent = nullptr);
        ~PlusMinus() {};

    private slots:
        void OnPlus();
        void OnMinus();

    private:
        QLabel *lbl;
};



#endif