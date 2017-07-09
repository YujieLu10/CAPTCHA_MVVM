#pragma once
#include"Commom.h"
class Observer
{
private:
	Param m_p;
public:
	Observer() {

	}
	~Observer() {

	}
	void update(Param& p) {
		m_p = p;
	}
};

