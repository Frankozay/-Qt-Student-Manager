#-------------------------------------------------
#
# Project created by QtCreator 2019-06-06T15:40:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = student_project
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    globle.cpp \
    manager.cpp \
    user_insert.cpp \
    user_manage.cpp \
    user_delete.cpp \
    user_changepassword.cpp \
    stuinfor_manage.cpp \
    allstuinfor.cpp \
    course_manage.cpp \
    allcourses.cpp \
    sc_manage.cpp \
    allsc.cpp \
    user_stupass.cpp \
    allpassword.cpp \
    student.cpp \
    stu_changepass.cpp \
    stu_inforquery.cpp \
    stu_scorequery.cpp \
    all_grade.cpp \
    stu_coursequery.cpp \
    all_stucourses.cpp

HEADERS += \
        mainwindow.h \
    globle.h \
    manager.h \
    user_insert.h \
    user_manage.h \
    user_delete.h \
    user_changepassword.h \
    stuinfor_manage.h \
    allstuinfor.h \
    course_manage.h \
    allcourses.h \
    sc_manage.h \
    allsc.h \
    user_stupass.h \
    allpassword.h \
    student.h \
    stu_changepass.h \
    stu_inforquery.h \
    stu_scorequery.h \
    all_grade.h \
    stu_coursequery.h \
    all_stucourses.h

FORMS += \
        mainwindow.ui \
    manager.ui \
    user_manage.ui \
    user_changepassword.ui \
    user_delete.ui \
    user_insert.ui \
    stuinfor_manage.ui \
    allstuinfor.ui \
    course_manage.ui \
    allcourses.ui \
    sc_manage.ui \
    allsc.ui \
    student.ui \
    user_stupass.ui \
    allpassword.ui \
    stu_changepass.ui \
    stu_inforquery.ui \
    stu_scorequery.ui \
    all_grade.ui \
    stu_coursequery.ui \
    all_stucourses.ui

QT          += sql
