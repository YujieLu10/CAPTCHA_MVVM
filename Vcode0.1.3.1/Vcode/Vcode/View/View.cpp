#include<View\View.h>
#include <QFileDialog>
#include <QMessageBox>
#include <qdebug.h>
using namespace std;

View::View(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.importPicAction->setShortcuts(QKeySequence::Open);
	ui.importPicAction->setStatusTip(tr("Import a picture of verification code"));

	connect(ui.importPicAction, &QAction::triggered, this, &View::importPicture);
}
void View::importPicture() {

	filename = QFileDialog::getOpenFileName(this, "Select Picture", ".", tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));

	if (!filename.isEmpty()) {

		shared_ptr<StringParam> sp = make_shared<StringParam>();
		sp->setPath(filename.toStdString());

		loadPictureCommand->setParams(static_pointer_cast<Param,StringParam>(sp));

		loadPictureCommand->exec();
		
	}
}
void View::update(const string& attribute) {
	if (attribute == "image") {
		QGraphicsScene* scene=new QGraphicsScene();
		scene->addPixmap(QPixmap::fromImage(pImg->scaled(ui.graphicsView->width(), ui.graphicsView->height(), Qt::KeepAspectRatio)));
		ui.graphicsView->setScene(scene);
	}
}
void View::commandSucceed(bool flag) {
	if (!flag) {
		QMessageBox::critical(this, "Error", "Error!");
	}
}