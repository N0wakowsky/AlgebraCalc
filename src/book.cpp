#include "book.h"

#include <QString>

Book::Book(QString auth, QString titl) {
    author = auth;
    title = titl;
}

QString Book::get_author() const {
    return author;
}

QString Book::get_title() const {
    return title;
}

