#pragma once
#include<Common/Common.h>
#include<opencv2/opencv.hpp>
#include<qdebug.h>
#include<fstream>
#include<exception>
#include<string>

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
public:
	Model() {}
	~Model() {}

	cv::Mat& getMat() { return m; }
	cv::Mat& getGrayMat() { return graym; }
	cv::Mat& getDenoiseMat() { return denoisem; }
	cv::Mat& getRemoveBGMat() { return removeBGm; }
	cv::Mat& getBinaryMat() { return binarym; }
	string getRes() { return res; }
	void loadPicture(const string& path) {
		m = cv::imread(path, 1);
		if (m.empty()) {
			this->notify(false);
		}
		else {
			string s = "image";
			this->notify(s);
		}
	}
	void processPicture(int grayType);
	void solvePicture();
	void saveResult(string savePath);
};