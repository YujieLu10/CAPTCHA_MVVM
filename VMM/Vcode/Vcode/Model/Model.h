#pragma once
#include<Common\Common.h>
#include<opencv2\opencv.hpp>
#include<fstream>
#include<exception>
using namespace std;
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
		try {
			if (grayType < 0) {
				throw exception();
			}
			if (m.empty()) {
				throw exception();
			}
			//begin graym
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
							uchar maxc = max(max(data[i], data[i + 1]), data[i + 2]);
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
			//end graym
			if (graym.empty()) {
				throw exception();
			}
			//begin remove background
			graym.copyTo(removeBGm);
			for (int j = 0; j < nr; j++) {
				uchar* data = removeBGm.ptr<uchar>(j);

				for (int i = 0; i < nc; i++) {
					data[i] = (data[i] > RemoveBG::THRESHOLD) ? 255 : data[i];
				}
			}
			if (removeBGm.empty()) {
				throw exception();
			}
			//end remove bg	
			//begin binary
			removeBGm.copyTo(binarym);
			for (int j = 0; j < nr; j++) {
				uchar* data = binarym.ptr<uchar>(j);

				for (int i = 0; i < nc; i++) {
					data[i] = (data[i] > Binary::THRESHOLD) ? 255 : 0;
					//0 black, 255 white
				}
			}
			if (binarym.empty()) {
				throw exception();
			}
			//end binary
			//begin denoise
			binarym.copyTo(denoisem);
			cv::Mat tmp;
			denoisem.copyTo(tmp);
			int r = Denoise::HALF_RADIUS;
			uchar** datas = new uchar*[nr];
			//erosion
			for (int i = 0; i < nr; i++) {
				datas[i] = binarym.ptr<uchar>(i);
			}
			
			for (int j = r; j < nr - r; j++) {
				uchar* desData = tmp.ptr<uchar>(j);
				
				for (int i = r; i < nc - r; i++) {
					//0 black, 255 white, all 0, then 0
					bool flag = true;
					for (int m = -r; m <= r; m++) {
						for (int n = -r; n <= r; n++) {
							if (datas[j + m][i + n]) {
								flag = false;
								break;
							}
						}
						if (!flag) break;
					}
					if (flag) {
						desData[i] = 0;
					}
					else {
						desData[i] = 255;
					}
				}
			}
			tmp.copyTo(denoisem);
			//dalition
			for (int i = 0; i < nr; i++) {
				datas[i] = denoisem.ptr<uchar>(i);
			}

			for (int j = r; j < nr - r; j++) {
				uchar* desData = tmp.ptr<uchar>(j);

				for (int i = r; i < nc - r; i++) {
					//0 black, 255 white, all 255, then 255
					bool flag = false;
					for (int m = -r; m <= r; m++) {
						for (int n = -r; n <= r; n++) {
							if (!datas[j + m][i + n]) {
								flag = true;
								break;
							}
						}
						if (flag) break;
					}
					if (flag) {
						desData[i] = 0;
					}
					else {
						desData[i] = 255;
					}
				}
			}
			tmp.copyTo(denoisem);
			if (denoisem.empty()) {
				throw exception();
			}
			//end denoise
			string s = "process";
			this->notify(s);
		}
		catch (exception& e) {
			this->notify(false);
		}
	}

};
