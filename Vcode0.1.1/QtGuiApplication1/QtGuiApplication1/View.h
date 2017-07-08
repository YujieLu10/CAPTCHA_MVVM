#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include"Commom.h"
#include"Observer.h"
class View : public QMainWindow,public Observer
{
	Q_OBJECT

public:
	View(QWidget *parent = Q_NULLPTR);
	
	void setLoadPictureCommand(BaseCommand* p) {
		loadPictureCommand = p;
	}
private:
	Ui::QtGuiApplication1Class ui;
	QString filename;
	
	BaseCommand* loadPictureCommand;


private slots:
	
	void importPicture();
};
