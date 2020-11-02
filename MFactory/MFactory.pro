QT       += core gui
QT       +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG +=console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addemployee.cpp \
    main.cpp \
    mainwindow.cpp \
    search.cpp \
    stat.cpp

HEADERS += \
    addemployee.h \
    mainwindow.h \
    search.h \
    stat.h

FORMS += \
    addemployee.ui \
    mainwindow.ui \
    search.ui \
    stat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../../../Desktop/Project.Pas/qt_test/Emoji.qrc \
    Resources.qrc
