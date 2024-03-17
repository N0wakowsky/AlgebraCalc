#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QWidget(parent) {
    auto *quitButn = new QPushButton("QUIT", this);
    quitButn->setGeometry(100,100,75,30);

    /*
    auto *download = new QPushButton("Download", this);
    download->setGeometry(100,150,90,30);
    */
   
    connect(quitButn, &QPushButton::clicked, qApp, QApplication::quit);
}