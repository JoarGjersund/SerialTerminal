#include "console.h"
#include <QScrollBar>
Console::Console(QWidget *parent)
	: QPlainTextEdit(parent)
{
	document()->setMaximumBlockCount(1000);
	QPalette p = palette();
	p.setColor(QPalette::Base, Qt::white);
	p.setColor(QPalette::Text, Qt::black);
	setPalette(p);
}


void Console::putData(const QByteArray &data)
{
	insertPlainText(data);
	QScrollBar *bar = verticalScrollBar();
}