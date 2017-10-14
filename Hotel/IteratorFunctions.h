#pragma once
#ifndef __ITERATOR_FUNCTIONS_H
#define __ITERATOR_FUNCTIONS_H
#include <vector>

template<class T, class S>
S& getEmployeeByType(vector<T*> vec, S& def)
{
	vector<T*>::const_iterator begin = vec.begin();
	vector<T*>::const_iterator end = vec.end();

	for ( ; begin != end; ++begin)
		if (strcmp(typeid(**begin).name(), typeid(S).name()) == 0)
			return dynamic_cast<S&>(**begin);

	return def;
};

//template<class T>
//T* getRoomByRoomNumber(vector<T*> vec, int roomNumber)
//{
//	vector<T*>::const_iterator begin = vec.begin();
//	vector<T*>::const_iterator end = vec.end();
//
//	for (; begin != end; ++begin)
//		if ((*begin)->getRoomNumber() == roomNumber)
//			return *begin;
//	return nullptr;
//};

template <class T, class S>
S& printAll(vector<T*> vec, S& os)
{
	vector<T*>::const_iterator begin = vec.begin();
	vector<T*>::const_iterator end = vec.end();

	for (; begin != end; ++begin)
	{
		os << **begin << "\n";
	}
	return os;
};

template<class T>
void acceptGeneric(vector<T*> vec, IVisitor* visitor)
{
	vector<T*>::const_iterator begin = vec.begin();
	vector<T*>::const_iterator end = vec.end();

	for (; begin != end; ++begin)
		(*begin)->accept(visitor);
};

template<class T>
void removeEmployee(vector<T*>& vec, int id)
{
	vector<T*>::const_iterator begin = vec.begin();
	vector<T*>::const_iterator end = vec.end();
	for (; begin != end; ++begin)
	{
		if ((*begin)->getId() == id)
		{
			vec.erase(begin);
			return;
		}
	}
};

#endif // __ITERATOR_FUNCTIONS_H