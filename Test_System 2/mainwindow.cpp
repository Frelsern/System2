#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


void MainWindow::hide_all_seg_boxes()
{
    ui->Local_Sobel_box->hide();
    ui->Local_Scharr_box->hide();
    ui->Local_Otsu_box->hide();
    ui->Thresholding_box->hide();
    ui->Adaptive_Thresholding_box->hide();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setup window
    ui->setupUi(this);
    this->setWindowTitle(QString("System 2, v.0.1"));

    //hide the Segmentation boxes
    hide_all_seg_boxes();

    //initializing parameters.
    Local_Sobel_numberofSubImages = 5;
    Local_Sobel_hist_percentile = 90;
    Local_Sobel_dx = 1;
    Local_Sobel_dy = 1;
    Local_Sobel_kernel_size = 3;
    Local_Scharr_numberofSubImages = 5;
    Local_Scharr_hist_percentile = 90;
    Local_Otsu_numberofSubImages = 5;
    Naive_threshold = 90;
    Adaptive_Thresholding_kernel_size = 3;
    Adaptive_thresholding_C = 0;
    Dilation_iterations = 1;
    Gaussian_kernel_size = 1;

    Percentage_foreground_clean_net = -1;

    cspace = COLOR_NONE;
    thresh_met = THRESH_NONE;
    mode = NO_MODE;
    PAUSE = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processFrameAndUpdateGUI(cv::Mat b4_tweak_input_image)
{
        //cv::Mat input_image = tweak_video_frame(b4_tweak_input_image);
        cv::Mat input_image;
        b4_tweak_input_image.copyTo(input_image);

        //cv::Mat processed_image,Segmented_image,hole_detected_image;//kan lage de her, men da må jeg lage de en gang hver frame, unødvendig?
        cv::Mat lab_image;
        //Converting to the given color space
        switch(cspace)
        {
        case COLOR_NONE:

           break;
        case LUMINANCE:
            processed_image = custom_Y(input_image);
            break;
        case X:
            processed_image = custom_x(input_image);
            break;
        case Y:
            processed_image = custom_y(input_image);
            break;
        case RED:
            processed_image = red_space(input_image);
            break;
        case GREEN:
            processed_image = green_space(input_image);
            break;
        case BLUE:
            processed_image = blue_space(input_image);
            break;
        case X2:
            processed_image = standard_x(input_image);
            break;
        case Y2:
            processed_image = standard_y(input_image);
            break;
        case LUMINANCE2:
            processed_image = standard_Y(input_image);
            break;
        case LAB:
            cv::cvtColor(input_image,lab_image,CV_RGB2Lab);
            break;
        case L:
            processed_image = L_space(input_image);
            break;
        case A:
            processed_image = a_space(input_image);
            break;
        case B:
            processed_image = b_space(input_image);
            break;
        }

        //Smoothing image before thresholding
        if(ui->Gaussian_checkBox->isChecked() && !processed_image.empty())
        {
            cv::GaussianBlur(processed_image,processed_image,cv::Size(Gaussian_kernel_size,Gaussian_kernel_size),0,0,cv::BORDER_DEFAULT);
        }
        //Light gradient
        if(ui->Gradient_equalizer_checkBox->isChecked())
        {
            processed_image = Light_gradient_equalizer(processed_image);
        }


        //thresholding
        switch(thresh_met)
        {
        case THRESH_NONE:
            break;
        case SOBEL:
            Segmented_image = Local_Sobel(processed_image,Local_Sobel_numberofSubImages, Local_Sobel_kernel_size,
                                          Local_Sobel_hist_percentile,Local_Sobel_dx,Local_Sobel_dy,ui->Otsu_in_edge_checkBox->isChecked(),0.5,0.5);
            break;
        case SCHARR:
            //double weight_dx = 1.0*(ui->Scharr_weight_dx_horizontalSlider/100);
            //double weight_dy = 1.0*(ui->Scharr_weight_dy_horizontalSlider/100);
            Segmented_image = Local_Scharr(processed_image,Local_Scharr_numberofSubImages,Local_Scharr_hist_percentile,
                                           ui->Local_Scharr_dx_checkBox->isChecked(),ui->Local_Scharr_dy_checkBox->isChecked(),
                                           ui->Otsu_in_edge_checkBox->isChecked(),(double)ui->Scharr_weight_dx_horizontalSlider->value()/100
                                                                                 ,(double)ui->Scharr_weight_dy_horizontalSlider->value()/100);
            break;
        case OTSU:
            if(ui->Gradient_equalizer_checkBox->isChecked())
            {

            }
            Segmented_image = Local_Otsu(processed_image,Local_Otsu_numberofSubImages);
            break;
        case THRESHOLDING:
            Segmented_image = Naive_Thresholding(processed_image,Naive_threshold);
            break;
        case ADAPTIVE_THRESHOLDING:
            Segmented_image = Adaptive_Thresholding(processed_image,Adaptive_Thresholding_kernel_size,Adaptive_thresholding_C,
                                                    ui->Adaptive_Thresholding_gaussian_radioButton->isChecked());
            break;
        }

        //operations to improve the segmentation result
        if(!Segmented_image.empty())
        {
            if(ui->Inversion_checkbox->isChecked())
            {
                int num_pix = Segmented_image.rows*Segmented_image.cols;
                uchar* data = Segmented_image.ptr<uchar>(0);
                for(int i = 0; i<num_pix;i++)
                {
                    data[i] = 255-data[i];
                }
            }
            if(ui->Dilation_checkBox->isChecked())//maybe dilation before gaussian
            {
                cv::Mat Seg_copy;
                Segmented_image.copyTo(Seg_copy);
                cv::dilate(Seg_copy,Segmented_image,cv::Mat(),cv::Point(-1,-1),Dilation_iterations,cv::BORDER_CONSTANT,cv::morphologyDefaultBorderValue());
            }
        }

        //if a mode is chosen display the modes image instead of the color space image
        switch(mode)
        {
        case NO_MODE:
            //putting the correct color space image and segmented image on display.
            if(ui->Lab->isChecked())
            {
                QImage color_space_image = QImage((const unsigned char*)(lab_image.data),
                                    lab_image.cols,lab_image.rows,QImage::Format_RGB888);
                ui->label->setPixmap(QPixmap::fromImage(color_space_image));
                ui->label->resize(ui->label->pixmap()->size());
            }
            else if(!processed_image.empty())
            {
                QImage color_space_image = QImage((const unsigned char*)(processed_image.data),
                                     processed_image.cols,processed_image.rows,QImage::Format_Indexed8);
                ui->label->setPixmap(QPixmap::fromImage(color_space_image));
                ui->label->resize(ui->label->pixmap()->size());
                ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),1330,120);//moving boxes in accordance to size of image
            }else if(!input_image.empty())
            {
                QImage color_space_image = QImage((const unsigned char*)(input_image.data),
                                     input_image.cols,input_image.rows,QImage::Format_RGB888);
                ui->label->setPixmap(QPixmap::fromImage(color_space_image));
                ui->label->resize(ui->label->pixmap()->size());
                ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),1330,120);//moving boxes in accordance to size of image
            }
            break;
        case HOLE_DETECTION:
            //knaksje ta å lage en ny label, hide processed og vise denne, kan bli fixa på knappetrykka
            hole_detected_image = Hole_detection_algo(Segmented_image);
            if(!hole_detected_image.empty())
            {
                QImage hole_detection_image = QImage((const unsigned char*)(hole_detected_image.data),
                                     hole_detected_image.cols,hole_detected_image.rows,QImage::Format_Indexed8);
                ui->label->setPixmap(QPixmap::fromImage(hole_detection_image));
                ui->label->resize(ui->label->pixmap()->size());
                ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),1330,120);//moving boxes in accordance to size of image
            }
            break;
        case GROWTH_DETECTION:
            if((Percentage_foreground_clean_net > -1) && (!Segmented_image.empty()))
            {
                //gjør noe
                qDebug() << "percentage foreground pixels on clean net: " << Percentage_foreground_clean_net;

                int percentage_growth = Growth_Detection_algo(Percentage_foreground_clean_net,Segmented_image);
                qDebug() << "percentage growth: " << percentage_growth;


            }
            break;

        }

        //Show the segmented image in the right label
        if(!Segmented_image.empty())
        {
            QImage segmented_image = QImage((const unsigned char*)(Segmented_image.data),
                                            Segmented_image.cols,Segmented_image.rows,QImage::Format_Indexed8 );
            ui->processed_image_label->setGeometry(100+ui->label->width(),100,0,0);
            ui->processed_image_label->setPixmap(QPixmap::fromImage(segmented_image));
            ui->processed_image_label->resize(ui->label->pixmap()->size());

        }


}




void MainWindow::on_Sobel_clicked()
{
    thresh_met = SOBEL;
    //hide the different group boxes and show the local sobel one.
    hide_all_seg_boxes();
    ui->Local_Sobel_box->show();
}


void MainWindow::on_Scharr_clicked()
{
    thresh_met = SCHARR;
    //hide the different group boxes and show the global sobel one.
    hide_all_seg_boxes();
    ui->Local_Scharr_box->show();

}

void MainWindow::on_Otsu_clicked()
{
    thresh_met = OTSU;
    //hide the different group boxes and show the global sobel one.
    hide_all_seg_boxes();
    ui->Local_Otsu_box->show();
}

void MainWindow::on_Thresholding_clicked()
{
    thresh_met = THRESHOLDING;
    //hide the different group boxes and show the thresholding one.
    hide_all_seg_boxes();
    ui->Thresholding_box->show();
}

void MainWindow::on_Adaptive_Thresholding_clicked()
{
    thresh_met = ADAPTIVE_THRESHOLDING;
    //hide the different group boxes and show the thresholding one.
    hide_all_seg_boxes();
    ui->Adaptive_Thresholding_box->show();
}

void MainWindow::on_Local_Sobel_horizontalSlider_valueChanged(int value)
{
    Local_Sobel_numberofSubImages = value;
    ui->Local_Sobel_lcdNumber->display(value*value);
}

void MainWindow::on_Local_Scharr_horizontalSlider_valueChanged(int value)
{
    Local_Scharr_numberofSubImages = value;
    ui->Local_Scharr_lcdNumber->display(value*value);
}

void MainWindow::on_Local_Otsu_horizontalSlider_valueChanged(int value)
{
    Local_Otsu_numberofSubImages = value;
    ui->Local_Otsu_lcdNumber->display(value*value);
}

void MainWindow::on_Capture_clicked()
{
    if(!Segmented_image.empty())
    {
        imwrite("Segmented_Image.png", Segmented_image );
    }

    if(!hole_detected_image.empty())
    {
        imwrite("Hole_detected_Image.png", hole_detected_image );
    }
}

void MainWindow::on_Local_Sobel_histogram_slider_valueChanged(int value)
{
    Local_Sobel_hist_percentile = value;
}

void MainWindow::on_Local_Scharr_histogram_slider_valueChanged(int value)
{
    Local_Scharr_hist_percentile = value;
}

void MainWindow::on_Threshold_slider_valueChanged(int value)
{
    Naive_threshold = value;
}

void MainWindow::on_No_Mode_clicked()
{
    mode = NO_MODE;
}

void MainWindow::on_Hole_Detection_clicked()
{
    mode = HOLE_DETECTION;
}

void MainWindow::on_Growth_detection_clicked()
{
    mode = GROWTH_DETECTION;
}

void MainWindow::on_y_clicked()
{
    cspace = Y;
}

void MainWindow::on_x_clicked()
{
   cspace = X;
}

void MainWindow::on_Y_clicked()
{
   cspace = LUMINANCE;
}

void MainWindow::on_Red_clicked()
{
     cspace = RED;
}
void MainWindow::on_Green_clicked()
{
     cspace = GREEN;
}

void MainWindow::on_Blue_clicked()
{
     cspace = BLUE;
}

void MainWindow::on_x2_clicked()
{
    cspace = X2;
}

void MainWindow::on_y2_clicked()
{
    cspace = Y2;
}
void MainWindow::on_Y2_clicked()
{
    cspace = LUMINANCE2;
}

void MainWindow::on_Lab_clicked()
{
    cspace = LAB;
}

void MainWindow::on_L_clicked()
{
    cspace = L;
}

void MainWindow::on_a_clicked()
{
    cspace = A;
}

void MainWindow::on_b_clicked()
{
    cspace = B;
}

void MainWindow::on_Dilation_horizontalSlider_valueChanged(int value)
{
    Dilation_iterations = value;
}

void MainWindow::on_Gaussian_horizontalSlider_valueChanged(int value)
{
    if(value % 2)
    {
        Gaussian_kernel_size = value;
        ui->Gaussian_lcdNumber->display(value);
    }
}


void MainWindow::on_Local_Sobel_dx_slider_valueChanged(int value)
{
    Local_Sobel_dx = value;

}

void MainWindow::on_Local_Sobel_dy_slider_valueChanged(int value)
{
    Local_Sobel_dy = value;

}

void MainWindow::on_Local_Sobel_kernel_slider_valueChanged(int value)
{
    if(value % 2)
    {
        Local_Sobel_kernel_size = value;
        ui->Local_Sobel_kernel_lcdNumber->display(value);
    }
}


void MainWindow::on_Adaptive_Thresholding_kernel_slider_valueChanged(int value)
{
    if(value % 2)
    {
        Adaptive_Thresholding_kernel_size = value;
        ui->Adaptive_Thresholding_kernel_lcdNumber->display(value);
    }

}

void MainWindow::on_Adaptive_Thresholding_C_slider_valueChanged(int value)
{
    Adaptive_thresholding_C = value;
}


void MainWindow::on_Capture_clean_net_pushButton_clicked()
{
    if(!Segmented_image.empty())
    {
        Percentage_foreground_clean_net = percentage_foreground(Segmented_image);
    }

}

//bygg om processframe and update gui
void MainWindow::on_Webcam_source_radioButton_clicked()
{
    capWebcam.release();
    capWebcam.open(0);
    if(capWebcam.isOpened() == false)
    {
        ui->Total_time_spent->appendPlainText("error: Webcam not accessed succesfully");
        return;
    }
    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()),this,SLOT(runCamera()));
    tmrTimer->start(100);
    qDebug() << "opened webcam source";
}

void MainWindow::on_Image_source_radioButton_clicked()
{
    capWebcam.release();
    //cv::Mat file_image;
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    image_from_file = cv::imread(fileName.toLatin1().data()) ;//.toAscii().data()
    //file_image = cv::imread(fileName.toLatin1().data()) ;

    //change color channel ordering
    cv::cvtColor(image_from_file,image_from_file,CV_BGR2RGB);
    //  Qt image
    QImage img = QImage((const unsigned char*)(image_from_file.data),
                        image_from_file.cols,image_from_file.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());
    ui->Bottom_line_box->setGeometry(5,100+ui->label->pixmap()->height(),1330,120);//moving boxes in accordance to size of image

    //rolling it like a video to get operations to work, first change color space to a valid one
    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()),this,SLOT(runImage()));
    //tmrTimer->start(1.0/60); //lavprioritet funksjon, hvis systemet bruker lenger tid får det lov til å btuke lenger tid
    tmrTimer->start(100);
}

void MainWindow::on_Video_source_radioButton_clicked()
{
    capWebcam.release();
    fileName = QFileDialog::getOpenFileName(this,tr("Open Video"),".",tr("Video Files (*.avi *.mp4 *.wmv)"));
  //  image_from_file = cv::imread(fileName.toLatin1().data()) ;//.toAscii().data()
    //cv::VideoCapture capWebcam(fileName.toLatin1().data());
    capWebcam.open(fileName.toLatin1().data());
    if(capWebcam.isOpened() == false)
    {
        ui->Total_time_spent->appendPlainText("error: Video not accessed succesfully");
        return;
    }


    video_file_FPS = capWebcam.get(CV_CAP_PROP_FPS);
    qDebug() << "FPS " << video_file_FPS;


    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()),this,SLOT(runVideo()));
    //tmrTimer->start(1.0/60); //lavprioritet funksjon, hvis systemet bruker lenger tid får det lov til å btuke lenger tid
    tmrTimer->start(100);


}

void MainWindow::runCamera()
{
    if(PAUSE == false)
    {
        cv::Mat camera_image;
        capWebcam.read(camera_image);
        if(camera_image.empty()==true) return;

        double duration;
        duration = static_cast<double>(cv::getTickCount());

        //change color channel ordering
        cv::cvtColor(camera_image,camera_image,CV_BGR2RGB);

        MainWindow::processFrameAndUpdateGUI(camera_image);

        //time measurment part
        duration = static_cast<double>(cv::getTickCount())-duration;
        duration /=cv::getTickFrequency();//elapsed time in ms
        ui->Total_time_spent->appendPlainText(QString::number(duration) + QString("s"));

    }
}
void MainWindow::runImage()
{
    if(image_from_file.empty()==true) return;

    if(PAUSE == false)
    {
        double duration;
        duration = static_cast<double>(cv::getTickCount());

        MainWindow::processFrameAndUpdateGUI(image_from_file);

        //time measurment part
        duration = static_cast<double>(cv::getTickCount())-duration;
        duration /=cv::getTickFrequency();//elapsed time in ms
        ui->Total_time_spent->appendPlainText(QString::number(duration) + QString("s"));

    }
}
void MainWindow::runVideo()
{
    if(PAUSE == false)
    {
        double duration;
        duration = static_cast<double>(cv::getTickCount());

        cv::Mat video_frame;



        //lag en ting som sykler ut frames på balgrunn av framerate kontra prosseseringstid
        bool end_of_video = false;
        int frame_not_found = 0; //gives the system the chance to process videos missing frames
        while(end_of_video==false)
        {
            capWebcam.read(video_frame);

            if(!video_frame.empty())
            {
                cv::cvtColor(video_frame,video_frame,CV_BGR2RGB);
                //qDebug() << "valid frame" << video_frame.cols << video_frame.rows;
                MainWindow::processFrameAndUpdateGUI(video_frame);
                end_of_video = true;
            }
            else
            {
                frame_not_found +=1;
            }

            if(frame_not_found >100)
            {
                capWebcam.release();
                capWebcam.open(fileName.toLatin1().data());
                if(capWebcam.isOpened() == false)
                {
                    ui->Total_time_spent->appendPlainText("error: Video not accessed succesfully");
                    return;
                }
                end_of_video = true;
            }

        }


        //time measurment part
        duration = static_cast<double>(cv::getTickCount())-duration;
        duration /=cv::getTickFrequency();//elapsed time in ms
        ui->Total_time_spent->appendPlainText(QString::number(duration) + QString("s"));

    }

}

void MainWindow::on_actionPause_triggered()
{
    if(PAUSE == true)
    {
        PAUSE = false;
    }
    else
    {
        PAUSE = true;
    }
}

//shuts off the processes
void MainWindow::on_actionDont_Process_triggered()
{
    cspace = COLOR_NONE;
    thresh_met = THRESH_NONE;
    mode = NO_MODE;
    hide_all_seg_boxes();
    processed_image.release();
    ui->processed_image_label->hide();
}

