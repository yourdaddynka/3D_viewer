QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17
ICON = img/app_icon.png

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../modules/source/affine_transformations.c \
    ../../modules/source/parser.c \
    main.cpp \
    mainwindow.cpp \
    my_ogl_widget.cpp

HEADERS += \
    ../../modules/header/modules.h \
    gif.h \
    mainwindow.h \
    my_ogl_widget.h

FORMS += \
    mainwindow.ui

CONFIG += lrelease

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
