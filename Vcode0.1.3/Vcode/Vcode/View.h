#pragma once
#include "ui_Vcode.h"
#include "Commom.h"
#include "Observer.h"
#include <QtWidgets/QMainWindow>

class View : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	View(QWidget *parent = Q_NULLPTR);

	void setLoadPictureCommand(BaseCommand* p) {
		loadPictureCommand = p;
	}
private:
	Ui::ViewClass ui;
	QString filename;

	BaseCommand* loadPictureCommand;


private slots:

	void importPicture();
};
