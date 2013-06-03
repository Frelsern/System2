/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPause;
    QAction *actionDont_Process;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *processed_image_label;
    QGroupBox *Segmentation_groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *Sobel;
    QRadioButton *Scharr;
    QRadioButton *Otsu;
    QRadioButton *Thresholding;
    QRadioButton *Adaptive_Thresholding;
    QCheckBox *Inversion_checkbox;
    QGroupBox *Modes_groupbox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *No_Mode;
    QRadioButton *Hole_Detection;
    QRadioButton *Growth_detection;
    QGroupBox *Color_spaces_groupBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *x;
    QRadioButton *y;
    QRadioButton *Y;
    QRadioButton *Red;
    QRadioButton *Green;
    QRadioButton *Blue;
    QRadioButton *x2;
    QRadioButton *y2;
    QRadioButton *Y2;
    QRadioButton *Lab;
    QRadioButton *L;
    QRadioButton *a;
    QRadioButton *b;
    QGroupBox *Bottom_line_box;
    QPushButton *Capture;
    QGroupBox *time_spent_box;
    QPlainTextEdit *Total_time_spent;
    QGroupBox *Segmentation_enhancing_groupBox;
    QCheckBox *Dilation_checkBox;
    QCheckBox *Gaussian_checkBox;
    QGroupBox *Dilation_groupBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_12;
    QSlider *Dilation_horizontalSlider;
    QLCDNumber *Dilation_lcdNumber;
    QGroupBox *Gaussian_smoothing_groupBox;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_15;
    QSlider *Gaussian_horizontalSlider;
    QLCDNumber *Gaussian_lcdNumber;
    QGroupBox *Thresholding_box;
    QGroupBox *Glocal_Scharr_Histogram_2;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_11;
    QSlider *Threshold_slider;
    QLCDNumber *Threshold_lcdNumber_2;
    QCheckBox *Otsu_in_edge_checkBox;
    QGroupBox *Adaptive_Thresholding_box;
    QGroupBox *groupBox;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QRadioButton *Adaptive_Thresholding_gaussian_radioButton;
    QRadioButton *Adaptive_thresholding_mean_radioButton;
    QGroupBox *Adaptive_Thresholding_Kernel_box;
    QSlider *Adaptive_Thresholding_kernel_slider;
    QLCDNumber *Adaptive_Thresholding_kernel_lcdNumber;
    QGroupBox *Adaptive_Thresholding_C_box;
    QSlider *Adaptive_Thresholding_C_slider;
    QLCDNumber *Adaptive_Thresholding_C_lcdNumber;
    QGroupBox *Local_Otsu_box;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_2;
    QSlider *Local_Otsu_horizontalSlider;
    QLCDNumber *Local_Otsu_lcdNumber;
    QGroupBox *Local_Scharr_box;
    QGroupBox *Local_Scharr_Histogram;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_5;
    QSlider *Local_Scharr_histogram_slider;
    QLCDNumber *Local_Scharr_histogram_lcdNumber;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QSlider *Local_Scharr_horizontalSlider;
    QLCDNumber *Local_Scharr_lcdNumber;
    QCheckBox *Local_Scharr_dy_checkBox;
    QCheckBox *Local_Scharr_dx_checkBox;
    QGroupBox *Scharr_weight_dx_groupBox;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QSlider *Scharr_weight_dx_horizontalSlider;
    QLCDNumber *Local_Scharr_weight_dx_lcdNumber;
    QGroupBox *Scharr_weight_dy_groupBox;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_14;
    QSlider *Scharr_weight_dy_horizontalSlider;
    QLCDNumber *Local_Scharr_weight_dy_lcdNumber;
    QGroupBox *Local_Sobel_box;
    QGroupBox *Local_Sobel_groupBox;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_3;
    QSlider *Local_Sobel_horizontalSlider;
    QLCDNumber *Local_Sobel_lcdNumber;
    QGroupBox *Local_Sobel_Histogram;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QSlider *Local_Sobel_histogram_slider;
    QLCDNumber *Local_Sobel_histogram_lcdNumber;
    QGroupBox *Local_Sobel_dx_groupBox;
    QWidget *layoutWidget_15;
    QHBoxLayout *horizontalLayout_22;
    QSlider *Local_Sobel_dx_slider;
    QLCDNumber *Local_Sobel_dx_lcdNumber;
    QGroupBox *Local_Sobel_dy_groupBox;
    QWidget *layoutWidget_17;
    QHBoxLayout *horizontalLayout_24;
    QSlider *Local_Sobel_dy_slider;
    QLCDNumber *Local_Sobel_dy_lcdNumber;
    QGroupBox *Local_Sobel_Kernel_size_box;
    QWidget *layoutWidget_16;
    QHBoxLayout *horizontalLayout_23;
    QSlider *Local_Sobel_kernel_slider;
    QLCDNumber *Local_Sobel_kernel_lcdNumber;
    QGroupBox *Sobel_weight_dy_groupBox;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_16;
    QSlider *Sobel_weight_dy_horizontalSlider;
    QLCDNumber *Sobel_weight_dy_lcdNumber;
    QGroupBox *Sobel_weight_dx_groupBox;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_17;
    QSlider *Sobel_weight_dx_horizontalSlider;
    QLCDNumber *Sobel_weight_dx_lcdNumber;
    QPushButton *Capture_clean_net_pushButton;
    QGroupBox *Input_Source_groupBox;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *Webcam_source_radioButton;
    QRadioButton *Image_source_radioButton;
    QRadioButton *Video_source_radioButton;
    QCheckBox *Gradient_equalizer_checkBox;
    QCheckBox *Morphological_gradient_equalizer_checkBox;
    QCheckBox *Morphological_sharpen_checkBox;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1400, 400);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1400, 400));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionDont_Process = new QAction(MainWindow);
        actionDont_Process->setObjectName(QStringLiteral("actionDont_Process"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 100, 111, 61));
        processed_image_label = new QLabel(centralWidget);
        processed_image_label->setObjectName(QStringLiteral("processed_image_label"));
        processed_image_label->setGeometry(QRect(100, 100, 211, 71));
        Segmentation_groupBox = new QGroupBox(centralWidget);
        Segmentation_groupBox->setObjectName(QStringLiteral("Segmentation_groupBox"));
        Segmentation_groupBox->setGeometry(QRect(0, 44, 625, 45));
        layoutWidget = new QWidget(Segmentation_groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(4, 16, 608, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Sobel = new QRadioButton(layoutWidget);
        Sobel->setObjectName(QStringLiteral("Sobel"));

        horizontalLayout->addWidget(Sobel);

        Scharr = new QRadioButton(layoutWidget);
        Scharr->setObjectName(QStringLiteral("Scharr"));

        horizontalLayout->addWidget(Scharr);

        Otsu = new QRadioButton(layoutWidget);
        Otsu->setObjectName(QStringLiteral("Otsu"));

        horizontalLayout->addWidget(Otsu);

        Thresholding = new QRadioButton(layoutWidget);
        Thresholding->setObjectName(QStringLiteral("Thresholding"));

        horizontalLayout->addWidget(Thresholding);

        Adaptive_Thresholding = new QRadioButton(layoutWidget);
        Adaptive_Thresholding->setObjectName(QStringLiteral("Adaptive_Thresholding"));

        horizontalLayout->addWidget(Adaptive_Thresholding);

        Inversion_checkbox = new QCheckBox(layoutWidget);
        Inversion_checkbox->setObjectName(QStringLiteral("Inversion_checkbox"));

        horizontalLayout->addWidget(Inversion_checkbox);

        Modes_groupbox = new QGroupBox(centralWidget);
        Modes_groupbox->setObjectName(QStringLiteral("Modes_groupbox"));
        Modes_groupbox->setGeometry(QRect(780, 0, 285, 45));
        layoutWidget1 = new QWidget(Modes_groupbox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 20, 279, 19));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        No_Mode = new QRadioButton(layoutWidget1);
        No_Mode->setObjectName(QStringLiteral("No_Mode"));
        No_Mode->setChecked(true);

        horizontalLayout_9->addWidget(No_Mode);

        Hole_Detection = new QRadioButton(layoutWidget1);
        Hole_Detection->setObjectName(QStringLiteral("Hole_Detection"));

        horizontalLayout_9->addWidget(Hole_Detection);

        Growth_detection = new QRadioButton(layoutWidget1);
        Growth_detection->setObjectName(QStringLiteral("Growth_detection"));

        horizontalLayout_9->addWidget(Growth_detection);

        Color_spaces_groupBox = new QGroupBox(centralWidget);
        Color_spaces_groupBox->setObjectName(QStringLiteral("Color_spaces_groupBox"));
        Color_spaces_groupBox->setGeometry(QRect(210, 0, 561, 45));
        layoutWidget2 = new QWidget(Color_spaces_groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 20, 547, 19));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        x = new QRadioButton(layoutWidget2);
        x->setObjectName(QStringLiteral("x"));

        horizontalLayout_10->addWidget(x);

        y = new QRadioButton(layoutWidget2);
        y->setObjectName(QStringLiteral("y"));

        horizontalLayout_10->addWidget(y);

        Y = new QRadioButton(layoutWidget2);
        Y->setObjectName(QStringLiteral("Y"));

        horizontalLayout_10->addWidget(Y);

        Red = new QRadioButton(layoutWidget2);
        Red->setObjectName(QStringLiteral("Red"));

        horizontalLayout_10->addWidget(Red);

        Green = new QRadioButton(layoutWidget2);
        Green->setObjectName(QStringLiteral("Green"));

        horizontalLayout_10->addWidget(Green);

        Blue = new QRadioButton(layoutWidget2);
        Blue->setObjectName(QStringLiteral("Blue"));

        horizontalLayout_10->addWidget(Blue);

        x2 = new QRadioButton(layoutWidget2);
        x2->setObjectName(QStringLiteral("x2"));

        horizontalLayout_10->addWidget(x2);

        y2 = new QRadioButton(layoutWidget2);
        y2->setObjectName(QStringLiteral("y2"));

        horizontalLayout_10->addWidget(y2);

        Y2 = new QRadioButton(layoutWidget2);
        Y2->setObjectName(QStringLiteral("Y2"));

        horizontalLayout_10->addWidget(Y2);

        Lab = new QRadioButton(layoutWidget2);
        Lab->setObjectName(QStringLiteral("Lab"));

        horizontalLayout_10->addWidget(Lab);

        L = new QRadioButton(layoutWidget2);
        L->setObjectName(QStringLiteral("L"));

        horizontalLayout_10->addWidget(L);

        a = new QRadioButton(layoutWidget2);
        a->setObjectName(QStringLiteral("a"));

        horizontalLayout_10->addWidget(a);

        b = new QRadioButton(layoutWidget2);
        b->setObjectName(QStringLiteral("b"));

        horizontalLayout_10->addWidget(b);

        Bottom_line_box = new QGroupBox(centralWidget);
        Bottom_line_box->setObjectName(QStringLiteral("Bottom_line_box"));
        Bottom_line_box->setGeometry(QRect(5, 200, 1349, 121));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Bottom_line_box->sizePolicy().hasHeightForWidth());
        Bottom_line_box->setSizePolicy(sizePolicy1);
        Bottom_line_box->setMinimumSize(QSize(1330, 121));
        Bottom_line_box->setMaximumSize(QSize(1500, 121));
        Capture = new QPushButton(Bottom_line_box);
        Capture->setObjectName(QStringLiteral("Capture"));
        Capture->setGeometry(QRect(10, 20, 109, 25));
        QFont font;
        font.setPointSize(12);
        Capture->setFont(font);
        time_spent_box = new QGroupBox(Bottom_line_box);
        time_spent_box->setObjectName(QStringLiteral("time_spent_box"));
        time_spent_box->setGeometry(QRect(0, 50, 145, 69));
        time_spent_box->setAlignment(Qt::AlignCenter);
        Total_time_spent = new QPlainTextEdit(time_spent_box);
        Total_time_spent->setObjectName(QStringLiteral("Total_time_spent"));
        Total_time_spent->setGeometry(QRect(4, 12, 137, 53));
        Total_time_spent->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Total_time_spent->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Segmentation_enhancing_groupBox = new QGroupBox(Bottom_line_box);
        Segmentation_enhancing_groupBox->setObjectName(QStringLiteral("Segmentation_enhancing_groupBox"));
        Segmentation_enhancing_groupBox->setGeometry(QRect(1000, 20, 341, 97));
        Dilation_checkBox = new QCheckBox(Segmentation_enhancing_groupBox);
        Dilation_checkBox->setObjectName(QStringLiteral("Dilation_checkBox"));
        Dilation_checkBox->setGeometry(QRect(48, 20, 57, 17));
        Gaussian_checkBox = new QCheckBox(Segmentation_enhancing_groupBox);
        Gaussian_checkBox->setObjectName(QStringLiteral("Gaussian_checkBox"));
        Gaussian_checkBox->setGeometry(QRect(192, 20, 117, 17));
        Dilation_groupBox = new QGroupBox(Segmentation_enhancing_groupBox);
        Dilation_groupBox->setObjectName(QStringLiteral("Dilation_groupBox"));
        Dilation_groupBox->setGeometry(QRect(4, 40, 150, 40));
        layoutWidget3 = new QWidget(Dilation_groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(4, 12, 141, 25));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        Dilation_horizontalSlider = new QSlider(layoutWidget3);
        Dilation_horizontalSlider->setObjectName(QStringLiteral("Dilation_horizontalSlider"));
        Dilation_horizontalSlider->setMinimum(1);
        Dilation_horizontalSlider->setMaximum(10);
        Dilation_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(Dilation_horizontalSlider);

        Dilation_lcdNumber = new QLCDNumber(layoutWidget3);
        Dilation_lcdNumber->setObjectName(QStringLiteral("Dilation_lcdNumber"));
        Dilation_lcdNumber->setProperty("intValue", QVariant(1));

        horizontalLayout_12->addWidget(Dilation_lcdNumber);

        Gaussian_smoothing_groupBox = new QGroupBox(Segmentation_enhancing_groupBox);
        Gaussian_smoothing_groupBox->setObjectName(QStringLiteral("Gaussian_smoothing_groupBox"));
        Gaussian_smoothing_groupBox->setGeometry(QRect(180, 40, 150, 40));
        layoutWidget_8 = new QWidget(Gaussian_smoothing_groupBox);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(4, 12, 141, 25));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        Gaussian_horizontalSlider = new QSlider(layoutWidget_8);
        Gaussian_horizontalSlider->setObjectName(QStringLiteral("Gaussian_horizontalSlider"));
        Gaussian_horizontalSlider->setMinimum(1);
        Gaussian_horizontalSlider->setMaximum(25);
        Gaussian_horizontalSlider->setSingleStep(2);
        Gaussian_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_15->addWidget(Gaussian_horizontalSlider);

        Gaussian_lcdNumber = new QLCDNumber(layoutWidget_8);
        Gaussian_lcdNumber->setObjectName(QStringLiteral("Gaussian_lcdNumber"));
        Gaussian_lcdNumber->setProperty("intValue", QVariant(1));

        horizontalLayout_15->addWidget(Gaussian_lcdNumber);

        Thresholding_box = new QGroupBox(Bottom_line_box);
        Thresholding_box->setObjectName(QStringLiteral("Thresholding_box"));
        Thresholding_box->setGeometry(QRect(300, 20, 380, 100));
        Glocal_Scharr_Histogram_2 = new QGroupBox(Thresholding_box);
        Glocal_Scharr_Histogram_2->setObjectName(QStringLiteral("Glocal_Scharr_Histogram_2"));
        Glocal_Scharr_Histogram_2->setGeometry(QRect(200, 30, 170, 45));
        layoutWidget_5 = new QWidget(Glocal_Scharr_Histogram_2);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(4, 12, 156, 25));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        Threshold_slider = new QSlider(layoutWidget_5);
        Threshold_slider->setObjectName(QStringLiteral("Threshold_slider"));
        Threshold_slider->setMinimum(1);
        Threshold_slider->setMaximum(255);
        Threshold_slider->setSliderPosition(90);
        Threshold_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(Threshold_slider);

        Threshold_lcdNumber_2 = new QLCDNumber(layoutWidget_5);
        Threshold_lcdNumber_2->setObjectName(QStringLiteral("Threshold_lcdNumber_2"));
        Threshold_lcdNumber_2->setProperty("intValue", QVariant(90));

        horizontalLayout_11->addWidget(Threshold_lcdNumber_2);

        Otsu_in_edge_checkBox = new QCheckBox(Bottom_line_box);
        Otsu_in_edge_checkBox->setObjectName(QStringLiteral("Otsu_in_edge_checkBox"));
        Otsu_in_edge_checkBox->setGeometry(QRect(148, 20, 121, 25));
        Adaptive_Thresholding_box = new QGroupBox(Bottom_line_box);
        Adaptive_Thresholding_box->setObjectName(QStringLiteral("Adaptive_Thresholding_box"));
        Adaptive_Thresholding_box->setGeometry(QRect(300, 20, 380, 100));
        groupBox = new QGroupBox(Adaptive_Thresholding_box);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 20, 113, 73));
        layoutWidget4 = new QWidget(groupBox);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(5, 13, 68, 42));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Adaptive_Thresholding_gaussian_radioButton = new QRadioButton(layoutWidget4);
        Adaptive_Thresholding_gaussian_radioButton->setObjectName(QStringLiteral("Adaptive_Thresholding_gaussian_radioButton"));
        Adaptive_Thresholding_gaussian_radioButton->setChecked(true);

        verticalLayout->addWidget(Adaptive_Thresholding_gaussian_radioButton);

        Adaptive_thresholding_mean_radioButton = new QRadioButton(layoutWidget4);
        Adaptive_thresholding_mean_radioButton->setObjectName(QStringLiteral("Adaptive_thresholding_mean_radioButton"));

        verticalLayout->addWidget(Adaptive_thresholding_mean_radioButton);

        Adaptive_Thresholding_Kernel_box = new QGroupBox(Adaptive_Thresholding_box);
        Adaptive_Thresholding_Kernel_box->setObjectName(QStringLiteral("Adaptive_Thresholding_Kernel_box"));
        Adaptive_Thresholding_Kernel_box->setGeometry(QRect(124, 8, 173, 45));
        Adaptive_Thresholding_kernel_slider = new QSlider(Adaptive_Thresholding_Kernel_box);
        Adaptive_Thresholding_kernel_slider->setObjectName(QStringLiteral("Adaptive_Thresholding_kernel_slider"));
        Adaptive_Thresholding_kernel_slider->setGeometry(QRect(4, 16, 84, 19));
        Adaptive_Thresholding_kernel_slider->setMinimum(3);
        Adaptive_Thresholding_kernel_slider->setMaximum(15);
        Adaptive_Thresholding_kernel_slider->setSingleStep(2);
        Adaptive_Thresholding_kernel_slider->setValue(3);
        Adaptive_Thresholding_kernel_slider->setSliderPosition(3);
        Adaptive_Thresholding_kernel_slider->setOrientation(Qt::Horizontal);
        Adaptive_Thresholding_kernel_lcdNumber = new QLCDNumber(Adaptive_Thresholding_Kernel_box);
        Adaptive_Thresholding_kernel_lcdNumber->setObjectName(QStringLiteral("Adaptive_Thresholding_kernel_lcdNumber"));
        Adaptive_Thresholding_kernel_lcdNumber->setGeometry(QRect(100, 16, 64, 23));
        Adaptive_Thresholding_kernel_lcdNumber->setProperty("intValue", QVariant(3));
        Adaptive_Thresholding_C_box = new QGroupBox(Adaptive_Thresholding_box);
        Adaptive_Thresholding_C_box->setObjectName(QStringLiteral("Adaptive_Thresholding_C_box"));
        Adaptive_Thresholding_C_box->setGeometry(QRect(124, 52, 173, 45));
        Adaptive_Thresholding_C_slider = new QSlider(Adaptive_Thresholding_C_box);
        Adaptive_Thresholding_C_slider->setObjectName(QStringLiteral("Adaptive_Thresholding_C_slider"));
        Adaptive_Thresholding_C_slider->setGeometry(QRect(4, 16, 84, 19));
        Adaptive_Thresholding_C_slider->setMinimum(0);
        Adaptive_Thresholding_C_slider->setMaximum(25);
        Adaptive_Thresholding_C_slider->setSingleStep(2);
        Adaptive_Thresholding_C_slider->setValue(0);
        Adaptive_Thresholding_C_slider->setSliderPosition(0);
        Adaptive_Thresholding_C_slider->setOrientation(Qt::Horizontal);
        Adaptive_Thresholding_C_lcdNumber = new QLCDNumber(Adaptive_Thresholding_C_box);
        Adaptive_Thresholding_C_lcdNumber->setObjectName(QStringLiteral("Adaptive_Thresholding_C_lcdNumber"));
        Adaptive_Thresholding_C_lcdNumber->setGeometry(QRect(100, 16, 64, 23));
        Adaptive_Thresholding_C_lcdNumber->setProperty("intValue", QVariant(0));
        Local_Otsu_box = new QGroupBox(Bottom_line_box);
        Local_Otsu_box->setObjectName(QStringLiteral("Local_Otsu_box"));
        Local_Otsu_box->setGeometry(QRect(300, 20, 380, 100));
        layoutWidget5 = new QWidget(Local_Otsu_box);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(8, 48, 156, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Local_Otsu_horizontalSlider = new QSlider(layoutWidget5);
        Local_Otsu_horizontalSlider->setObjectName(QStringLiteral("Local_Otsu_horizontalSlider"));
        Local_Otsu_horizontalSlider->setMinimum(1);
        Local_Otsu_horizontalSlider->setMaximum(60);
        Local_Otsu_horizontalSlider->setValue(5);
        Local_Otsu_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(Local_Otsu_horizontalSlider);

        Local_Otsu_lcdNumber = new QLCDNumber(layoutWidget5);
        Local_Otsu_lcdNumber->setObjectName(QStringLiteral("Local_Otsu_lcdNumber"));
        Local_Otsu_lcdNumber->setProperty("intValue", QVariant(25));

        horizontalLayout_2->addWidget(Local_Otsu_lcdNumber);

        Local_Scharr_box = new QGroupBox(Bottom_line_box);
        Local_Scharr_box->setObjectName(QStringLiteral("Local_Scharr_box"));
        Local_Scharr_box->setGeometry(QRect(300, 20, 550, 100));
        Local_Scharr_Histogram = new QGroupBox(Local_Scharr_box);
        Local_Scharr_Histogram->setObjectName(QStringLiteral("Local_Scharr_Histogram"));
        Local_Scharr_Histogram->setGeometry(QRect(0, 56, 170, 45));
        layoutWidget6 = new QWidget(Local_Scharr_Histogram);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(4, 12, 156, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Local_Scharr_histogram_slider = new QSlider(layoutWidget6);
        Local_Scharr_histogram_slider->setObjectName(QStringLiteral("Local_Scharr_histogram_slider"));
        Local_Scharr_histogram_slider->setMinimum(60);
        Local_Scharr_histogram_slider->setMaximum(99);
        Local_Scharr_histogram_slider->setSliderPosition(90);
        Local_Scharr_histogram_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(Local_Scharr_histogram_slider);

        Local_Scharr_histogram_lcdNumber = new QLCDNumber(layoutWidget6);
        Local_Scharr_histogram_lcdNumber->setObjectName(QStringLiteral("Local_Scharr_histogram_lcdNumber"));
        Local_Scharr_histogram_lcdNumber->setProperty("intValue", QVariant(90));

        horizontalLayout_5->addWidget(Local_Scharr_histogram_lcdNumber);

        groupBox_2 = new QGroupBox(Local_Scharr_box);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 12, 170, 45));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(8, 16, 156, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Local_Scharr_horizontalSlider = new QSlider(layoutWidget_2);
        Local_Scharr_horizontalSlider->setObjectName(QStringLiteral("Local_Scharr_horizontalSlider"));
        Local_Scharr_horizontalSlider->setMinimum(1);
        Local_Scharr_horizontalSlider->setMaximum(40);
        Local_Scharr_horizontalSlider->setValue(5);
        Local_Scharr_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(Local_Scharr_horizontalSlider);

        Local_Scharr_lcdNumber = new QLCDNumber(layoutWidget_2);
        Local_Scharr_lcdNumber->setObjectName(QStringLiteral("Local_Scharr_lcdNumber"));
        Local_Scharr_lcdNumber->setProperty("intValue", QVariant(25));

        horizontalLayout_4->addWidget(Local_Scharr_lcdNumber);

        Local_Scharr_dy_checkBox = new QCheckBox(Local_Scharr_box);
        Local_Scharr_dy_checkBox->setObjectName(QStringLiteral("Local_Scharr_dy_checkBox"));
        Local_Scharr_dy_checkBox->setGeometry(QRect(216, 72, 70, 17));
        Local_Scharr_dx_checkBox = new QCheckBox(Local_Scharr_box);
        Local_Scharr_dx_checkBox->setObjectName(QStringLiteral("Local_Scharr_dx_checkBox"));
        Local_Scharr_dx_checkBox->setGeometry(QRect(216, 28, 70, 17));
        Local_Scharr_dx_checkBox->setChecked(true);
        Scharr_weight_dx_groupBox = new QGroupBox(Local_Scharr_box);
        Scharr_weight_dx_groupBox->setObjectName(QStringLiteral("Scharr_weight_dx_groupBox"));
        Scharr_weight_dx_groupBox->setGeometry(QRect(292, 8, 170, 45));
        layoutWidget_6 = new QWidget(Scharr_weight_dx_groupBox);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(8, 16, 156, 25));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        Scharr_weight_dx_horizontalSlider = new QSlider(layoutWidget_6);
        Scharr_weight_dx_horizontalSlider->setObjectName(QStringLiteral("Scharr_weight_dx_horizontalSlider"));
        Scharr_weight_dx_horizontalSlider->setMinimum(1);
        Scharr_weight_dx_horizontalSlider->setMaximum(100);
        Scharr_weight_dx_horizontalSlider->setValue(50);
        Scharr_weight_dx_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(Scharr_weight_dx_horizontalSlider);

        Local_Scharr_weight_dx_lcdNumber = new QLCDNumber(layoutWidget_6);
        Local_Scharr_weight_dx_lcdNumber->setObjectName(QStringLiteral("Local_Scharr_weight_dx_lcdNumber"));
        Local_Scharr_weight_dx_lcdNumber->setSmallDecimalPoint(false);
        Local_Scharr_weight_dx_lcdNumber->setProperty("value", QVariant(50));
        Local_Scharr_weight_dx_lcdNumber->setProperty("intValue", QVariant(50));

        horizontalLayout_7->addWidget(Local_Scharr_weight_dx_lcdNumber);

        Scharr_weight_dy_groupBox = new QGroupBox(Local_Scharr_box);
        Scharr_weight_dy_groupBox->setObjectName(QStringLiteral("Scharr_weight_dy_groupBox"));
        Scharr_weight_dy_groupBox->setGeometry(QRect(292, 52, 170, 45));
        layoutWidget_7 = new QWidget(Scharr_weight_dy_groupBox);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(8, 16, 156, 25));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        Scharr_weight_dy_horizontalSlider = new QSlider(layoutWidget_7);
        Scharr_weight_dy_horizontalSlider->setObjectName(QStringLiteral("Scharr_weight_dy_horizontalSlider"));
        Scharr_weight_dy_horizontalSlider->setMinimum(1);
        Scharr_weight_dy_horizontalSlider->setMaximum(100);
        Scharr_weight_dy_horizontalSlider->setValue(50);
        Scharr_weight_dy_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_14->addWidget(Scharr_weight_dy_horizontalSlider);

        Local_Scharr_weight_dy_lcdNumber = new QLCDNumber(layoutWidget_7);
        Local_Scharr_weight_dy_lcdNumber->setObjectName(QStringLiteral("Local_Scharr_weight_dy_lcdNumber"));
        Local_Scharr_weight_dy_lcdNumber->setProperty("intValue", QVariant(50));

        horizontalLayout_14->addWidget(Local_Scharr_weight_dy_lcdNumber);

        Local_Sobel_box = new QGroupBox(Bottom_line_box);
        Local_Sobel_box->setObjectName(QStringLiteral("Local_Sobel_box"));
        Local_Sobel_box->setGeometry(QRect(300, 20, 693, 100));
        Local_Sobel_groupBox = new QGroupBox(Local_Sobel_box);
        Local_Sobel_groupBox->setObjectName(QStringLiteral("Local_Sobel_groupBox"));
        Local_Sobel_groupBox->setGeometry(QRect(0, 30, 170, 45));
        layoutWidget7 = new QWidget(Local_Sobel_groupBox);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(4, 12, 156, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Local_Sobel_horizontalSlider = new QSlider(layoutWidget7);
        Local_Sobel_horizontalSlider->setObjectName(QStringLiteral("Local_Sobel_horizontalSlider"));
        Local_Sobel_horizontalSlider->setMinimum(1);
        Local_Sobel_horizontalSlider->setMaximum(40);
        Local_Sobel_horizontalSlider->setValue(5);
        Local_Sobel_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(Local_Sobel_horizontalSlider);

        Local_Sobel_lcdNumber = new QLCDNumber(layoutWidget7);
        Local_Sobel_lcdNumber->setObjectName(QStringLiteral("Local_Sobel_lcdNumber"));
        Local_Sobel_lcdNumber->setProperty("intValue", QVariant(25));

        horizontalLayout_3->addWidget(Local_Sobel_lcdNumber);

        Local_Sobel_Histogram = new QGroupBox(Local_Sobel_box);
        Local_Sobel_Histogram->setObjectName(QStringLiteral("Local_Sobel_Histogram"));
        Local_Sobel_Histogram->setGeometry(QRect(344, 16, 170, 41));
        layoutWidget_4 = new QWidget(Local_Sobel_Histogram);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(4, 12, 156, 25));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        Local_Sobel_histogram_slider = new QSlider(layoutWidget_4);
        Local_Sobel_histogram_slider->setObjectName(QStringLiteral("Local_Sobel_histogram_slider"));
        Local_Sobel_histogram_slider->setMinimum(60);
        Local_Sobel_histogram_slider->setMaximum(99);
        Local_Sobel_histogram_slider->setSliderPosition(90);
        Local_Sobel_histogram_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(Local_Sobel_histogram_slider);

        Local_Sobel_histogram_lcdNumber = new QLCDNumber(layoutWidget_4);
        Local_Sobel_histogram_lcdNumber->setObjectName(QStringLiteral("Local_Sobel_histogram_lcdNumber"));
        Local_Sobel_histogram_lcdNumber->setProperty("intValue", QVariant(90));

        horizontalLayout_8->addWidget(Local_Sobel_histogram_lcdNumber);

        Local_Sobel_dx_groupBox = new QGroupBox(Local_Sobel_box);
        Local_Sobel_dx_groupBox->setObjectName(QStringLiteral("Local_Sobel_dx_groupBox"));
        Local_Sobel_dx_groupBox->setGeometry(QRect(172, 16, 169, 41));
        layoutWidget_15 = new QWidget(Local_Sobel_dx_groupBox);
        layoutWidget_15->setObjectName(QStringLiteral("layoutWidget_15"));
        layoutWidget_15->setGeometry(QRect(4, 12, 156, 25));
        horizontalLayout_22 = new QHBoxLayout(layoutWidget_15);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        Local_Sobel_dx_slider = new QSlider(layoutWidget_15);
        Local_Sobel_dx_slider->setObjectName(QStringLiteral("Local_Sobel_dx_slider"));
        Local_Sobel_dx_slider->setMinimum(0);
        Local_Sobel_dx_slider->setMaximum(6);
        Local_Sobel_dx_slider->setValue(1);
        Local_Sobel_dx_slider->setSliderPosition(1);
        Local_Sobel_dx_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_22->addWidget(Local_Sobel_dx_slider);

        Local_Sobel_dx_lcdNumber = new QLCDNumber(layoutWidget_15);
        Local_Sobel_dx_lcdNumber->setObjectName(QStringLiteral("Local_Sobel_dx_lcdNumber"));
        Local_Sobel_dx_lcdNumber->setProperty("intValue", QVariant(1));

        horizontalLayout_22->addWidget(Local_Sobel_dx_lcdNumber);

        Local_Sobel_dy_groupBox = new QGroupBox(Local_Sobel_box);
        Local_Sobel_dy_groupBox->setObjectName(QStringLiteral("Local_Sobel_dy_groupBox"));
        Local_Sobel_dy_groupBox->setGeometry(QRect(172, 56, 169, 41));
        layoutWidget_17 = new QWidget(Local_Sobel_dy_groupBox);
        layoutWidget_17->setObjectName(QStringLiteral("layoutWidget_17"));
        layoutWidget_17->setGeometry(QRect(4, 12, 156, 25));
        horizontalLayout_24 = new QHBoxLayout(layoutWidget_17);
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        Local_Sobel_dy_slider = new QSlider(layoutWidget_17);
        Local_Sobel_dy_slider->setObjectName(QStringLiteral("Local_Sobel_dy_slider"));
        Local_Sobel_dy_slider->setMinimum(0);
        Local_Sobel_dy_slider->setMaximum(6);
        Local_Sobel_dy_slider->setValue(1);
        Local_Sobel_dy_slider->setSliderPosition(1);
        Local_Sobel_dy_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_24->addWidget(Local_Sobel_dy_slider);

        Local_Sobel_dy_lcdNumber = new QLCDNumber(layoutWidget_17);
        Local_Sobel_dy_lcdNumber->setObjectName(QStringLiteral("Local_Sobel_dy_lcdNumber"));
        Local_Sobel_dy_lcdNumber->setProperty("intValue", QVariant(1));

        horizontalLayout_24->addWidget(Local_Sobel_dy_lcdNumber);

        Local_Sobel_Kernel_size_box = new QGroupBox(Local_Sobel_box);
        Local_Sobel_Kernel_size_box->setObjectName(QStringLiteral("Local_Sobel_Kernel_size_box"));
        Local_Sobel_Kernel_size_box->setGeometry(QRect(344, 56, 170, 37));
        layoutWidget_16 = new QWidget(Local_Sobel_Kernel_size_box);
        layoutWidget_16->setObjectName(QStringLiteral("layoutWidget_16"));
        layoutWidget_16->setGeometry(QRect(4, 12, 156, 25));
        horizontalLayout_23 = new QHBoxLayout(layoutWidget_16);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        Local_Sobel_kernel_slider = new QSlider(layoutWidget_16);
        Local_Sobel_kernel_slider->setObjectName(QStringLiteral("Local_Sobel_kernel_slider"));
        Local_Sobel_kernel_slider->setMinimum(1);
        Local_Sobel_kernel_slider->setMaximum(7);
        Local_Sobel_kernel_slider->setSliderPosition(3);
        Local_Sobel_kernel_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_23->addWidget(Local_Sobel_kernel_slider);

        Local_Sobel_kernel_lcdNumber = new QLCDNumber(layoutWidget_16);
        Local_Sobel_kernel_lcdNumber->setObjectName(QStringLiteral("Local_Sobel_kernel_lcdNumber"));
        Local_Sobel_kernel_lcdNumber->setProperty("intValue", QVariant(3));

        horizontalLayout_23->addWidget(Local_Sobel_kernel_lcdNumber);

        Sobel_weight_dy_groupBox = new QGroupBox(Local_Sobel_box);
        Sobel_weight_dy_groupBox->setObjectName(QStringLiteral("Sobel_weight_dy_groupBox"));
        Sobel_weight_dy_groupBox->setGeometry(QRect(516, 56, 170, 45));
        layoutWidget_9 = new QWidget(Sobel_weight_dy_groupBox);
        layoutWidget_9->setObjectName(QStringLiteral("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(8, 16, 156, 25));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        Sobel_weight_dy_horizontalSlider = new QSlider(layoutWidget_9);
        Sobel_weight_dy_horizontalSlider->setObjectName(QStringLiteral("Sobel_weight_dy_horizontalSlider"));
        Sobel_weight_dy_horizontalSlider->setMinimum(1);
        Sobel_weight_dy_horizontalSlider->setMaximum(100);
        Sobel_weight_dy_horizontalSlider->setValue(50);
        Sobel_weight_dy_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_16->addWidget(Sobel_weight_dy_horizontalSlider);

        Sobel_weight_dy_lcdNumber = new QLCDNumber(layoutWidget_9);
        Sobel_weight_dy_lcdNumber->setObjectName(QStringLiteral("Sobel_weight_dy_lcdNumber"));
        Sobel_weight_dy_lcdNumber->setProperty("intValue", QVariant(50));

        horizontalLayout_16->addWidget(Sobel_weight_dy_lcdNumber);

        Sobel_weight_dx_groupBox = new QGroupBox(Local_Sobel_box);
        Sobel_weight_dx_groupBox->setObjectName(QStringLiteral("Sobel_weight_dx_groupBox"));
        Sobel_weight_dx_groupBox->setGeometry(QRect(516, 12, 170, 45));
        layoutWidget_10 = new QWidget(Sobel_weight_dx_groupBox);
        layoutWidget_10->setObjectName(QStringLiteral("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(8, 16, 156, 25));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        Sobel_weight_dx_horizontalSlider = new QSlider(layoutWidget_10);
        Sobel_weight_dx_horizontalSlider->setObjectName(QStringLiteral("Sobel_weight_dx_horizontalSlider"));
        Sobel_weight_dx_horizontalSlider->setMinimum(1);
        Sobel_weight_dx_horizontalSlider->setMaximum(100);
        Sobel_weight_dx_horizontalSlider->setValue(50);
        Sobel_weight_dx_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_17->addWidget(Sobel_weight_dx_horizontalSlider);

        Sobel_weight_dx_lcdNumber = new QLCDNumber(layoutWidget_10);
        Sobel_weight_dx_lcdNumber->setObjectName(QStringLiteral("Sobel_weight_dx_lcdNumber"));
        Sobel_weight_dx_lcdNumber->setSmallDecimalPoint(false);
        Sobel_weight_dx_lcdNumber->setProperty("value", QVariant(50));
        Sobel_weight_dx_lcdNumber->setProperty("intValue", QVariant(50));

        horizontalLayout_17->addWidget(Sobel_weight_dx_lcdNumber);

        Capture_clean_net_pushButton = new QPushButton(centralWidget);
        Capture_clean_net_pushButton->setObjectName(QStringLiteral("Capture_clean_net_pushButton"));
        Capture_clean_net_pushButton->setGeometry(QRect(1070, 20, 97, 23));
        Input_Source_groupBox = new QGroupBox(centralWidget);
        Input_Source_groupBox->setObjectName(QStringLiteral("Input_Source_groupBox"));
        Input_Source_groupBox->setGeometry(QRect(0, 0, 201, 45));
        layoutWidget8 = new QWidget(Input_Source_groupBox);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(10, 20, 182, 19));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        Webcam_source_radioButton = new QRadioButton(layoutWidget8);
        Webcam_source_radioButton->setObjectName(QStringLiteral("Webcam_source_radioButton"));
        Webcam_source_radioButton->setChecked(true);

        horizontalLayout_13->addWidget(Webcam_source_radioButton);

        Image_source_radioButton = new QRadioButton(layoutWidget8);
        Image_source_radioButton->setObjectName(QStringLiteral("Image_source_radioButton"));

        horizontalLayout_13->addWidget(Image_source_radioButton);

        Video_source_radioButton = new QRadioButton(layoutWidget8);
        Video_source_radioButton->setObjectName(QStringLiteral("Video_source_radioButton"));

        horizontalLayout_13->addWidget(Video_source_radioButton);

        Gradient_equalizer_checkBox = new QCheckBox(centralWidget);
        Gradient_equalizer_checkBox->setObjectName(QStringLiteral("Gradient_equalizer_checkBox"));
        Gradient_equalizer_checkBox->setGeometry(QRect(632, 60, 133, 17));
        Morphological_gradient_equalizer_checkBox = new QCheckBox(centralWidget);
        Morphological_gradient_equalizer_checkBox->setObjectName(QStringLiteral("Morphological_gradient_equalizer_checkBox"));
        Morphological_gradient_equalizer_checkBox->setGeometry(QRect(772, 60, 201, 17));
        Morphological_sharpen_checkBox = new QCheckBox(centralWidget);
        Morphological_sharpen_checkBox->setObjectName(QStringLiteral("Morphological_sharpen_checkBox"));
        Morphological_sharpen_checkBox->setGeometry(QRect(976, 60, 137, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionPause);
        menuFile->addAction(actionDont_Process);

        retranslateUi(MainWindow);
        QObject::connect(Local_Scharr_histogram_slider, SIGNAL(valueChanged(int)), Local_Scharr_histogram_lcdNumber, SLOT(display(int)));
        QObject::connect(Local_Sobel_histogram_slider, SIGNAL(valueChanged(int)), Local_Sobel_histogram_lcdNumber, SLOT(display(int)));
        QObject::connect(Dilation_horizontalSlider, SIGNAL(valueChanged(int)), Dilation_lcdNumber, SLOT(display(int)));
        QObject::connect(Threshold_slider, SIGNAL(valueChanged(int)), Threshold_lcdNumber_2, SLOT(display(int)));
        QObject::connect(Local_Sobel_dx_slider, SIGNAL(valueChanged(int)), Local_Sobel_dx_lcdNumber, SLOT(display(int)));
        QObject::connect(Local_Sobel_dy_slider, SIGNAL(valueChanged(int)), Local_Sobel_dy_lcdNumber, SLOT(display(int)));
        QObject::connect(Adaptive_Thresholding_C_slider, SIGNAL(valueChanged(int)), Adaptive_Thresholding_C_lcdNumber, SLOT(display(int)));
        QObject::connect(Scharr_weight_dx_horizontalSlider, SIGNAL(valueChanged(int)), Local_Scharr_weight_dx_lcdNumber, SLOT(display(int)));
        QObject::connect(Scharr_weight_dy_horizontalSlider, SIGNAL(valueChanged(int)), Local_Scharr_weight_dy_lcdNumber, SLOT(display(int)));
        QObject::connect(Sobel_weight_dx_horizontalSlider, SIGNAL(valueChanged(int)), Sobel_weight_dx_lcdNumber, SLOT(display(int)));
        QObject::connect(Sobel_weight_dy_horizontalSlider, SIGNAL(valueChanged(int)), Sobel_weight_dy_lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        actionDont_Process->setText(QApplication::translate("MainWindow", "Do not Process", 0));
        label->setText(QString());
        processed_image_label->setText(QString());
        Segmentation_groupBox->setTitle(QApplication::translate("MainWindow", "Segmentation methods", 0));
        Sobel->setText(QApplication::translate("MainWindow", "Sobel", 0));
        Scharr->setText(QApplication::translate("MainWindow", "Scharr", 0));
        Otsu->setText(QApplication::translate("MainWindow", "Otsu's method", 0));
        Thresholding->setText(QApplication::translate("MainWindow", "Naive thresholding", 0));
        Adaptive_Thresholding->setText(QApplication::translate("MainWindow", "Adaptive thresholding", 0));
        Inversion_checkbox->setText(QApplication::translate("MainWindow", "Invert Segmented image", 0));
        Modes_groupbox->setTitle(QApplication::translate("MainWindow", "Mode", 0));
        No_Mode->setText(QApplication::translate("MainWindow", "No Mode", 0));
        Hole_Detection->setText(QApplication::translate("MainWindow", "Hole Detection", 0));
        Growth_detection->setText(QApplication::translate("MainWindow", "Growth Detection", 0));
        Color_spaces_groupBox->setTitle(QApplication::translate("MainWindow", "Color Spaces", 0));
        x->setText(QApplication::translate("MainWindow", "x", 0));
        y->setText(QApplication::translate("MainWindow", "y", 0));
        Y->setText(QApplication::translate("MainWindow", "Y", 0));
        Red->setText(QApplication::translate("MainWindow", "Red", 0));
        Green->setText(QApplication::translate("MainWindow", "Green", 0));
        Blue->setText(QApplication::translate("MainWindow", "Blue", 0));
        x2->setText(QApplication::translate("MainWindow", "x2", 0));
        y2->setText(QApplication::translate("MainWindow", "y2", 0));
        Y2->setText(QApplication::translate("MainWindow", "Y2", 0));
        Lab->setText(QApplication::translate("MainWindow", "L*a*b*", 0));
        L->setText(QApplication::translate("MainWindow", "L", 0));
        a->setText(QApplication::translate("MainWindow", "a", 0));
        b->setText(QApplication::translate("MainWindow", "b", 0));
        Bottom_line_box->setTitle(QString());
        Capture->setText(QApplication::translate("MainWindow", "Capture", 0));
        time_spent_box->setTitle(QApplication::translate("MainWindow", "Total time spent per image", 0));
        Segmentation_enhancing_groupBox->setTitle(QApplication::translate("MainWindow", "Segmentation enhancing", 0));
        Dilation_checkBox->setText(QApplication::translate("MainWindow", "Dilation", 0));
        Gaussian_checkBox->setText(QApplication::translate("MainWindow", "Gaussian Smoothing", 0));
        Dilation_groupBox->setTitle(QApplication::translate("MainWindow", "Number of rounds", 0));
        Gaussian_smoothing_groupBox->setTitle(QApplication::translate("MainWindow", "Kernel size", 0));
        Thresholding_box->setTitle(QApplication::translate("MainWindow", "Thresholding", 0));
        Glocal_Scharr_Histogram_2->setTitle(QApplication::translate("MainWindow", "Threshold", 0));
        Otsu_in_edge_checkBox->setText(QApplication::translate("MainWindow", "Use Otsu with\n"
"Edge Segmentation\n"
"", 0));
        Adaptive_Thresholding_box->setTitle(QApplication::translate("MainWindow", "Adaptive Thresholding", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Thresholding method", 0));
        Adaptive_Thresholding_gaussian_radioButton->setText(QApplication::translate("MainWindow", "Gaussian", 0));
        Adaptive_thresholding_mean_radioButton->setText(QApplication::translate("MainWindow", "Mean", 0));
        Adaptive_Thresholding_Kernel_box->setTitle(QApplication::translate("MainWindow", "Kernel size", 0));
        Adaptive_Thresholding_C_box->setTitle(QApplication::translate("MainWindow", "C", 0));
        Local_Otsu_box->setTitle(QApplication::translate("MainWindow", "Local Otsu", 0));
        Local_Scharr_box->setTitle(QApplication::translate("MainWindow", "Local Scharr", 0));
        Local_Scharr_Histogram->setTitle(QApplication::translate("MainWindow", "Histogram percentile", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Number of sub-images", 0));
        Local_Scharr_dy_checkBox->setText(QApplication::translate("MainWindow", "dy", 0));
        Local_Scharr_dx_checkBox->setText(QApplication::translate("MainWindow", "dx", 0));
        Scharr_weight_dx_groupBox->setTitle(QApplication::translate("MainWindow", "Weighting of dx", 0));
        Scharr_weight_dy_groupBox->setTitle(QApplication::translate("MainWindow", "Weighting of dy", 0));
        Local_Sobel_box->setTitle(QApplication::translate("MainWindow", "Local Sobel", 0));
        Local_Sobel_groupBox->setTitle(QApplication::translate("MainWindow", "Number of sub-images", 0));
        Local_Sobel_Histogram->setTitle(QApplication::translate("MainWindow", "Histogram percentile", 0));
        Local_Sobel_dx_groupBox->setTitle(QApplication::translate("MainWindow", "dx", 0));
        Local_Sobel_dy_groupBox->setTitle(QApplication::translate("MainWindow", "dy", 0));
        Local_Sobel_Kernel_size_box->setTitle(QApplication::translate("MainWindow", "Kernel Size", 0));
        Sobel_weight_dy_groupBox->setTitle(QApplication::translate("MainWindow", "Weighting of dy", 0));
        Sobel_weight_dx_groupBox->setTitle(QApplication::translate("MainWindow", "Weighting of dx", 0));
        Capture_clean_net_pushButton->setText(QApplication::translate("MainWindow", "Capture clean net", 0));
        Input_Source_groupBox->setTitle(QApplication::translate("MainWindow", "Input Source", 0));
        Webcam_source_radioButton->setText(QApplication::translate("MainWindow", "WebCam", 0));
        Image_source_radioButton->setText(QApplication::translate("MainWindow", "Image", 0));
        Video_source_radioButton->setText(QApplication::translate("MainWindow", "Video", 0));
        Gradient_equalizer_checkBox->setText(QApplication::translate("MainWindow", "Light gradient equalizer", 0));
        Morphological_gradient_equalizer_checkBox->setText(QApplication::translate("MainWindow", "Morphological light gradient equalizer", 0));
        Morphological_sharpen_checkBox->setText(QApplication::translate("MainWindow", "Morphological sharpen", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
