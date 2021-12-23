QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    generatemaze.cpp \
    introduction.cpp \
    level_low.cpp \
    main.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    setting.cpp \
    startgame.cpp

HEADERS += \
    generatemaze.h \
    introduction.h \
    level_low.h \
    mainwidget.h \
    mainwindow.h \
    setting.h \
    startgame.h

FORMS += \
    introduction.ui \
    level_low.ui \
    mainwidget.ui \
    mainwindow.ui \
    setting.ui \
    startgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

