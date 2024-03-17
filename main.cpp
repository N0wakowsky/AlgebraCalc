#include <QWidget>
#include <QApplication>
#include <QGridLayout>
#include <QFrame>

#include "book.h"
#include "cursors.h"
#include "mybutton.h"
#include "plusminus.h"


int main(int argc, char **argv) {
    
    QApplication app(argc, argv);
    
    PlusMinus window;

    window.resize(300, 250);
    window.setWindowTitle("plusminus");
    window.show();

    return app.exec();
}