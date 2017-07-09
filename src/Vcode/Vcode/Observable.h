#pragma once
#include"Observer.h"
#include"Commom.h"
#include<vector>
using namespace std;
class Observable
{
private:
	vector<Observer*> observerList;
public:
	Observable() {

	}
	~Observable() {

	}
	void addObserver(Observer* pobj) {
		observerList.push_back(pobj);
	}
	void removeObserver(Observer obj) {
		
	}
	void notify(Param& p) {
		for (auto it = observerList.begin(), end = observerList.end(); it != end; it++) {
			(*it)->update(p);
		}
	}
};

