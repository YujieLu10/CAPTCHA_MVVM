#include "View.h"
#include <QFileDialog>
#include <QMessageBox>
#include<qdebug.h>


View::View(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.importPicAction->setShortcuts(QKeySequence::Open);
	ui.importPicAction->setStatusTip(tr("Import a picture of verification code"));
	

	connect(ui.importPicAction, &QAction::triggered, this, &View::importPicture);
	connect(ui.recognizeButton, SIGNAL(clicked()), this, SLOT(recognizeCode()));
}
void View::importPicture() {

	filename = QFileDialog::getOpenFileName(this, "Select Picture", ".", tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));

	if (!filename.isEmpty()) {
		
		//Param p(filename.toStdString(), ui.graphicsView->width(), ui.graphicsView->height());
		
		//loadPictureCommand->setParams(p);
		
		//loadPictureCommand->exec();
		
		//ui.graphicsView->setScene(loadPictureCommand->getParam().getSence());
	}
}