#ifndef LINKED_LIST_H

#define LINKED_LIST_H

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "List.h"
#include "Queue.h"
#include "Iterator.cpp"

using namespace List_interface;
using namespace Iterator_face;
using namespace Queue_interface;
using namespace std;

namespace Linked_list{



template<class E,class T> class LinkedList: public List<E,T>, public Queue<E,T>{

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
		E element();
		void offer(E e);
		E poll();


	private:
		T container;


};

}

#endif