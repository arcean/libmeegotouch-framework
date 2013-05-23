######################################################################
# Automatically generated by qmake (2.01a) Thu Apr 8 13:51:58 2010
######################################################################

include(../common_top.pri)

TARGET =  ut_mcomponentcache
DEPENDPATH += .

QT+=opengl
contains(DEFINES, HAVE_MEEGOGRAPHICSSYSTEM) {
    QT += meegographicssystemhelper
}

TEST_HEADERS = \
             $$MSRCDIR/corelib/core/mcomponentcache.h \
             $$MSRCDIR/corelib/core/mgraphicssystemhelper.h \

TEST_SOURCES = \
             $$MSRCDIR/corelib/core/mcomponentcache.cpp \
             $$MSRCDIR/corelib/core/mgraphicssystemhelper.cpp \
             $$MSRCDIR/corelib/theme/mpixmaphandle.cpp \
	
INCLUDEPATH += $$MSRCDIR/feedback
INCLUDEPATH += $$MSRCDIR/corelib/core

# Input
HEADERS += \
       ut_mcomponentcache.h \
       $$TEST_HEADERS


SOURCES += \
	ut_mcomponentcache.cpp \
    	$$TEST_SOURCES \

# service classes
SOURCES += \
    $$STUBSDIR/stubbase.cpp \

include(../common_bot.pri)