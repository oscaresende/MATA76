#-------------------------------------------------
#
# Project created by QtCreator 2018-10-24T21:25:14
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += core gui multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = academiaUfba
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    addaluno.cpp \
    dbmanager.cpp \
    aluno.cpp \
    professor.cpp \
    addpro.cpp \
    exercicio.cpp \
    addexercicio.cpp \
    treino.cpp \
    addtreino.cpp \
    removeraluno.cpp \
    login.cpp \
    itemtreino.cpp \
    removerexercicio.cpp \
    removerprofessor.cpp \
    atualizaraluno.cpp \
    atualizarprofessor.cpp \
    atualizarexercicio.cpp

HEADERS += \
        mainwindow.h \
    addaluno.h \
    dbmanager.h \
    aluno.h \
    professor.h \
    addpro.h \
    exercicio.h \
    addexercicio.h \
    treino.h \
    addtreino.h \
    removeraluno.h \
    login.h \
    itemtreino.h \
    removerexercicio.h \
    removerprofessor.h \
    atualizaraluno.h \
    atualizarprofessor.h \
    atualizarexercicio.h

FORMS += \
        mainwindow.ui \
    addaluno.ui \
    addpro.ui \
    addexercicio.ui \
    addtreino.ui \
    removeraluno.ui \
    login.ui \
    removerexercicio.ui \
    removerprofessor.ui \
    atualizaraluno.ui \
    atualizarprofessor.ui \
    atualizarexercicio.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
