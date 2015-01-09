TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += D:/boost/boost_1_55_0/

SOURCES += main.cpp

LIBS +=D:/boost/boost_1_55_0/bin.v2/libs/thread/build/gcc-mingw-4.4.0/release/link-static/threading-multi/libboost_thread-mgw44-mt-1_55.a \
    D:/boost/boost_1_55_0/bin.v2/libs/filesystem/build/gcc-mingw-4.4.0/release/link-static/threading-multi/libboost_filesystem-mgw44-mt-1_55.a \
    D:/boost/boost_1_55_0/bin.v2/libs/system/build/gcc-mingw-4.4.0/release/link-static/threading-multi/libboost_system-mgw44-mt-1_55.a \



