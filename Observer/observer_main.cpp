/*
 * observer_main.cpp
 *
 *  Created on: Jun 28, 2014
 *      Author: nishiba
 */

#include <iostream>
#include <boost/bind/bind.hpp>
#include "Observable.h"

//!
class Data : public Observable<Data> {
public:
	//!
	Data(double x) : _x(x) {}

	//!
	void setData(double x)
	{
		_x = x;
		this->notify();
	}
private:
	double _x;
};

//!
class Observer {
public:
	//!
	Observer(const Data& data)
	{
		boost::function<void(const Data&)>
			f = boost::bind(&Observer::update, this, _1);
		data.addObserver(f);
	}

	//!
	void update(const Data& d)
	{
		std::cout << "I'm a Observer!!" << std::endl;
	}
private:
};


int main()
{
	Data d(1.0);
	Observer o(d);
	d.setData(2.0);
	d.setData(3.0);
	return 0;
}
