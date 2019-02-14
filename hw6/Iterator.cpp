#ifndef ITERATOR_CPP

#define ITERATOR_CPP

#include "Iterator.h"
#include <typeinfo>


namespace Iterator_face{


template<class E , class T > 

Iterator<E,T>::Iterator(){
	size_count=0;
	current_pos=0;
}
template<class E , class T > 

Iterator<E,T>::Iterator(int size,decltype(iterator_type.begin()) iterate,T& container){
	current_pos=0;
	size_count=size;
	it=(iterate);
	collection=&container;
}
template<class E , class T > 

bool Iterator<E,T>::hasNext(){
	if(it!=collection->end() )
		//&& current_pos<size_count-1
		return true;
	return false;
}
template<class E , class T > 

E Iterator<E,T>::next(){
	//current_pos+=1;
	return *(it++);		
}
template<class E , class T > 

void Iterator<E,T>::remove(){
	vector<E> vctr;
	list<E> list;
	set<E> set;

	if(typeid(vctr).name()==typeid(*collection).name()){
		collection->erase(--it);
		return;
	}
	else if(typeid(list).name()==typeid(*collection).name() || typeid(set).name()==typeid(*collection).name()){

		decltype(it) temporary_it=it;

		collection->erase(--temporary_it);
		return;	
	}


	//size_count-=1;
	//current_pos-=1;
	}
}

#endif