#include "serialqt.h"
#include <QtSerialPort>
#include <qmessagebox.h>
#include <QDebug>
#include <QMenuBar>
serialqt::serialqt(QWidget *parent)
	: QMainWindow(parent), m_serial(new QSerialPort(this))
{
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(100);

	drawMenu();
	ui.setupUi(this);
	model = new QStringListModel(this);

	connect(m_serial, &QSerialPort::readyRead, this, &serialqt::readData);
}

void serialqt::update() {
	//QCoreApplication::processEvents();
	timer->start(100);
}
void serialqt::drawMenu()
{



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

			Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) 
			{
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

		subMenuBaudrate = new QMenu("Baudrate", this);
			Q_FOREACH(int baudrate, QSerialPortInfo::standardBaudRates()) 
			{
			actionBaudrate = new QAction(QString::number(baudrate), this);
			subMenuBaudrate->addAction(actionBaudrate);
			
			QSignalMapper* signalMapper2 = new QSignalMapper(this);
			signalMapper2->setMapping(actionBaudrate, baudrate);

			QObject::connect(signalMapper2, SIGNAL(mapped(int)), this, SLOT(setBaudrate(int)));
			connect(actionBaudrate, SIGNAL(triggered()), signalMapper2, SLOT(map()));
			
			}
			settingsMenu->addMenu(subMenuBaudrate);

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
void serialqt::setBaudrate(int baudrate)
{
	m_serial->setBaudRate(baudrate);
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

