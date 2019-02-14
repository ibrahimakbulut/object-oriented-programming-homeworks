
#ifndef QUEUE_H

#define QUEUE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Collection.h"
using namespace std;
using namespace Collection_interface;

namespace Queue_interface{


template<class E,class T> class Queue: virtual public Collection<E,T>{

	public:

		virtual void add(E e)=0;
		virtual E element()=0;
		virtual void offer(E e)=0;
		virtual E poll()=0;

};

}

#endif
