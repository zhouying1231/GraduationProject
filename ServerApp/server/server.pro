TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    db.cpp \
    socketserver.cpp


unix:!macx: LIBS += -lpqxx -lpq

HEADERS += \
    db.h \
    socketserver.hpp

unix:!macx: LIBS += -lboost_system
