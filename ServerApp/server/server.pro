TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    db.cpp


unix:!macx: LIBS += -lpqxx -lpq

HEADERS += \
    db.h
