#-------------------------------------------------
#
# Project created by QtCreator 2014-11-06T10:21:06
#
#-------------------------------------------------

TEMPLATE = app

TARGET = CheckPath

DESTDIR = $$PWD/../bin

QT       += widgets core
# QT       -= gui

CONFIG   += console c++11
CONFIG   -= app_bundle

SOURCES += \
	main.cpp \
	Util.cpp

HEADERS += \
	Util.hpp

INCLUDEPATH += ../CppAidKit/headers/

