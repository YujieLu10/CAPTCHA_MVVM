#include <string.h>
#include <malloc.h>

#include "bmp.h"

BMP::BMP() :
bmpImg(NULL){}

BMP::BMP(string fileName) :
bmpImg(NULL){
	open(fileName);
}

BMP::~BMP(){
	clear();
}

BMP::BMP(BMP& _bmp) :
bmpImg(NULL){
	bmpFileHeader = _bmp.bmpFileHeader;
	bmpInfoHeader = _bmp.bmpInfoHeader;
	name = _bmp.name;
	for (int i = 0; i < 256; i++)
		bmpColorPanel[i] = _bmp.bmpColorPanel[i];
	if (_bmp.bmpImg){
		bmpImg = new BYTE[bmpInfoHeader.biSizeImage];
		for (int i = 0; i < bmpInfoHeader.biSizeImage; i++)
			bmpImg[i] = _bmp.bmpImg[i];
	}
}

bool BMP::open(string fileName){
	clear();
	// Open the BMP file
	FILE *bmpFile = fopen(fileName.c_str(), "rb");
	if (bmpFile == NULL){
		fprintf(stderr, "Error in load bitmap file process: the file doesn't exist\n");
		return false;
	}
	// Get this BMP's file header
	fread(&bmpFileHeader, 14, 1, bmpFile);
	if (bmpFileHeader.bfType != BITMAP_ID){
		fprintf(stderr, "Error in load bitmap file process: the file is not a bitmap file\n");
		return false;
	}
	// Get this BMP's info header
	fread(&bmpInfoHeader, 40, 1, bmpFile);
	//fseek(bmpFile, bmpFileHeader.bfOffBits, SEEK_SET);
	bmpImg = (BYTE*)malloc(bmpInfoHeader.biSizeImage * sizeof(BYTE));
	if (!bmpImg){
		fprintf(stderr, " Error in load bitmap file process: memory error\n");
		return false;
	}
	// Get this BMP's color panel
	if (bmpInfoHeader.biBitCount == 8)
		fread(&bmpColorPanel, sizeof(RGBQUAD), 256, bmpFile);
	// Get this BMP's all pixels
	fread(bmpImg, 1, bmpInfoHeader.biSizeImage, bmpFile);
	if (bmpImg == NULL){
		fprintf(stderr, "Error in load bitmap file process: memory error\n");
		return false;
	}
	fclose(bmpFile);
	return 1;
}

void BMP::clear(){
	ZeroMemory(&bmpFileHeader, sizeof(bmpFileHeader));
	ZeroMemory(&bmpInfoHeader, sizeof(bmpInfoHeader));
	if(bmpImg) delete[] bmpImg;
	bmpImg = NULL;
	ZeroMemory(bmpColorPanel, sizeof(bmpColorPanel));
}

bool BMP::save(string fileName){
	if (bmpImg == NULL)	return false;
	FILE *file = fopen(fileName.c_str() , "wb");
	if (file == NULL){
		fprintf(stderr, "Error in output file process: the file doesn't open\n");
		return 0;
	}
	fwrite(&bmpFileHeader, 14, 1, file);
	fwrite(&bmpInfoHeader, 40, 1, file);
	if (bmpInfoHeader.biBitCount == 8) fwrite(&bmpColorPanel, 1024, 1, file);
	fwrite(bmpImg, 1, bmpInfoHeader.biSizeImage, file);
	fclose(file);
	return true;
}

// Convert RGB to YUV
float getYUV(int type, BYTE R, BYTE G, BYTE B, float intensity) {
	float ans = 0;
	switch (type) {
		case 0: { ans = R * 0.299000f + G *  0.587000f + B * 0.114000f; break; }
		case 1: { ans = -R * 0.168736f - G * 0.331264f + B * 0.500000f + 128.0f; break; }
		case 2: { ans = R * 0.500000f - G * 0.418688f - B * 0.081312f + 128.0f; break; }
		default: break;
	}
	ans = (intensity * ans);
	if (ans > 255.0f) ans = 255.0f;
	if (ans < 1e-6f) ans = 0.0f;
	return ans;
}

// Convert YUV to RGB
BYTE getRGB(int type, float Y, float U, float V) {
	switch (type) {
		case 0: return Y + 1.4075f * (V - 128.0f);
		case 1: return Y - 0.3455f * (U - 128.0f) - (0.7169f * (V - 128.0f));
		case 2: return Y + 1.7790f * (U - 128.0f);
	}
	return 0;
}

void bmpRGB2Gray(BMP inBMP, BMP& outBMP){
	if (!inBMP.bmpImg) return;
	outBMP.clear();
	outBMP.bmpFileHeader = inBMP.bmpFileHeader;
	outBMP.bmpInfoHeader = inBMP.bmpInfoHeader;
	outBMP.bmpInfoHeader.biBitCount = 8;
	int biSizeImage = inBMP.bmpInfoHeader.biSizeImage;
	switch (inBMP.bmpInfoHeader.biBitCount){
		case 24:{
						 outBMP.bmpInfoHeader.biSizeImage = biSizeImage / 3;
						 outBMP.bmpImg = new BYTE[biSizeImage / 3];
						 for (int bmpIdx = 0; bmpIdx < biSizeImage; bmpIdx += 3){
							 outBMP.bmpImg[bmpIdx / 3] = getYUV(0, 
																									inBMP.bmpImg[bmpIdx + 2],
																									inBMP.bmpImg[bmpIdx + 1],
																									inBMP.bmpImg[bmpIdx + 0], 1.0);
						 }
						 for (int i = 0; i < 256; ++i){
							 RGBQUAD r = { (BYTE)i, (BYTE)i, (BYTE)i, (BYTE)0 };
							 outBMP.bmpColorPanel[i] = r;
						 }
						 break;
		}
		case 8:{
						  outBMP.bmpImg = new BYTE[biSizeImage];
							outBMP.bmpInfoHeader.biSizeImage = biSizeImage;
							// To grey image
							for (int bmpIdx = 0; bmpIdx < biSizeImage; ++bmpIdx){
								int idx = inBMP.bmpImg[bmpIdx];
								outBMP.bmpImg[bmpIdx] = getYUV(0,
																							 inBMP.bmpColorPanel[idx].rgbRed,
																							 inBMP.bmpColorPanel[idx].rgbGreen,
																							 inBMP.bmpColorPanel[idx].rgbBlue, 1.0);
							}
							for (int bmpIdx = 0; bmpIdx < 256; ++bmpIdx){
								// Convert RGB to YUV in the panel
								float Y = getYUV(0, inBMP.bmpColorPanel[bmpIdx].rgbRed,
																 inBMP.bmpColorPanel[bmpIdx].rgbGreen, 
																 inBMP.bmpColorPanel[bmpIdx].rgbBlue, Ratio);
								float U = getYUV(1, inBMP.bmpColorPanel[bmpIdx].rgbRed, 
																 inBMP.bmpColorPanel[bmpIdx].rgbGreen, 
																 inBMP.bmpColorPanel[bmpIdx].rgbBlue, 1.0);
								float V = getYUV(2, inBMP.bmpColorPanel[bmpIdx].rgbRed, 
																 inBMP.bmpColorPanel[bmpIdx].rgbGreen, 
																 inBMP.bmpColorPanel[bmpIdx].rgbBlue, 1.0);
								// Back to RGB in the panel
								BYTE R = getRGB(0, Y, U, V);
								BYTE G = getRGB(1, Y, U, V);
								BYTE B = getRGB(2, Y, U, V);
								RGBQUAD rgbquad;
								rgbquad.rgbBlue = B;
								rgbquad.rgbGreen = G;
								rgbquad.rgbRed = R;
								rgbquad.rgbReserved = 0;
								outBMP.bmpColorPanel[bmpIdx] = rgbquad;
							}
							break;
		}
	}
}

void bmpGray2Binary(BMP inBMP, BMP& outBMP, int thres){
	if (!inBMP.bmpImg) return;
	outBMP.clear();
	outBMP.bmpFileHeader = inBMP.bmpFileHeader;
	outBMP.bmpInfoHeader = inBMP.bmpInfoHeader;
	int biSizeImage = inBMP.bmpInfoHeader.biSizeImage;
	if (inBMP.bmpInfoHeader.biBitCount == 8){
		outBMP.bmpImg = new BYTE[outBMP.bmpInfoHeader.biSizeImage];
		ZeroMemory(outBMP.bmpImg, sizeof(outBMP.bmpImg));
		for (int i = 0; i < biSizeImage; i++){
			outBMP.bmpImg[i] = ((inBMP.bmpImg[i]>=thres) ? 255 : 0);
			//cout << "gray2bin: " << i << endl;
		}
		for (int i = 0; i < 256; i++){
			RGBQUAD t = { i, i, i, 0 };
			outBMP.bmpColorPanel[i] = t;
		}
		//cout << "111\n";
	}
	//cout << "???\n";
}

void bmpBinaryErosion(BMP inBMP, BMP& outBMP, int ksize){
	if (!inBMP.bmpImg) return;
	outBMP.clear();
	outBMP.bmpFileHeader = inBMP.bmpFileHeader;
	outBMP.bmpInfoHeader = inBMP.bmpInfoHeader;
	int biSizeImage = inBMP.bmpInfoHeader.biSizeImage;
	if (inBMP.bmpInfoHeader.biBitCount == 8){
		outBMP.bmpImg = new BYTE[biSizeImage];
		ZeroMemory(outBMP.bmpImg, sizeof(outBMP.bmpImg));
		for (int index = 0; index < biSizeImage; index++){
			int nowx = index % inBMP.bmpInfoHeader.biWidth;
			int nowy = index / inBMP.bmpInfoHeader.biWidth;
			int min = 255;
			for (int j = 0; j < ksize; j++){
				for (int i = 0; i < ksize; i++){
					int tx = nowx + i - ksize / 2;
					int ty = nowy + j - ksize / 2;
					if (tx < 0 || tx >= inBMP.bmpInfoHeader.biWidth ||
							ty < 0 || ty >= inBMP.bmpInfoHeader.biHeight)
						continue;
					int pos = tx + ty*inBMP.bmpInfoHeader.biWidth;
					if (inBMP.bmpImg[pos] < min)
						min = inBMP.bmpImg[pos];
				}
			}
			outBMP.bmpImg[index] = min;
		}
		for (int i = 0; i < 256; i++){
			RGBQUAD t = { i, i, i, 0 };
			outBMP.bmpColorPanel[i] = t;
		}
	}
}

void bmpBinaryDilation(BMP inBMP, BMP& outBMP, int ksize){
	if (!inBMP.bmpImg) return;
	outBMP.clear();
	outBMP.bmpFileHeader = inBMP.bmpFileHeader;
	outBMP.bmpInfoHeader = inBMP.bmpInfoHeader;
	int biSizeImage = inBMP.bmpInfoHeader.biSizeImage;
	if (inBMP.bmpInfoHeader.biBitCount == 8){
		outBMP.bmpImg = new BYTE[biSizeImage];
		ZeroMemory(outBMP.bmpImg, sizeof(outBMP.bmpImg));
		for (int index = 0; index < biSizeImage; index++){
			int nowx = index % inBMP.bmpInfoHeader.biWidth;
			int nowy = index / inBMP.bmpInfoHeader.biWidth;
			int max = 0;
			for (int j = 0; j < ksize; j++){
				for (int i = 0; i < ksize; i++){
					int tx = nowx + i - ksize / 2;
					int ty = nowy + j - ksize / 2;
					if (tx < 0 || tx >= inBMP.bmpInfoHeader.biWidth ||
							ty < 0 || ty >= inBMP.bmpInfoHeader.biHeight)
						continue;
					int pos = tx + ty*inBMP.bmpInfoHeader.biWidth;
					if (inBMP.bmpImg[pos] > max) max = inBMP.bmpImg[pos];
				}
			}
			outBMP.bmpImg[index] = max;
		}
		for (int i = 0; i < 256; i++){
			RGBQUAD t = { i, i, i, 0 };
			outBMP.bmpColorPanel[i] = t;
		}
	}
}

void bmpBinaryOpen(BMP inBMP, BMP& outBMP, int ksize){
	BMP temp;
	temp.name = "temp";
	bmpBinaryErosion(inBMP, temp, ksize);
	bmpBinaryDilation(temp, outBMP, ksize);
}

void bmpBinaryClose(BMP inBMP, BMP& outBMP, int ksize){
	BMP temp;
	bmpBinaryDilation(inBMP, temp, ksize);
	bmpBinaryErosion(temp, outBMP, ksize);
}