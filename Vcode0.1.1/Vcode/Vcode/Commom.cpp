#include "Commom.h"

ofstream & operator<<(ofstream & os, Param & p)
{
	os << p.path << endl;
	return os;
}

Param & Param::operator=(Param & p)
{
	path = p.path;
	graphicHeight = p.graphicHeight;
	graphicWidth = p.graphicWidth;
	scene = p.scene;
	return *this;
}
