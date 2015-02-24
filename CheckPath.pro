#-------------------------------------------------
#
# Project created by QtCreator 2014-11-06T10:21:06
#
#-------------------------------------------------

TEMPLATE = subdirs

SUBDIRS += ./src/main.pro ../CppAidKit/AidKit.pro \
    test

main.pro.depends = AidKit.pro
