#include <QWidget>
#include <QFrame>
#include <QGridLayout>

#include "cursors.h"

Cursors::Cursors(QWidget *parent) : QWidget(parent) {
    auto *frame1 = new QFrame(this);
    frame1 -> setFrameStyle(QFrame::Box);
    frame1 -> setCursor(Qt::SizeAllCursor);

    auto *frame2 = new QFrame(this);
    frame2 -> setFrameStyle(QFrame::Box);
    frame2 -> setCursor(Qt::WaitCursor);

    auto *frame3 = new QFrame(this);
    frame3 -> setFrameStyle(QFrame::Box);
    frame3 -> setCursor(Qt::CrossCursor);

    auto *grid = new QGridLayout(this);
    grid -> addWidget(frame1, 0, 0);
    grid -> addWidget(frame2, 1, 0);
    grid -> addWidget(frame3, 2, 0);

    setLayout(grid);
}
