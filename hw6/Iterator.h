#ifndef ITERATOR_H

#define ITERATOR_H

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


namespace Iterator_face{


template<class E , class T > class Iterator{

	public:

		T iterator_type;
		
		Iterator();
		Iterator(int size,decltype(iterator_type.begin()) iterate,T& container);
		bool hasNext();
		E next();
		void remove();
	private:
		decltype(iterator_type.begin()) it;
		int size_count=0;
		int current_pos=0;
		T *collection;

	};	

}

#endif