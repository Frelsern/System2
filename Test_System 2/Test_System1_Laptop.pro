#-------------------------------------------------
#
# Project created by QtCreator 2013-03-01T10:10:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_System1_Laptop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    segmentation_techniques.cpp \
    histogram_segmentation.cpp \
    hole_detection.cpp \
    growth_detection.cpp \
    colorspaces.cpp

HEADERS  += mainwindow.h \
    segmentation_techniques.h \
    histogram_segmentation.h \
    hole_detection.h \
    growth_detection.h \
    colorspaces.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\\opencv\\MyBuild\\install\\include

LIBS += -LC:\\opencv\\MyBuild\\install\\lib \
    -lopencv_calib3d245.dll \
    -lopencv_core245.dll \
    -lopencv_features2d245.dll \
    -lopencv_flann245.dll \
    -lopencv_gpu245.dll \
    -lopencv_highgui245.dll \
    -lopencv_imgproc245.dll \
    -lopencv_legacy245.dll \
    -lopencv_ml245.dll \
    -lopencv_nonfree245.dll \
    -lopencv_objdetect245.dll \
    -lopencv_photo245.dll \
    -lopencv_stitching245.dll \
    -lopencv_video245.dll \
    -lopencv_videostab245.dll
