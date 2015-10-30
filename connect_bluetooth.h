#ifndef CONNECT_BLUETOOTH_H
#define CONNECT_BLUETOOTH_H

#include <QDialog>
#include <QListWidgetItem>
#include <qbluetoothglobal.h>
#include <qbluetoothlocaldevice.h>

QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceDiscoveryAgent)
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceInfo)

namespace Ui {
class Connect_Bluetooth;
}

class Connect_Bluetooth : public QDialog
{
    Q_OBJECT

public:
    explicit Connect_Bluetooth(QWidget *parent = 0);
    ~Connect_Bluetooth();

private:
    Ui::Connect_Bluetooth *ui;
    void rejected();

public slots:
    void addDevice(const QBluetoothDeviceInfo&);
    void on_power_clicked(bool clicked);
    void on_discoverable_clicked(bool clicked);
   // void displayPairingMenu(const QPoint &pos);
   // void pairingDone(const QBluetoothAddress&, QBluetoothLocalDevice::Pairing);
private slots:
    void startScan();
    void scanFinished();
    //void setGeneralUnlimited(bool unlimited);
    void itemActivated(QListWidgetItem *item);
    //void hostModeStateChanged(QBluetoothLocalDevice::HostMode);

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;

};

#endif // CONNECT_BLUETOOTH_H
