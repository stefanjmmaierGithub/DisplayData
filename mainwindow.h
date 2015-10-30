#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "ui_connect_bluetooth.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();





private slots:
    void on_actionFindDevice_triggered();
    void on_actionEdit_triggered();
    void on_actionDefine_Path_triggered();
    void on_actionLoad_Data_triggered();
    void bt_connect_closed();

private:
    Ui::MainWindow *ui;
    QDialog *bluetoothConnection;                   // Pointer auf den Dialog
    Ui::Connect_Bluetooth Connect_Bluetooth;        // Neuer Dialog

};

#endif // MAINWINDOW_H
