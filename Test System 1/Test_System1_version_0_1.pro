#-------------------------------------------------
#
# Project created by QtCreator 2013-03-01T10:10:05
#
#-------------------------------------------------

QT       += core gui\



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test_System1_version_0_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    segmentation_techniques.cpp \
    histogram_segmentation.cpp \
    hole_detection.cpp \
    shapetester.cpp \
    growth_detection.cpp \
    colorspaces.cpp

HEADERS  += mainwindow.h \
    segmentation_techniques.h \
    histogram_segmentation.h \
    hole_detection.h \
    shapetester.h \
    growth_detection.h \
    colorspaces.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\\OpenCV2.4\\myBuild\\install\\include

LIBS += -LC:\\OpenCV2.4\\myBuild\\install\\lib \
    -lopencv_calib3d240d \
    -lopencv_core240d \
    -lopencv_features2d240d \
    -lopencv_flann240d \
    -lopencv_gpu240d \
    -lopencv_highgui240d \
    -lopencv_imgproc240d \
    -lopencv_legacy240d \
    -lopencv_ml240d \
    -lopencv_nonfree240d \
    -lopencv_objdetect240d \
    -lopencv_photo240d \
    -lopencv_stitching240d \
    -lopencv_ts240d \
    -lopencv_video240d \
    -lopencv_videostab240d
