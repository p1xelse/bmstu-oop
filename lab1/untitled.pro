QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    action_handler.cpp \
    drawing.cpp \
    edges.cpp \
    error_handler.cpp \
    figure.cpp \
    graph_scene.cpp \
    input.cpp \
    main.cpp \
    mainwindow.cpp \
    operations.cpp \
    points.cpp

HEADERS += \
    action_handler.h \
    drawing.h \
    edges.h \
    error_handler.h \
    figure.h \
    graph_scene.h \
    input.h \
    mainwindow.h \
    operations.h \
    point.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
