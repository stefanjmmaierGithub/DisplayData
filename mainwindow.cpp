#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "connect_bluetooth.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bluetoothConnection = new QDialog;
    bluetoothConnection -> setModal(true);
    Connect_Bluetooth.setupUi(bluetoothConnection);
    connect(bluetoothConnection,SIGNAL(finished(int)),this,SLOT(bt_connect_closed()));
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionFindDevice_triggered()
{

    bluetoothConnection->show();
    ui->lcdNumber->display(Connect_Bluetooth.lcdNumber->value());
}


void MainWindow::bt_connect_closed()
{
   ui->lcdNumber->display(Connect_Bluetooth.lcdNumber->value());
}


void MainWindow::on_actionEdit_triggered()
{
    qDebug()<<"Edit";

}

void MainWindow::on_actionDefine_Path_triggered()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                                 QString(), tr("TXT-Files (*.txt);;All Files (*)"));
      // if (fn.isEmpty());
       if (! (fn.endsWith(".odt", Qt::CaseInsensitive) || fn.endsWith(".txt", Qt::CaseInsensitive)) )
           fn += ".txt"; // default

      qDebug()<<fn;
}


void MainWindow::on_actionLoad_Data_triggered()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                                  QString(), tr("TXT-Files (*.txt);;All Files (*)"));
    QFile file(fn);
            if(!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0,"info",file.errorString());
   QTextStream in(&file);
   ui->textBrowser->setText(in.readAll());
}

