QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

TRANSLATIONS += \
    ftl-saver_en_US.ts \
    ftl-saver_ru_RU.ts
CODECFORSRC     = UTF-8

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    icons/icons.qrc
DEPLOYMENTFOLDERS = icons
unix:!macx {
    TARGET = wine-gui
    isEmpty(PREFIX) {
        PREFIX = /usr
    }
    target.path =  $$quote($$PREFIX/bin)
    desktop.files = icons/ftl-saver.desktop
    desktop.path =  $$quote($$PREFIX/share/applications)
    ftl-saver_en_US.files = ftl-saver_en_US.qm
    ftl-saver_en_US.path =  $$quote($$PREFIX/share/ftl-saver/ftl-saver_en_US.qm)
    ftl-saver_ru_RU.files = ftl-saver_ru_RU.qm
    ftl-saver_ru_RU.path =  $$quote($$PREFIX/share/ftl-saver/ftl-saver_ru_RU.qm)
    INSTALLS += target desktop ftl-saver_en_US ftl-saver_ru_RU
}
