#pragma once
#include<Common\Common.h>
#include<Model\model.h>
#include<ViewModel\Commands\LoadPictureCommand.h>
#include<ViewModel\Commands\ProcessPictureCommand.h>
#include<QImage>
#include<fstream>
class ViewModel:public Observable,public Observer
{
private:
	shared_ptr<QImage> pImg;
	shared_ptr<QImage> pGrayImg;
	shared_ptr<QImage> pRemoveBGImg;
	shared_ptr<QImage> pDenoiseImg;
	shared_ptr<QImage> pBinaryImg;
	shared_ptr<BaseCommand> loadPictureCommand;
	shared_ptr<BaseCommand> processPictureCommand;
	shared_ptr<Model> model;
public:
	
	shared_ptr<BaseCommand> getLoadPictureCommand() {
		return loadPictureCommand;
	}
	shared_ptr<BaseCommand> getProcessPictureCommand() {
		return processPictureCommand;
	}
	ViewModel() {
		loadPictureCommand =static_pointer_cast<BaseCommand,LoadPictureCommand>(shared_ptr<LoadPictureCommand>(new LoadPictureCommand(this)));
		processPictureCommand = static_pointer_cast<BaseCommand, ProcessPictureCommand>(shared_ptr<ProcessPictureCommand>(new ProcessPictureCommand(this)));
		pImg = shared_ptr<QImage>(new QImage());
		pGrayImg = shared_ptr<QImage>(new QImage());
		pRemoveBGImg = shared_ptr<QImage>(new QImage());
		pDenoiseImg = shared_ptr<QImage>(new QImage());
		pBinaryImg = shared_ptr<QImage>(new QImage());
	}
	~ViewModel() {
		
	}
	void setModel(shared_ptr<Model>& m) {
		model = m;
	}
	void loadPicture(const string& path) {
		model->loadPicture(path);
	}
	void processPicture(int grayType) {
		model->processPicture(grayType);
	}
	shared_ptr<QImage> getpImg() { return pImg; }
	shared_ptr<QImage> getpGrayImg() { return pGrayImg; }
	shared_ptr<QImage> getpRemoveBGImg() { return pRemoveBGImg; }
	shared_ptr<QImage> getpDenoiseImg() { return pDenoiseImg; }
	shared_ptr<QImage> getpBinaryImg() { return pBinaryImg; }
	QImage cvMatToQImage(const cv::Mat &inMat)
	{
		switch (inMat.type())
		{
			// 8-bit, 4 channel
			case CV_8UC4:
			{
				QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32);
				return image;
			}
			// 8-bit, 3 channel
			case CV_8UC3:
			{
				QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888);
				return image.rgbSwapped();
			}
			// 8-bit, 1 channel
			case CV_8UC1:
			{
				static QVector<QRgb>  sColorTable;
				// only create our color table once
				if (sColorTable.isEmpty())
				{
					for (int i = 0; i < 256; ++i)
						sColorTable.push_back(qRgb(i, i, i));
				}
				QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8);
				image.setColorTable(sColorTable);
				return image;
			}
			default:
				break;
		}
		return QImage();

	}
	void update(const string& attribute) {
		if (attribute == "image") {
			
			*pImg = cvMatToQImage(model->getMat());
			if (pImg->isNull()) {
				notify(false);
			}
			else {
				string s = "image";
				notify(s);
			}
		}
		else if (attribute == "process") {
			*pGrayImg = cvMatToQImage(model->getGrayMat());
			*pRemoveBGImg = cvMatToQImage(model->getRemoveBGMat());
			*pDenoiseImg = cvMatToQImage(model->getDenoiseMat());
			*pBinaryImg = cvMatToQImage(model->getBinaryMat());
			if (pGrayImg->isNull()) {
				notify(false);
			}
			else {
				string s = "process";
				notify(s);
			}
		}
	}
	virtual void commandSucceed(bool flag) {
		notify(flag);
	}
};

