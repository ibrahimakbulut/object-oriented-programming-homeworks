#ifndef HASH_SET_H

#define HASH_SET_H

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "Set.h"
#include "Iterator.cpp"

using namespace Set_interface;
using namespace std;
using namespace Iterator_face;

namespace Hash_set{



template<class E,class T> class HashSet: public Set<E,T>{

	public:

		Iterator<E,T> iterator(){

			return Iterator<E,T>(size(),container.begin(),container);
		}
		void add(E e);
		void addAll(Collection<E,T>& c);
		void clear();
		bool contains(E e);
		bool containsAll(Collection<E,T>& c);
		bool isEmpty();
		void remove(E e);
		void removeAll(Collection<E,T>& c)throw(int);
		void retainAll(Collection<E,T>& c);
		int size();         

	private:
		T container;


};

}

#endif