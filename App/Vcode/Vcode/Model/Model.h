#pragma once
#include<Commom\Commom.h>
#include<opencv2\opencv.hpp>
#include<qdebug.h>
#include<fstream>

class Model :public Observable
{
protected:
	cv::Mat m;
	cv::Mat graym;
	cv::Mat denoisem;
	cv::Mat removeBGm;
	cv::Mat binarym;
public:
	Model() {}
	~Model() {}

	cv::Mat& getMat() { return m; }
	cv::Mat& getGrayMat() { return graym; }
	cv::Mat& getDenoiseMat() { return denoisem; }
	cv::Mat& getRemoveBGMat() { return removeBGm; }
	cv::Mat& getBinaryMat() { return binarym; }
	void loadPicture(const string& path) {
		m = cv::imread(path, 1);
		if (m.empty()) {
			this->notify(false);
		}
		else {
			qDebug() << m.rows << " " << m.cols << endl << m.channels();
			string s = "image";
			this->notify(s);
		}
	}
	void processPicture(int grayType) {
		if (grayType < 0) {
			this->notify(false);
		}
		else if (m.empty()) {
			this->notify(false);
		}
		else {
			m.copyTo(graym);
			int nr = m.rows; // number of rows
			int nc = m.cols * m.channels(); // total number of elements per line
			switch (grayType) {
				case GrayType::GRAY_AVERAGE: {
					for (int j = 0; j < nr; j++) {
						uchar* data = m.ptr<uchar>(j);
						uchar* data1 = graym.ptr<uchar>(j);
						for (int i = 0; i < nc; i += 3) {
							data1[i] = data1[i + 1] = data1[i + 2] = (data[i] + data[i + 1] + data[i + 2]) / 3;
						}
					}
					break;
				}
				case GrayType::GRAY_MAX: {
					for (int j = 0; j < nr; j++) {
						uchar* data = m.ptr<uchar>(j);
						uchar* data1 = graym.ptr<uchar>(j);
						for (int i = 0; i < nc; i += 3) {
							uchar maxc = max(max(data[i], data[i + 1]), data[i+2]);
							data1[i] = data1[i + 1] = data1[i + 2] = maxc;
						}
					}
					break;
				}
				case GrayType::GRAY_WEIGHTAVE: {
					for (int j = 0; j < nr; j++) {
						uchar* data = m.ptr<uchar>(j);
						uchar* data1 = graym.ptr<uchar>(j);
						for (int i = 0; i < nc; i += 3) {
							data1[i] = data1[i + 1] = data1[i + 2] = 0.3*data[i + 2] + 0.59*data[i + 1] + 0.11*data[i];
							//i Blue; i+1 Green; i+2 Red
						}
					}
					break;
				}
			}


			if (graym.empty()) {
				this->notify(false);
			}
			else {
				string s = "process";
				this->notify(s);
			}
		}

	}
};