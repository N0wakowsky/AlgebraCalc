#ifndef BOOK_
#define BOOK_

#include <QtCore>

class Book {
    public:
        Book(QString, QString);
        QString get_author() const;
        QString get_title() const;
    private:
        QString author;
        QString title;
};

#endif /* BOOK_ */