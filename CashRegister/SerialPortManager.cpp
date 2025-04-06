#include "SerialPortManager.h"
#include <QDebug>

SerialPortManager::SerialPortManager(QObject* parent)
	: QObject(parent), serialPort(new QSerialPort(this)) {
	connect(serialPort, &QSerialPort::readyRead, this, &SerialPortManager::handleReadyRead);
}

SerialPortManager::~SerialPortManager() {
	closeSerialPort();
}

bool SerialPortManager::openSerialPort(const QString& portName, qint32 baudRate) {
	serialPort->setPortName(portName);
	serialPort->setBaudRate(baudRate);
	serialPort->setDataBits(QSerialPort::Data8);
	serialPort->setParity(QSerialPort::NoParity);
	serialPort->setStopBits(QSerialPort::OneStop);
	serialPort->setFlowControl(QSerialPort::NoFlowControl);

	if (serialPort->open(QIODevice::ReadWrite)) {
		qDebug() << "Serial port opened successfully.";
		return true;
	}
	else {
		qDebug() << "Failed to open serial port:" << serialPort->errorString();
		return false;
	}
}

void SerialPortManager::closeSerialPort() {
	if (serialPort->isOpen()) {
		serialPort->close();
		qDebug() << "Serial port closed.";
	}
}

void SerialPortManager::writeData(const QByteArray& data) {
	if (serialPort->isOpen()) {
		serialPort->write(data);
	}
}

QStringList SerialPortManager::getAvailablePorts() const {
	QStringList portList;
	foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts()) {
		portList << info.portName();
	}
	return portList;
}

void SerialPortManager::handleReadyRead() {
	QByteArray data = serialPort->readAll();
	emit dataReceived(data);
}
