#pragma once
#include<Commom\Commom.h>

class ViewModel;
class recognizeCommand :public BaseCommand {
private:
	ViewModel* pvm;
	shared_ptr<Param> params;
public:

	recognizeCommand(ViewModel* p);
	virtual void exec();
	virtual void setParams(const shared_ptr<Param>& p);

};