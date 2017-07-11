#pragma once
#include "ui_Vcode.h"
#include <Common\Common.h>
#include <QtWidgets/QMainWindow>

class View : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	View(QWidget *parent = Q_NULLPTR);

	void setLoadPictureCommand(shared_ptr<BaseCommand> p) {
		loadPictureCommand = p;
	}
	void setProcessPictureCommand(shared_ptr<BaseCommand> p) {
		processPictureCommand = p;
	}
	void setImg(shared_ptr<QImage> p) {
		pImg = p;
	}
	void setGrayImg(shared_ptr<QImage> p) {
		pGrayImg = p;
	}
	void setDenoiseImg(shared_ptr<QImage> p) {
		pDenoiseImg = p;
	}
	void setRemoveBGImg(shared_ptr<QImage> p) {
		pRemoveBGImg = p;
	}
	void setBinaryImg(shared_ptr<QImage> p) {
		pBinaryImg = p;
	}
private:
	Ui::ViewClass ui;
	QString filename;
	int grayType;
	QGraphicsScene* originScene;
	QGraphicsScene* grayScene;
	QGraphicsScene* denoiseScene;
	QGraphicsScene* removeBGScene;
	QGraphicsScene* binaryScene;

	shared_ptr<BaseCommand> loadPictureCommand;
	shared_ptr<BaseCommand> processPictureCommand;

	shared_ptr<QImage> pImg;
	shared_ptr<QImage> pGrayImg;
	shared_ptr<QImage> pDenoiseImg;
	shared_ptr<QImage> pRemoveBGImg;
	shared_ptr<QImage> pBinaryImg;
	void update(const string& atrribute);
	virtual void commandSucceed(bool flag);

	private slots:
	void processPicture();
	void importPicture();
};
