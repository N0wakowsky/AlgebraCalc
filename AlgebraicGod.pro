TEMPLATE = app
TARGET = AlgebraicGod
INCLUDEPATH += . ./include ./include/matrix
QT += widgets gui core printsupport

# Input
HEADERS +=  include/matrix/matrix.hpp \
            include/matrix/matrixedit.hpp

SOURCES +=  main.cpp \
            src/matrix/matrix.cpp \
            src/matrix/matrixedit.cpp
