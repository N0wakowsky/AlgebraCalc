#include <QApplication>
#include <QWidget>

#include <QTextStream>

#include "matrix.hpp"

int main(int argc, char **argv) 
{
    QApplication app(argc, argv);

    Matrix window;
    window.setWindowTitle("Matrix calc");
    window.show();

    return app.exec();
}