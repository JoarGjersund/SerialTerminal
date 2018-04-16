#pragma once

#include <QPlainTextEdit>

class Console : public QPlainTextEdit
{
	Q_OBJECT

public:
	explicit Console(QWidget *parent = nullptr);
	void putData(const QByteArray & data);
};
