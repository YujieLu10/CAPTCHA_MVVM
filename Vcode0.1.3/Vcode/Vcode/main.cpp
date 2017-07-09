#include "View.h"
#include <QtWidgets/QApplication>
#include"ViewModel.h"
#include"Model.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	View v;
	Model m;
	ViewModel vm(&m);
	v.setLoadPictureCommand(vm.getLoadPictureCommand());
	m.addObserver(&vm);
	vm.addObserver(&v);
	v.show();
	return a.exec();
}
