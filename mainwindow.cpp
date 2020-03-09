#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileInfo>
#include <QDateTime>
#include <QFileDialog>
#include <QtDebug>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_imagebtn_clicked() // Creating a function for the "choose an image" Button
{
    QString FileImageName =  QFileDialog:: getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg*.jpeg*.bmp*.gif)"));

    if (QString::compare(FileImageName, QString()) != 0) // Checking if user picked an image
    {
        QImage image;
        bool found = image.load(FileImageName);

        if (found)
        {
            image = image.scaledToWidth(ui->imageLabel->width(), Qt::SmoothTransformation);// scaling image to fit label
            ui->imageLabel->setPixmap(QPixmap::fromImage(image));// putting image in label
        }
        else
        {
            // error . somthing went wrong =(
        }
    }
}

void MainWindow::on_pushButton_clicked()
{

}
