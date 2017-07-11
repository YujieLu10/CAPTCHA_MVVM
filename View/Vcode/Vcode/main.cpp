#include<View/View.h>
#include <QtWidgets/QApplication>
#include<QtGui\qbitmap.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	shared_ptr<View> pv(new View);
	
	pv->show();
	return a.exec();
}
