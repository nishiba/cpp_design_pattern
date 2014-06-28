/*
 * Observable.h
 *
 *  Created on: Jun 28, 2014
 *      Author: nishiba
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_


#include <list>
#include <boost/function.hpp>
#include <boost/foreach.hpp>

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
//!
template <typename T>
class Observable {
private:
	//!
	typedef boost::function<void(const T&)> call_back_function_type;
public:
	//!
	~Observable() {}
	//!
	void addObserver(call_back_function_type& f) const
	{
		_observers.push_back(f);
	}
protected:
	//!
	void notify() const
	{
		BOOST_FOREACH(const call_back_function_type& f, _observers)
		{
			f(static_cast<const T&>(*this));
		}
	}
private:
	//!
	mutable std::list<call_back_function_type> _observers;
};



#endif /* OBSERVABLE_H_ */
