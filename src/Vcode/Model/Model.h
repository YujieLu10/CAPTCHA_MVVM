#pragma once
#include<Common/Common.h>
#include<opencv2/opencv.hpp>
#include<qdebug.h>
#include<fstream>
#include<exception>
#include<string>
class QException :public exception {
private:
	string errorMessage;
public:
	QException(string s=""):errorMessage(s){}
	void setErrorMes(string s){
		errorMessage = s;
	}
	string getErrorMes() { return errorMessage; }
};
using namespace std;
class Model :public Observable
{
protected:
	cv::Mat m;
	cv::Mat graym;
	cv::Mat denoisem;
	cv::Mat removeBGm;
	cv::Mat binarym;
	string res;
	QException e;
public:
	Model() {}
	~Model() {}

	cv::Mat& getMat() { return m; }
	cv::Mat& getGrayMat() { return graym; }
	cv::Mat& getDenoiseMat() { return denoisem; }
	cv::Mat& getRemoveBGMat() { return removeBGm; }
	cv::Mat& getBinaryMat() { return binarym; }
	QException& getException() { return e; }
	string getRes() { return res; }
	wstring UTF8ToUnicode(const string& str);
	void loadPicture(const string& path) {
		m = cv::imread(path, 1);
		if (m.empty()) {
			e.setErrorMes("Load picture failed!");
			this->notify(false);
		}
		else {
			string s = "image";
			this->notify(s);
		}
	}
	void processPicture(int grayType, int removet, int binaryt, int denoiser);
	void solvePicture();
	void saveResult(string savePath);
};