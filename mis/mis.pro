#-------------------------------------------------
#
# Project created by QtCreator 2019-05-24T11:50:20
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    user_main.cpp \
    competition_information.cpp \
    score_inquiry.cpp \
    score_inquiry_all.cpp \
    teacher_main.cpp \
    competition_information_release.cpp \
    competition_information_teacher.cpp \
    admin_main.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    user_main.h \
    competition_information.h \
    score_inquiry.h \
    score_inquiry_all.h \
    teacher_main.h \
    competition_information_release.h \
    competition_information_teacher.h \
    admin_main.h

FORMS    += mainwindow.ui \
    dialog.ui \
    user_main.ui \
    competition_information.ui \
    score_inquiry.ui \
    score_inquiry_all.ui \
    teacher_main.ui \
    competition_information_release.ui \
    competition_information_teacher.ui \
    admin_main.ui
