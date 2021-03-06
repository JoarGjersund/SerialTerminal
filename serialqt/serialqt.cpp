#include "serialqt.h"
#include <QtSerialPort>
#include <qmessagebox.h>
#include <QDebug>
#include <QMenuBar>
#include <console.h>
#include <QScrollBar>

serialqt::serialqt(QWidget *parent)
	: QMainWindow(parent), m_serial(new QSerialPort(this)), m_console(new Console)
{
	ui.setupUi(this);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	drawMenu();

	drawStatusBar();
	ui.verticalLayout_3->addWidget(m_console);
	connect(m_serial, &QSerialPort::readyRead, this, &serialqt::readData);
}

void serialqt::update() {
	//QCoreApplication::processEvents();
	/*
	m_serial->open(QIODevice::ReadWrite);
	m_serial->waitForReadyRead();
	m_serial->close();
	*/
	timer->start(100);
	
}
void serialqt::drawStatusBar() {

	statusBar_connection = new QLabel("closed", this);
	statusBar()->addWidget(statusBar_connection);
	QString mess = QStringLiteral("Baudrate: %1").arg(9600);
	statusBar_baudrate = new QLabel(mess, this);
	statusBar()->addWidget(statusBar_baudrate);
}



void serialqt::drawMenu()
{



	QMenuBar* menuBar = new QMenuBar(this);
	setMenuBar(menuBar);

	fileMenu = new QMenu("File", this);

		actionQuit = new QAction("Close open port and leave", this);
			fileMenu->addAction(actionQuit);
			QObject::connect(actionQuit, SIGNAL(triggered()), this, SLOT(exitProgram()));

		actionClear = new QAction("Clear terminal", this);
			fileMenu->addAction(actionClear);
			QObject::connect(actionClear, SIGNAL(triggered()), this, SLOT(clearTerminal()));

		this->menuBar()->addMenu(fileMenu);

	settingsMenu = new QMenu("Settings", this);
		subMenuConnect = new QMenu("Connect", this);

			Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) 
			{
				actionPort = new QAction(port.portName()+":"+port.description(), this);
				if (port.isBusy()) {
					QFont bold;
					bold.setStrikeOut(true);
					actionPort->setFont(bold);
				}
				subMenuConnect->addAction(actionPort);

				QSignalMapper* signalMapper = new QSignalMapper(this);
				signalMapper->setMapping(actionPort, port.portName());

				QObject::connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(openSerialPort(QString)));
				connect(actionPort, SIGNAL(triggered()), signalMapper, SLOT(map()));
			}
			actionScan = new QAction("update list", this);
			subMenuConnect->addAction(actionScan);
			QObject::connect(actionScan, SIGNAL(triggered()), this, SLOT(drawMenu()));

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
	m_console->close();
	qApp->exit();
}

void serialqt::clearTerminal()
{
	m_console->clearData();
}
void serialqt::closeSerialPort()
{
	if (m_serial->isOpen())
		m_serial->close();

	QString mess = "closed";
	statusBar_connection->setText(mess);
	statusBar()->update();
}
void serialqt::setBaudrate(int baudrate)
{

	QString mess = QStringLiteral("Baudrate: %1").arg(baudrate);
	statusBar_baudrate->setText(mess);
	statusBar()->update();
	m_serial->setBaudRate(baudrate);
}
void serialqt::openSerialPort(QString portName)
{
	m_serial->setPortName(portName);

	// Baudrate (reset to 9600):
	// m_serial->setBaudRate(9600);
/*
	QString mess = QStringLiteral("Baudrate: %1").arg(9600);
	statusBar_baudrate->setText(mess);
	statusBar()->update();
	*/
	//m_serial->setDataBits(8);
	//m_serial->setParity(0);
	//m_serial->setStopBits(0);
	//m_serial->setFlowControl(p.flowControl);
	
	if (m_serial->open(QIODevice::ReadWrite)) {

		statusBar_connection->setText(portName);
		statusBar()->update();
	}
	else 
	{

		QMessageBox::critical(this, tr("Error"), m_serial->errorString());
	}
	
	ui.autoScroll->setChecked(true);
}

void serialqt::readData()
{
	const QByteArray data = m_serial->readAll();

	m_console->putData(data);

	if (ui.autoScroll->isChecked())
	{
		
		QScrollBar *bar = m_console->verticalScrollBar();
		m_console->verticalScrollBar()->setValue(bar->maximum());
	}
	else 
	{
		m_console->document()->setMaximumBlockCount(-1); // to prevent scrolling.
	}
	

}
void serialqt::writeData()
{
	qDebug("hallo");
	m_serial->write(ui.lineEdit->text().toUtf8());

}

