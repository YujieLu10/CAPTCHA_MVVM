#pragma once

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include<iostream>
#include<string>
#include <locale>
#include<fstream>
#include<string>
#pragma  comment(lib,"libtesseract304d.lib") 
#pragma  comment(lib,"liblept171d.lib")
using namespace std;

string solve(const char* path);

wstring UTF8ToUnicode(const string& str);
