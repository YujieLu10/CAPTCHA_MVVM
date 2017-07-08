#include"Solve.h"
wstring UTF8ToUnicode(const string& str)
{
	int  len = 0;
	len = str.length();
	int  unicodeLen = ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t* pUnicode;
	pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);
	wstring rt;
	rt = (wchar_t*)pUnicode;
	delete pUnicode;
	return rt;
}
string solve(const char* path) {
	string outText;
	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
	// Initialize tesseract-ocr with English, without specifying tessdata path
	if (api->Init(NULL, "eng")) {
		cout << "Could not initialize tesseract.\n";
		exit(1);
	}

	// Open input image with leptonica library
	Pix *image = pixRead(path);
	api->SetImage(image);
	// Get OCR result
	outText = api->GetUTF8Text();
	api->End();
	pixDestroy(&image);
	return outText;
}
