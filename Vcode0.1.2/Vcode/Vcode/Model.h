#pragma once
#include"Commom.h"
#include"Observable.h"
class Model:public Observable
{
public:
	Model() {}
	~Model() {}
	void loadPicture(Param& p) {
		QImage* pImg = new QImage;
		if (!(pImg->load(QString::fromStdString(p.getPath())))) //¼ÓÔØÍ¼Ïñ
		{
			return;
		}
		QImage *pImgScaled = new QImage;
		*pImgScaled = pImg->scaled(p.getWidth(),p.getHeight(), Qt::KeepAspectRatio);
		QGraphicsScene* s = new  QGraphicsScene();	
		p.setScene(s);
		p.getSence()->addPixmap(QPixmap::fromImage(*pImgScaled));
	
		this->notify(p);
	}
};

