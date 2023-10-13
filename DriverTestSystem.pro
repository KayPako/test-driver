QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cmd_proto.cpp \
    concrete_transport.cpp \
    drivertester.cpp \
    ecom_transport.cpp \
    line_device.cpp \
    logfilemanager.cpp \
    main.cpp \
    mainwindow.cpp \
    module_base.cpp \
    module_task.cpp \
    testlinedevice.cpp \
    transport.cpp

HEADERS += \
    base_types_impl.h \
    cmd_proto.h \
    concrete_transport.h \
    drivertester.h \
    ecom_transport.h \
    errors.h \
    line_device.h \
    logfilemanager.h \
    mainwindow.h \
    module_base.h \
    module_task.h \
    register.h \
    testlinedevice.h \
    transport.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
