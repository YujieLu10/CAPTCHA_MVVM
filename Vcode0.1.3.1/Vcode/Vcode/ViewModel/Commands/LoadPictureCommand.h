#pragma once
#include<Commom\Commom.h>
#include<qdebug.h>
class ViewModel;
class LoadPictureCommand :public BaseCommand {
private:
	ViewModel* pvm;
	shared_ptr<Param> params;
public:

	LoadPictureCommand(ViewModel* p);
	virtual void exec();
	virtual void setParams(const shared_ptr<Param>& p);

};