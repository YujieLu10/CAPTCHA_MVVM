#pragma once
#include"Commom.h"
#include"Model.h"
#include"Observable.h"
#include"Observer.h"
class LoadPictureCommand :public BaseCommand{
private:
	Model* model;
	Param params;
public:
	LoadPictureCommand(Model* p=0):model(p){}
	
	virtual void exec() {
		model->loadPicture(params);
	}
	virtual void setParams(Param p) {
		params = p;
	}
	Param getParam() {
		return params;
	}
};
class ViewModel:public Observable,public Observer
{
private:
	BaseCommand* loadPictureCommand;
public:
	BaseCommand* getLoadPictureCommand() {
		return loadPictureCommand;
	}
	ViewModel(Model* p) {
		loadPictureCommand = new LoadPictureCommand(p);
	}
	~ViewModel() {
		
	}
	void update(Param p) {
		Observer::update(p);
		notify(p);
	}
};

