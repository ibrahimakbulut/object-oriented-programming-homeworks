
#ifndef LIST_H

#define LIST_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Collection.h"
using namespace std;
using namespace Collection_interface;

namespace List_interface{



template<class E, class T> class List: virtual  public Collection<E,T>{

	public:

/*		void iterator();
		void add(E e);
		void addAll(Collection c);
		void clear();
		bool contains(E e);
		bool containsAll(Collection c);
		bool isEmpty();
		void remove(E e);
		void removeAll(Collection c);
		void retainAll(Collection c);
		int size();     */

};

}

#endif