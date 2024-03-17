#ifndef MY_BUTTON_
#define MY_BUTTON_

#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include "mybutton.h"

class MyButton : public QWidget {
    public:
        MyButton(QWidget *parent = nullptr);
};

#endif /* MY_BUTTON_ */