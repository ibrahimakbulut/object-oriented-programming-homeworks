
#ifndef COLLECTION_H

#define COLLECTION_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Iterator.cpp"
using namespace std;
using namespace Iterator_face;

namespace Collection_interface{



template<class E , class T > class Collection{

	public:
		//virtual ~Shape()=default;


		virtual Iterator<E,T> iterator()=0;
		virtual void add(E e)=0;
		virtual void addAll(Collection<E,T>& c)=0;
		virtual void clear()=0;
		virtual bool contains(E e)=0;
		virtual bool containsAll(Collection<E,T>& c)=0;
		virtual bool isEmpty()=0;
		virtual void remove(E e)=0;
		virtual void removeAll(Collection<E,T>& c)=0;
		virtual void retainAll(Collection<E,T>& c)=0;
		virtual int size()=0;

};

}

#endif
