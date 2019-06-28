#-------------------------------------------------
#
# Project created by QtCreator 2019-05-06T14:40:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dnp3_test
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
        dnp3_dds.cxx \
        dnp3_ddsPlugin.cxx \
        #dnp3_dds_publisher.cxx \
        #dnp3_dds_subscriber.cxx \
        getmodbus.cpp \
        main.cpp \
        mainwindow.cpp \
        master.cpp \
        ooodds.cpp \
        outstation.cpp

HEADERS += \
        #../dnp3/cpp/libs/include/asiodnp3/ConsoleLogger.h \
        #../dnp3/cpp/libs/include/asiodnp3/DNP3Manager.h \
        #../dnp3/cpp/libs/include/asiodnp3/DatabaseConfig.h \
        #../dnp3/cpp/libs/include/asiodnp3/DefaultMasterApplication.h \
        #../dnp3/cpp/libs/include/asiodnp3/PrintingChannelListener.h \
        #../dnp3/cpp/libs/include/asiodnp3/PrintingCommandCallback.h \
        #../dnp3/cpp/libs/include/asiodnp3/PrintingSOEHandler.h \
        #../dnp3/cpp/libs/include/asiodnp3/UpdateBuilder.h \
        #../dnp3/cpp/libs/include/asiopal/UTCTimeSource.h \
        #../dnp3/cpp/libs/include/libmodbus/src/modbus.h \
        #../dnp3/cpp/libs/include/opendnp3/LogLevels.h \
        #../dnp3/cpp/libs/include/opendnp3/outstation/IUpdateHandler.h \
        #../dnp3/cpp/libs/include/opendnp3/outstation/SimpleCommandHandler.h \
        #../dnp3/cpp/libs/include/openpal/container/Array.h \
        #../dnp3/cpp/libs/include/openpal/container/ArrayView.h \
        dnp3_dds.hpp \
        dnp3_ddsPlugin.hpp \
        getmodbus.h \
        mainwindow.h \
        master.h \
        ooodds.h \
        outstation.h

FORMS += \
        mainwindow.ui

#LIBS += -lasiodnp3 -lasiopal -lopendnp3 -lopenpal
LIBS += -lQt5SerialPort -lQt5SerialBus
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lasiodnp3
INCLUDEPATH += $$PWD/../../../usr/local/include/asiodnp3
DEPENDPATH += $$PWD/../../../usr/local/include/asiodnp3

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lasiopal
INCLUDEPATH += $$PWD/../../../usr/local/include/asiopal
DEPENDPATH += $$PWD/../../../usr/local/include/asiopal

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/ -lopendnp3
INCLUDEPATH += $$PWD/../../../usr/local/include/opendnp3
DEPENDPATH += $$PWD/../../../usr/local/include/opendnp3

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lopenpal
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lopenpal
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lopenpal
INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

CONFIG += no_keywords

DISTFILES += \
    dnp3_dds.idl
NDDSHOME = /home/shun/rti_connext_dds-5.3.1
TARGET_ARCH = x64Linux3gcc5.4.0
SYSLIBS = -ldl -lnsl -lm -lpthread -lrt
#LIBS += -L$(NDDSHOME)/lib/$(TARGET_ARCH) \
#        -lnddsc$(SHAREDLIB_SFX)$(DEBUG_SFX) -lnddscore$(SHAREDLIB_SFX)$(DEBUG_SFX) $(SYSLIBS)
#INCLUDES = -I. -I$(NDDSHOME)/include -I$(NDDSHOME)/include/ndds -I$(NDDSHOME)/include/ndds/hpp

#Add lib for dds
DEFINES += RTI_UNIX RTI_LINUX RTI_64BIT RTI_STATIC
LIBS += -L$$NDDSHOME/lib/$$TARGET_ARCH \
        -lnddscpp2z -lnddscz -lnddscorez $$SYSLIBS

INCLUDEPATH += $$NDDSHOME/lib/x64Linux3gcc5.4.0
DEPENDPATH += $$NDDSHOME/lib/x64Linux3gcc5.4.0
INCLUDEPATH += \
    $$NDDSHOME/include \
    $$NDDSHOME/include/ndds \
    $$NDDSHOME/include/ndds/hpp
