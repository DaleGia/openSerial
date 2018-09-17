#ifndef SENSORCONTROL_H
#define SENSORCONTROL_H

#include <QMainWindow>
//#include "QtSerialPort/qserialport.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "QtSerialPort/qserialport.h"
#include "QtSerialPort/qserialportinfo.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QList>
namespace Ui {
class sensorControl;
}

class sensorControl : public QMainWindow
{
    Q_OBJECT

public:
    struct Settings
    {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };

    explicit sensorControl(QWidget *parent = 0);
    ~sensorControl();

private:
    Ui::sensorControl *ui;
    QSerialPort *m_serial = nullptr;
    Settings m_currentSettings;
    void updateSettings();
    void availableSerialUpdate();


    void connectionStatusUpdate();
private slots:
    void openSerialPort();
    void closeSerialPort();
    void readData();
    void fillPortsInfo();
    void on_pushButton_connect_clicked();
    void on_pushButton_disconnect_clicked();
    void on_pushButton_clear_console_clicked();
    void on_pushButton_send_command_clicked();
};

#endif // SENSORCONTROL_H
