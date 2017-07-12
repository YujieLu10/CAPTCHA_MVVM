#include<View/View.h>
#include <QtWidgets/QApplication>
#include<QtGui/qbitmap.h>
#include <qsplashscreen.h>
#include <qelapsedtimer.h>

const int SPLASHTIME = 2000;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	shared_ptr<View> pv(new View);

	//initial
	QPixmap initialPixmap("image\\bg.png");
	QSplashScreen splash(initialPixmap);
	splash.show();
	QElapsedTimer timer;
	timer.start();
	while (timer.elapsed() < SPLASHTIME)
		a.processEvents();
	splash.close();

	
	//modify background
	QPixmap backgroundPixmap("image\\bg2.jpg");
	QPalette qp;
	qp.setBrush(pv->backgroundRole(), QBrush(backgroundPixmap));
	pv->setPalette(qp);
	pv->setMask(backgroundPixmap.mask());
	pv->setAutoFillBackground(true);

	pv->show();


	return a.exec();
}

