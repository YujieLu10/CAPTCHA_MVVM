#include "View.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	View v;
	
	v.show();
	return a.exec();
}


