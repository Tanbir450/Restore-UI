#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui/QPalette>
#include <QMessageBox>
#include <QFileDialog>
#include "dialog.h"
#include <qstorageinfo.h>
#include <qdebug.h>
#include <stdlib.h>
#include <QProcess>
#include<iostream>
#include <stdio.h>
#include <QTimer>
#include <fstream>
using namespace std;
#include<qprocess.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      QPixmap bkgnd("/home/tanbir/Pictures/Tanbir2.png");
      bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
      QPalette palette;
      palette.setBrush(QPalette::Background, bkgnd);
      this->setPalette(palette);
      ui->pushButton_2->setStyleSheet("background-color: #CCCCFF");
      ui->pushButton_3->setStyleSheet("background-color: #CCCCFF");
      ui->pushButton->setStyleSheet("background-color: #CCCCFF");
      ui->comboBox->setStyleSheet ("background-color:#CCCCFF");
        ui->comboBox->addItem ("USB ");


}

MainWindow::~MainWindow()
{
    delete ui;
}
int i=1;

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton_2->setText("Backup");
    ui->progressBar->setStyleSheet ("background-color: #CCCCFF");
    ui->progressBar->setStyleSheet ("background-color: #CCCCFF");
    ui->progressBar->setOrientation(Qt::Horizontal);
    ui->progressBar->setRange(0, 100); // Let's say it goes from 0 to 100
    ui->progressBar->setValue(100); // With a current value of 50
    QPalette p = palette();
    p.setColor(QPalette::Highlight, Qt::green);
    setPalette(p);
    p.setColor(QPalette::Base, Qt::red);

    if((i==1))
    {
        setStyleSheet("pushButton_2 { background-color: white; }\n"
                      "pushButton_2:enabled { background-color: yellow; }\n");
        i=i+1;

    }
    else
    {
        if((i==2))
        {
            setStyleSheet("pushButton{ background-color: grey; }\n"
                          "pushButton:enabled { background-color: rgb(0,200,0); }\n");
         i=i+1;
        }
        else
        {
            setStyleSheet("pushButton{ background-color: grey; }\n"
                          "pushButton:enabled { background-color: rgb(0,0,200); }\n");
            i=i-2;
        }

}

}


void MainWindow::on_pushButton_2_clicked()
{

    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();

}


void MainWindow::on_pushButton_3_clicked()
{
 close ();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QStorageInfo storage = QStorageInfo::root();

    qDebug() << storage.rootPath();
    if (storage.isReadOnly())
        qDebug() << "isReadOnly:" << storage.isReadOnly();

    qDebug() << "name:" << storage.name();
    qDebug() << "fileSystemType:" << storage.fileSystemType();
    qDebug() << "size:" << storage.bytesTotal()/1024/1024 << "MB";
    qDebug() << "availableSize:" << storage.bytesAvailable()/1024/1024 << "MB";
}

void MainWindow::on_pushButton_4_clicked()
{
    QProcess process;
    process.start("echo your_password | sudo -S mkdir /bin/myDir");

   //system("su");
//    system ("g++ a.cc -o a");

     //system ("sudo id -u -r");
   system ("sudo yum -y install rear syslinux-extlinux grub2-efi-x64-modules");
    system("sudo rear format /dev/nfs://your.NFS.server.IP/path");
    system("sudo nano /etc/rear/local.conf");

      ofstream MyFile("sudo nano /etc/rear/local.conf");

          // Write to the file
          MyFile << "OUTPUT=USB" <<endl<<"BACKUP=NETFS"<<endl <<"BACKUP_URL=”usb:///dev/disk/by-label/REAR-000""";


          // Close the file
         MyFile.close();
    system("sudo nano /etc/rear/local.conf");
    system("sudo make rpm");


//    system("sudo chmod +x tanin.sh");
//    system("./tanin.sh");
    //system("sudo yum update");


    system ("sudo rear -v mkbackup");


}
