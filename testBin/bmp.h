#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#ifndef _BMP_H
#define _BMP_H

#define BITMAP_ID (0x4D42)
#define Ratio (0.9)

#define ZeroMemory(x, y) memset(x, 0, y);

typedef unsigned char BYTE;
typedef unsigned short U16;
typedef unsigned int   U32;

typedef struct tagBITMAPFILEHEADER
{
	U16 bfType;
	U32 bfSize;
	U16 bfReserved1;
	U16 bfReserved2;
	U32 bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	U32 biSize;
	U32 biWidth;
	U32 biHeight;
	U16 biPlanes;
	U16 biBitCount;
	U32 biCompression;
	U32 biSizeImage;
	U32 biXPelsPerMeter;
	U32 biYPelsPerMeter;
	U32 biClrUsed;
	U32 biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {
	BYTE    rgbBlue;
	BYTE    rgbGreen;
	BYTE    rgbRed;
	BYTE    rgbReserved;
} RGBQUAD;

class BMP
{
	public:
	string name;
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;
	RGBQUAD bmpColorPanel[256];
	BYTE* bmpImg;

	BMP();
	BMP(string fileName);
	BMP(BMP &_bmp);
	~BMP();
	bool open(string fileName);
	void clear();
	bool save(string fileName);
	
};

//Effects
void bmpRGB2Gray(BMP inBMP, BMP& outBMP);
void bmpGray2Binary(BMP inBMP, BMP& outBMP, int thres);
void bmpBinaryErosion(BMP inBMP, BMP& outBMP, int ksize);
void bmpBinaryDilation(BMP inBMP, BMP& outBMP, int ksize);
void bmpBinaryOpen(BMP inBMP, BMP& outBMP, int ksize);
void bmpBinaryClose(BMP inBMP, BMP& outBMP, int ksize);

#endif