TEMPLATE = app
TARGET = AlgebraicGod
INCLUDEPATH += . ./include ./include/matrix ./src ./src/matrix
QT += widgets gui core printsupport

# Input
HEADERS +=  include/matrix/matrixlayout.hpp \
            include/matrix/matrixedit.hpp \
            include/matrix/matrixcalc.hpp

SOURCES +=  main.cpp \
            src/matrix/matrixlayout.cpp \
            src/matrix/matrixedit.cpp \
            src/matrix/matrixcalc.cpp
