#include "Hashset.h"



namespace Hash_set{
template<class E, class T> 

void HashSet<E,T>::add(E e){

	int find=0;

	for(auto j=container.begin();j!=container.end();++j){
		if(e==*j)
			find=1;
	}
	if(find!=1)
		container.insert(container.end(),e);

}

template<class E, class T> 

void HashSet<E,T>::addAll(Collection<E,T>& c){


Collection<E,T> *g=&c;
HashSet<E,T> *ptr_set=dynamic_cast<HashSet<E,T>* >(g);   //if collection is not pointing a Hashset then dont add collection to my container.

if(ptr_set!=nullptr){

	for(auto i=ptr_set->container.begin();i!=ptr_set->container.end();++i){
		int find=0;
		for(auto j=container.begin();j!=container.end();++j){
			if(*i==*j)
				find=1;
		}
		if(find!=1)
			container.insert(container.end(),*i);
	}


}
}

template<class E, class T>
void HashSet<E,T>::clear(){

	container.erase(container.begin(),container.end());
}


template<class E,class T>
bool HashSet<E,T>::contains(E e){

	for(auto i=container.begin();i!=container.end();++i){
		if(*i==e)
			return true;
	}
	return false;
}
template<class E,class T>
bool HashSet<E,T>::containsAll(Collection<E,T>& c){


Collection<E,T> *g=&c;
HashSet<E,T> *ptr_set=dynamic_cast<HashSet<E,T>* >(g);   //if collection is not pointing a Hashset then dont chech collection.

if(ptr_set!=nullptr){

	for(auto i=ptr_set->container.begin();i!=ptr_set->container.end();++i){
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
bool HashSet<E,T>::isEmpty(){

	if(size()!=0)
		return false;
	return true;
}

template<class E,class T>
void HashSet<E,T>::remove(E e){
	for(auto i=container.begin();i!=container.end();++i){
		if(*i==e){
			container.erase(i);
			i--;
		}
	}
}

template<class E,class T>
void HashSet<E,T>::removeAll(Collection<E,T>& c)throw(int){


Collection<E,T> *g=&c;
HashSet<E,T> *ptr_set=dynamic_cast<HashSet<E,T>* >(g);   //if collection is not pointing a Hashset then dont chech collection.

if(ptr_set!=nullptr){

	for(auto i=ptr_set->container.begin();i!=ptr_set->container.end();++i){
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
void HashSet<E,T>::retainAll(Collection<E,T>& c){


Collection<E,T> *g=&c;
HashSet<E,T> *ptr_set=dynamic_cast<HashSet<E,T>* >(g);  //if collection is not pointing a Hashset then dont chech collection.

if(ptr_set!=nullptr){


	for(auto j=container.begin();j!=container.end();++j){
		int find_in=0;
		for(auto i=ptr_set->container.begin();i!=ptr_set->container.end();++i){
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
int HashSet<E,T>::size(){

	return container.size();
}



}



