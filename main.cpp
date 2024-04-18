#include <QApplication>
#include <QWidget>

#include <QTextStream>

#include "matrixlayout.hpp"

int main(int argc, char **argv) 
{
    QApplication app(argc, argv);

    MatrixLayout window;
    window.setWindowTitle("Matrix calc");
    window.show();

    return app.exec();
}