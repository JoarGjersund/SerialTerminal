#include "serialqt.h"
#include <QtSerialPort>
#include <qmessagebox.h>
#include <QDebug>
#include <QMenuBar>
serialqt::serialqt(QWidget *parent)
	: QMainWindow(parent), m_serial(new QSerialPort(this))
{
	drawMenu();
	ui.setupUi(this);
	model = new QStringListModel(this);
	connect(m_serial, &QSerialPort::readyRead, this, &serialqt::readData);

}
void serialqt::drawMenu()
{
	// testing branch...
	// also testing branch ...
	QMenuBar* menuBar = new QMenuBar(this);
	setMenuBar(menuBar);

	fileMenu = new QMenu("File", this);
		actionQuit = new QAction("Close open port and leave", this);
			connect(m_serial, &QSerialPort::readyRead, this, &serialqt::readData);
			fileMenu->addAction(actionQuit);
			QObject::connect(actionQuit, SIGNAL(triggered()), this, SLOT(exitProgram()));
		this->menuBar()->addMenu(fileMenu);

	settingsMenu = new QMenu("Settings", this);
		subMenuConnect = new QMenu("Connect", this);

			Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
				actionPort = new QAction(port.portName()+":"+port.description(), this);
				subMenuConnect->addAction(actionPort);

				QSignalMapper* signalMapper = new QSignalMapper(this);
				signalMapper->setMapping(actionPort, port.portName());

				QObject::connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(openSerialPort(QString)));
				connect(actionPort, SIGNAL(triggered()), signalMapper, SLOT(map()));
			}
			settingsMenu->addMenu(subMenuConnect);

		actionDisconnect = new QAction("disconnect", this);
			settingsMenu->addAction(actionDisconnect);
			QObject::connect(actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
		this->menuBar()->addMenu(settingsMenu);

}
void serialqt::exitProgram()
{
	closeSerialPort();
	qApp->exit();
}
void serialqt::closeSerialPort()
{
	if (m_serial->isOpen())
		m_serial->close();
}
void serialqt::openSerialPort(QString portName)
{
	qDebug("hallo");
	
	m_serial->setPortName(portName);
	m_serial->setBaudRate(9600);
	//m_serial->setDataBits(8);
	//m_serial->setParity(0);
	//m_serial->setStopBits(0);
	//m_serial->setFlowControl(p.flowControl);
	if (m_serial->open(QIODevice::ReadWrite)) {

		
	}
	else 
	{
		QMessageBox::critical(this, tr("Error"), m_serial->errorString());
	}
}

void serialqt::readData()
{
	const QByteArray data = m_serial->readAll();

	
	// Make data
	QStringList List;
	List << model->stringList() << data;

	// Populate our model
	model->setStringList(List);

	// Glue model and view together
	ui.listView->setModel(model);

	if (ui.autoScroll->isChecked())
	{
		ui.listView->scrollToBottom();
	}

}
void serialqt::writeData()
{
	qDebug("hallo");
	//m_serial->write(data);
}

