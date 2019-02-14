#include "ArrayList.h"


namespace Array_list{


template<class E, class T> 

void ArrayList<E,T>::add(E e){

	container.insert(container.begin(),e);

}

template<class E, class T> 
void ArrayList<E,T>::addAll(Collection<E,T>& c){

Collection<E,T> *g=&c;
ArrayList<E,T> *ptr_arraylist=dynamic_cast<ArrayList<E,T>* >(g);   //if collection is not pointing a ArrayList then dont add collection to my container.

if(ptr_arraylist!=nullptr){

	for(auto i=ptr_arraylist->container.begin();i!=ptr_arraylist->container.end();++i){
		container.insert(container.begin(),*i);
	}
}
}

template<class E, class T> 
void ArrayList<E,T>::clear(){
	container.erase(container.begin(),container.end());
}

template<class E,class T>
bool ArrayList<E,T>::contains(E e){

	for(auto i=container.begin();i!=container.end();++i){
		if(*i==e)
			return true;
	}
	return false;
}

template<class E,class T>
bool ArrayList<E,T>::containsAll(Collection<E,T>& c){

Collection<E,T> *g=&c;
ArrayList<E,T> *ptr_arraylist=dynamic_cast<ArrayList<E,T>* >(g);    //if collection is not pointing a ArrayList then dont check collection.

if(ptr_arraylist!=nullptr){

	for(auto i=ptr_arraylist->container.begin();i!=ptr_arraylist->container.end();++i){
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
bool ArrayList<E,T>::isEmpty(){

	if(size()!=0)
		return false;
	return true;
}

template<class E,class T>
void ArrayList<E,T>::remove(E e){
	for(auto i=container.begin();i!=container.end();++i){
		if(*i==e){
			container.erase(i);
			i--;
		}
	}
}

template<class E,class T>
void ArrayList<E,T>::removeAll(Collection<E,T>& c)throw(int){

Collection<E,T> *g=&c;
ArrayList<E,T> *ptr_arraylist=dynamic_cast<ArrayList<E,T>* >(g);   //if collection is not pointing a Hashset then dont chech collection.

if(ptr_arraylist!=nullptr){

	for(auto i=ptr_arraylist->container.begin();i!=ptr_arraylist->container.end();++i){
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
void ArrayList<E,T>::retainAll(Collection<E,T>& c){

Collection<E,T> *g=&c;
ArrayList<E,T> *ptr_arraylist=dynamic_cast<ArrayList<E,T>* >(g);    //if collection is not pointing a Hashset then dont chech collection.

if(ptr_arraylist!=nullptr){


	for(auto j=container.begin();j!=container.end();++j){
		int find_in=0;
		for(auto i=ptr_arraylist->container.begin();i!=ptr_arraylist->container.end();++i){
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
int ArrayList<E,T>::size(){

	return container.size();
}
}






