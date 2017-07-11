#include<View/View.h>
#include <QtWidgets/QApplication>
#include<ViewModel\ViewModel.h>
#include<Model/Model.h>
#include<QtGui\qbitmap.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	shared_ptr<View> pv(new View);
	shared_ptr<Model> pm(new Model);
	shared_ptr<ViewModel> pvm(new ViewModel());
	pvm->setModel(pm);
	//bind command
	pv->setLoadPictureCommand(pvm->getLoadPictureCommand());
	pv->setProcessPictureCommand(pvm->getProcessPictureCommand());
	//bind data
	pv->setImg(pvm->getpImg());
	pv->setGrayImg(pvm->getpGrayImg());
	pv->setDenoiseImg(pvm->getpDenoiseImg());
	pv->setBinaryImg(pvm->getpBinaryImg());
	pv->setRemoveBGImg(pvm->getpRemoveBGImg());
	
	//observer
	pm->addObserver(static_pointer_cast<Observer, ViewModel>(pvm));
	pvm->addObserver(static_pointer_cast<Observer, View>(pv));

	
	/*QPixmap pixmap("image/bg.png");
	QPalette qp;
	qp.setBrush(pv->backgroundRole(), QBrush(pixmap));
	pv->setPalette(qp);
	pv->setMask(pixmap.mask());
	pv->setAutoFillBackground(true);*/
	pv->show();
	return a.exec();
}
