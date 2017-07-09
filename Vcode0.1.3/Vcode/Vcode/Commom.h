#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<memory>
#include<qgraphicsscene.h>
using namespace std;

class Param {
private:
	string path;
	int graphicWidth;
	int graphicHeight;
	QGraphicsScene* scene;
public:
	Param(string s="",int w=0,int h=0):path(s),graphicHeight(h),graphicWidth(w){}

	string getPath() { return path; }
	int getWidth() { return graphicWidth; }
	int getHeight() { return graphicHeight; }
	void setScene(QGraphicsScene* p) { scene = p; }
	QGraphicsScene* getSence() { return scene; }
	friend ofstream& operator<<(ofstream& os,Param& p);
	Param& operator=(Param& p);
};

class BaseCommand {
private:
	Param params;
public:
	virtual void setParams(Param p) = 0;
	virtual void exec() = 0;
	virtual Param getParam() = 0;
};

