#include "LinkedList.h"


namespace Linked_list{

template<class E, class T> 

void LinkedList<E,T>::add(E e){

	container.insert(container.end(),e);

}
template<class E, class T> 

E LinkedList<E,T>::element(){
	return *(container.begin());
}

template<class E, class T> 
void LinkedList<E,T>::offer(E e){
	container.insert(container.end(),e);
}
template<class E, class T> 
E LinkedList<E,T>::poll(){
	E temp;
	temp=*(container.begin());

	container.erase(container.begin());
	return temp;
}

template<class E, class T> 
void LinkedList<E,T>::addAll(Collection<E,T>& c){

Collection<E,T> *g=&c;
LinkedList<E,T> *ptr_linkedlist=dynamic_cast<LinkedList<E,T>* >(g);   //if collection is not pointing a ArrayList then dont add collection to my container.

if(ptr_linkedlist!=nullptr){

	for(auto i=ptr_linkedlist->container.begin();i!=ptr_linkedlist->container.end();++i){
		container.insert(container.end(),*i);
	}
}
}

template<class E, class T> 
void LinkedList<E,T>::clear(){
	container.erase(container.begin(),container.end());
}

template<class E,class T>
bool LinkedList<E,T>::contains(E e){

	for(auto i=container.begin();i!=container.end();++i){
		if(*i==e)
			return true;
	}
	return false;
}

template<class E,class T>
bool LinkedList<E,T>::containsAll(Collection<E,T>& c){

Collection<E,T> *g=&c;
LinkedList<E,T> *ptr_linkedlist=dynamic_cast<LinkedList<E,T>* >(g);    //if collection is not pointing a LinkedList then dont check collection.

if(ptr_linkedlist!=nullptr){

	for(auto i=ptr_linkedlist->container.begin();i!=ptr_linkedlist->container.end();++i){
		int all_in=0;
		for(auto j=container.begin();j!=container.end();++j){
			if(*i==*j)
				all_in=1;
		}
		if(all_in==0)
			return false;
	}
	return true;

}
}

template<class E,class T>
bool LinkedList<E,T>::isEmpty(){

	if(size()!=0)
		return false;
	return true;
}

template<class E,class T>
void LinkedList<E,T>::remove(E e){
	for(auto i=container.begin();i!=container.end();++i){
		if(*i==e){
			container.erase(i);
			i--;
		}
	}
}

template<class E,class T>
void LinkedList<E,T>::removeAll(Collection<E,T>& c)throw(int){

Collection<E,T> *g=&c;
LinkedList<E,T> *ptr_linkedlist=dynamic_cast<LinkedList<E,T>* >(g);    //if collection is not pointing a LinkedList then dont chech collection.

if(ptr_linkedlist!=nullptr){

	for(auto i=ptr_linkedlist->container.begin();i!=ptr_linkedlist->container.end();++i){
		for(auto j=container.begin();j!=container.end();++j){
			if(*i==*j){
				container.erase(j);
				j--;
			}
		}
	}
}
else
	throw -1;
}

template<class E,class T>
void LinkedList<E,T>::retainAll(Collection<E,T>& c){

Collection<E,T> *g=&c;
LinkedList<E,T> *ptr_linkedlist=dynamic_cast<LinkedList<E,T>* >(g);  //if collection is not pointing a LinkedList then dont checK collection.

if(ptr_linkedlist!=nullptr){


	for(auto j=container.begin();j!=container.end();++j){
		int find_in=0;
		for(auto i=ptr_linkedlist->container.begin();i!=ptr_linkedlist->container.end();++i){
			if(*i==*j)
				find_in=1;
		}
		if(!find_in){
			container.erase(j);
			j--;
		}
	}	
}

}
template<class E,class T>
int LinkedList<E,T>::size(){

	return container.size();
}
}






