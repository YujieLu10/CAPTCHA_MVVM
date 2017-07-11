#include "bmp.h"

int main(){
	string filename;
	cout << "Input the filename: ";
	cin >> filename;
	BMP original, gray, bin, bin_ero, bin_dil, bin_open, bin_close;
	original.name = "ori";
	gray.name = "gray";
	bin.name = "bin";
	bin_ero.name = "bin_ero";
	bin_dil.name = "bin_dil";
	bin_open.name = "bin_open";
	bin_close.name = "bin_close";

	original.open(filename);
	original.save(filename + ".ori.bmp");
	
	bmpRGB2Gray(original, gray);
	gray.save(filename + ".gray.bmp");

	bmpGray2Binary(gray, bin, 128);
	bin.save(filename + ".bin.bmp");

	bmpBinaryErosion(bin, bin_ero, 3);
	bin_ero.save(filename + ".bin.ero.bmp");

	bmpBinaryDilation(bin, bin_dil, 3);
	bin_dil.save(filename + ".bin.dil.bmp");

	bmpBinaryOpen(bin, bin_dil, 3);
	bin_dil.save(filename + ".bin.open.bmp");
	system("pause");
	bmpBinaryClose(bin, bin_dil, 3);
	bin_dil.save(filename + ".bin.close.bmp");

	return 0;
}