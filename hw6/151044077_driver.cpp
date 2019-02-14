#include <vector>
#include <iostream>
#include <typeinfo>
#include <string>
#include <list>
#include <set>

#include "Collection.h"

using namespace Collection_interface;

#include "Hashset.cpp"
#include "ArrayList.cpp" 
#include "LinkedList.cpp"


using namespace Hash_set;
using namespace Array_list;
using namespace Linked_list;

using  namespace std;


int main(){

	
Iterator<int,vector<int> > it1;

HashSet<int,vector<int> > collect1;

HashSet<int,vector<int> > inner_collect1;

for(int i=0;i<20;++i){
	inner_collect1.add(i);
}

for(int i=150;i<160;++i){
	collect1.add(i*2);
}
collect1.add(5);
collect1.add(8);
collect1.add(13);

collect1.addAll(inner_collect1);


if(collect1.contains(30))
	cout<<"collect1 contain 30"<<endl;

if(collect1.containsAll(inner_collect1))
	cout<<"collect1 contain all of them inner_collect1"<<endl;

collect1.retainAll(inner_collect1);
try{
collect1.removeAll(inner_collect1);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect1.add(10);
collect1.remove(10);

cout<<collect1.size()<<endl;

collect1.addAll(inner_collect1);
collect1.clear();

cout<<collect1.size()<<endl;

it1=collect1.iterator();
while(it1.hasNext()){
	cout<<it1.next()<<endl;
}

if(collect1.containsAll(inner_collect1))
	cout<<"collect1 contain all of them inner_collect1 again"<<endl;

if(!collect1.isEmpty())
	cout<<"collect1 is not empty"<<endl;
else
	cout<<"collect1 is empty"<<endl;


cout<<"-------------------------------------------------------------------------------------"<<endl;


Iterator<int,set<int> > it2;

HashSet<int,set<int> > collect2;

HashSet<int,set<int> > inner_collect2;

for(int i=0;i<20;++i){
	inner_collect2.add(i);
}

for(int i=150;i<160;++i){
	collect2.add(i*2);
}
collect2.add(5);
collect2.add(8);
collect2.add(13);

collect2.addAll(inner_collect2);


if(collect2.contains(30))
	cout<<"collect2 contain 30"<<endl;

if(collect2.containsAll(inner_collect2))
	cout<<"collect2 contain all of them inner_collect2"<<endl;

collect2.retainAll(inner_collect2);
try{
collect2.removeAll(inner_collect2);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect2.add(10);
collect2.remove(10);

cout<<collect2.size()<<endl;

collect2.addAll(inner_collect2);
collect2.clear();

cout<<collect2.size()<<endl;

it2=collect2.iterator();
while(it2.hasNext()){
	cout<<it2.next()<<endl;
}

if(collect2.containsAll(inner_collect2))
	cout<<"collect2 contain all of them inner_collect2 again"<<endl;

if(!collect2.isEmpty())
	cout<<"collect2 is not empty"<<endl;
else
	cout<<"collect2 is empty"<<endl;





cout<<"-------------------------------------------------------------------------"<<endl;



Iterator<int,list<int> > it3;

HashSet<int,list<int> > collect3;

HashSet<int,list<int> > inner_collect3;

for(int i=0;i<20;++i){
	inner_collect3.add(i);
}

for(int i=150;i<160;++i){
	collect3.add(i*2);
}
collect3.add(5);
collect3.add(8);
collect3.add(13);

collect3.addAll(inner_collect3);


if(collect3.contains(30))
	cout<<"collect3 contain 30"<<endl;

if(collect3.containsAll(inner_collect3))
	cout<<"collect3 contain all of them inner_collect3"<<endl;

collect3.retainAll(inner_collect3);
try{
collect3.removeAll(inner_collect3);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect3.add(10);
collect3.remove(10);

cout<<collect3.size()<<endl;

collect3.addAll(inner_collect3);
collect3.clear();

cout<<collect3.size()<<endl;

it3=collect3.iterator();
while(it3.hasNext()){
	cout<<it3.next()<<endl;
}

if(collect3.containsAll(inner_collect3))
	cout<<"collect3 contain all of them inner_collect3 again"<<endl;

if(!collect3.isEmpty())
	cout<<"collect3 is not empty"<<endl;
else
	cout<<"collect3 is empty"<<endl;




cout<<"---------------------------------------------------------------------------------"<<endl;


Iterator<string,vector<string> > it4;

HashSet<string,vector<string> > collect4;

HashSet<string,vector<string> > inner_collect4;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect4.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect4.add(s);
}
string s1="number"+to_string(5);
collect4.add(s1);
s1="number"+to_string(8);
collect4.add(s1);
s1="number"+to_string(13);
collect4.add(s1);

collect4.addAll(inner_collect4);

it4=collect4.iterator();
while(it4.hasNext()){
	cout<<it4.next()<<endl;
}


if(collect4.contains("number30"))
	cout<<"collect4 contain number30"<<endl;

if(collect4.containsAll(inner_collect4))
	cout<<"collect4 contain all of them inner_collect4"<<endl;

collect4.retainAll(inner_collect4);
try{
collect4.removeAll(inner_collect4);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s1="number"+to_string(600);
collect4.add(s1);
collect4.remove(s1);

cout<<collect4.size()<<endl;

collect4.addAll(inner_collect4);
collect4.clear();

cout<<collect4.size()<<endl;

it4=collect4.iterator();
while(it4.hasNext()){
	cout<<it4.next()<<endl;
}

if(collect4.containsAll(inner_collect4))
	cout<<"collect4 contain all of them inner_collect4 again"<<endl;

if(!collect4.isEmpty())
	cout<<"collect4 is not empty"<<endl;
else
	cout<<"collect4 is empty"<<endl;



cout<<"------------------------------------------------------------------------"<<endl;


Iterator<string,set<string> > it5;

HashSet<string,set<string> > collect5;

HashSet<string,set<string> > inner_collect5;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect5.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect5.add(s);
}
string s2="number"+to_string(5);
collect5.add(s2);
s2="number"+to_string(8);
collect5.add(s2);
s2="number"+to_string(13);
collect5.add(s2);

collect5.addAll(inner_collect5);

it5=collect5.iterator();
while(it5.hasNext()){
	cout<<it5.next()<<endl;
}


if(collect5.contains("number30"))
	cout<<"collect5 contain number30"<<endl;

if(collect5.containsAll(inner_collect5))
	cout<<"collect5 contain all of them inner_collect5"<<endl;

collect5.retainAll(inner_collect5);
try{
collect5.removeAll(inner_collect5);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s2="number"+to_string(600);
collect5.add(s2);
collect5.remove(s2);

cout<<collect5.size()<<endl;

collect5.addAll(inner_collect5);
collect5.clear();

cout<<collect5.size()<<endl;

it5=collect5.iterator();
while(it5.hasNext()){
	cout<<it5.next()<<endl;
}

if(collect5.containsAll(inner_collect5))
	cout<<"collect5 contain all of them inner_collect5 again"<<endl;

if(!collect5.isEmpty())
	cout<<"collect5 is not empty"<<endl;
else
	cout<<"collect5 is empty"<<endl;


cout<<"---------------------------------------------------------------------"<<endl;


Iterator<string,list<string> > it6;

HashSet<string,list<string> > collect6;

HashSet<string,list<string> > inner_collect6;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect6.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect6.add(s);
}
string s3="number"+to_string(5);
collect6.add(s3);
s3="number"+to_string(8);
collect6.add(s3);
s3="number"+to_string(13);
collect6.add(s3);

collect6.addAll(inner_collect6);

it6=collect6.iterator();
while(it6.hasNext()){
	cout<<it6.next()<<endl;
}


if(collect6.contains("number30"))
	cout<<"collect6 contain number30"<<endl;

if(collect6.containsAll(inner_collect6))
	cout<<"collect6 contain all of them inner_collect6"<<endl;

collect6.retainAll(inner_collect6);
try{
collect6.removeAll(inner_collect6);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s3="number"+to_string(600);
collect6.add(s3);
collect6.remove(s3);

cout<<collect6.size()<<endl;

collect6.addAll(inner_collect6);
collect6.clear();

cout<<collect6.size()<<endl;

it6=collect6.iterator();
while(it6.hasNext()){
	cout<<it6.next()<<endl;
}

if(collect6.containsAll(inner_collect6))
	cout<<"collect6 contain all of them inner_collect6 again"<<endl;

if(!collect6.isEmpty())
	cout<<"collect6 is not empty"<<endl;
else
	cout<<"collect6 is empty"<<endl;


cout<<"-----------------------------------------------------------------------------"<<endl;


Iterator<int,vector<int> > it7;

ArrayList<int,vector<int> > collect7;

ArrayList<int,vector<int> > inner_collect7;

for(int i=0;i<20;++i){
	inner_collect7.add(i);
}

for(int i=150;i<160;++i){
	collect7.add(i*2);
}
collect7.add(5);
collect7.add(8);
collect7.add(13);

collect7.addAll(inner_collect7);


if(collect7.contains(30))
	cout<<"collect7 contain 30"<<endl;

if(collect7.containsAll(inner_collect7))
	cout<<"collect7 contain all of them inner_collect7"<<endl;

it7=collect7.iterator();
while(it7.hasNext()){
	cout<<it7.next()<<endl;
}



collect7.retainAll(inner_collect7);
try{
collect7.removeAll(inner_collect7);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect7.add(10);
collect7.remove(10);

cout<<collect7.size()<<endl;

collect7.addAll(inner_collect7);
collect7.clear();

cout<<collect7.size()<<endl;

it7=collect7.iterator();
while(it7.hasNext()){
	cout<<it7.next()<<endl;
}

if(collect7.containsAll(inner_collect7))
	cout<<"collect7 contain all of them inner_collect7 again"<<endl;

if(!collect7.isEmpty())
	cout<<"collect7 is not empty"<<endl;
else
	cout<<"collect7 is empty"<<endl;




cout<<"-------------------------------------------------------------------------------------"<<endl;


Iterator<int,set<int> > it8;

ArrayList<int,set<int> > collect8;

ArrayList<int,set<int> > inner_collect8;

for(int i=0;i<20;++i){
	inner_collect8.add(i);
}

for(int i=150;i<160;++i){
	collect8.add(i*2);
}
collect8.add(5);
collect8.add(8);
collect8.add(13);

collect8.addAll(inner_collect8);


if(collect8.contains(30))
	cout<<"collect8 contain 30"<<endl;

if(collect8.containsAll(inner_collect8))
	cout<<"collect8 contain all of them inner_collect8"<<endl;

it8=collect8.iterator();
while(it8.hasNext()){
	cout<<it8.next()<<endl;
}


collect8.retainAll(inner_collect8);
try{
collect8.removeAll(inner_collect8);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect8.add(10);
collect8.remove(10);

cout<<collect8.size()<<endl;

collect8.addAll(inner_collect8);
collect8.clear();

cout<<collect8.size()<<endl;

it8=collect8.iterator();
while(it8.hasNext()){
	cout<<it8.next()<<endl;
}

if(collect8.containsAll(inner_collect8))
	cout<<"collect8 contain all of them inner_collect8 again"<<endl;

if(!collect8.isEmpty())
	cout<<"collect8 is not empty"<<endl;
else
	cout<<"collect8 is empty"<<endl;




cout<<"-------------------------------------------------------------------------"<<endl;




Iterator<int,list<int> > it9;

ArrayList<int,list<int> > collect9;

ArrayList<int,list<int> > inner_collect9;

for(int i=0;i<20;++i){
	inner_collect9.add(i);
}

for(int i=150;i<160;++i){
	collect9.add(i*2);
}
collect9.add(5);
collect9.add(8);
collect9.add(13);

collect9.addAll(inner_collect9);


if(collect9.contains(30))
	cout<<"collect9 contain 30"<<endl;

if(collect9.containsAll(inner_collect9))
	cout<<"collect9 contain all of them inner_collect9"<<endl;

it9=collect9.iterator();
while(it9.hasNext()){
	cout<<it9.next()<<endl;
}


collect9.retainAll(inner_collect9);
try{
collect9.removeAll(inner_collect9);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect9.add(10);
collect9.remove(10);

cout<<collect9.size()<<endl;

collect9.addAll(inner_collect9);
collect9.clear();

cout<<collect9.size()<<endl;

it9=collect9.iterator();
while(it9.hasNext()){
	cout<<it9.next()<<endl;
}

if(collect9.containsAll(inner_collect9))
	cout<<"collect9 contain all of them inner_collect9 again"<<endl;

if(!collect9.isEmpty())
	cout<<"collect9 is not empty"<<endl;
else
	cout<<"collect9 is empty"<<endl;


cout<<"---------------------------------------------------------------------------------"<<endl;


Iterator<string,vector<string> > it10;

ArrayList<string,vector<string> > collect10;

ArrayList<string,vector<string> > inner_collect10;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect10.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect10.add(s);
}
string s4="number"+to_string(5);
collect10.add(s4);
s4="number"+to_string(8);
collect10.add(s4);
s4="number"+to_string(13);
collect10.add(s4);

collect10.addAll(inner_collect10);

it10=collect10.iterator();
while(it10.hasNext()){
	cout<<it10.next()<<endl;
}


if(collect10.contains("number30"))
	cout<<"collect10 contain number30"<<endl;

if(collect10.containsAll(inner_collect10))
	cout<<"collect10 contain all of them inner_collect10"<<endl;

collect10.retainAll(inner_collect10);
try{
collect10.removeAll(inner_collect10);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s4="number"+to_string(600);
collect10.add(s4);
collect10.remove(s4);

cout<<collect10.size()<<endl;

collect10.addAll(inner_collect10);
collect10.clear();

cout<<collect10.size()<<endl;

it10=collect10.iterator();
while(it10.hasNext()){
	cout<<it10.next()<<endl;
}

if(collect10.containsAll(inner_collect10))
	cout<<"collect10 contain all of them inner_collect10 again"<<endl;

if(!collect10.isEmpty())
	cout<<"collect10 is not empty"<<endl;
else
	cout<<"collect10 is empty"<<endl;



cout<<"------------------------------------------------------------------------"<<endl;


Iterator<string,set<string> > it11;

HashSet<string,set<string> > collect11;

HashSet<string,set<string> > inner_collect11;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect11.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect11.add(s);
}
string s5="number"+to_string(5);
collect11.add(s5);
s5="number"+to_string(8);
collect11.add(s5);
s5="number"+to_string(13);
collect11.add(s5);

collect11.addAll(inner_collect11);

it11=collect11.iterator();
while(it11.hasNext()){
	cout<<it11.next()<<endl;
}


if(collect11.contains("number30"))
	cout<<"collect11 contain number30"<<endl;

if(collect11.containsAll(inner_collect11))
	cout<<"collect11 contain all of them inner_collect11"<<endl;

collect11.retainAll(inner_collect11);
try{
collect11.removeAll(inner_collect11);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s5="number"+to_string(600);
collect11.add(s5);
collect11.remove(s5);

cout<<collect11.size()<<endl;

collect11.addAll(inner_collect11);
collect11.clear();

cout<<collect11.size()<<endl;

it11=collect11.iterator();
while(it11.hasNext()){
	cout<<it11.next()<<endl;
}

if(collect11.containsAll(inner_collect11))
	cout<<"collect11 contain all of them inner_collect11 again"<<endl;

if(!collect11.isEmpty())
	cout<<"collect11 is not empty"<<endl;
else
	cout<<"collect11 is empty"<<endl;


cout<<"---------------------------------------------------------------------"<<endl;


Iterator<string,list<string> > it12;

ArrayList<string,list<string> > collect12;

ArrayList<string,list<string> > inner_collect12;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect12.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect12.add(s);
}
string s6="number"+to_string(5);
collect12.add(s6);
s6="number"+to_string(8);
collect12.add(s6);
s6="number"+to_string(13);
collect12.add(s6);

collect12.addAll(inner_collect12);

it12=collect12.iterator();
while(it12.hasNext()){
	cout<<it12.next()<<endl;
}


if(collect12.contains("number30"))
	cout<<"collect12 contain number30"<<endl;

if(collect12.containsAll(inner_collect12))
	cout<<"collect12 contain all of them inner_collect12"<<endl;

collect12.retainAll(inner_collect12);
try{
collect12.removeAll(inner_collect12);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s6="number"+to_string(600);
collect12.add(s6);
collect12.remove(s6);

cout<<collect12.size()<<endl;

collect12.addAll(inner_collect12);
collect12.clear();

cout<<collect12.size()<<endl;

it12=collect12.iterator();
while(it12.hasNext()){
	cout<<it12.next()<<endl;
}

if(collect12.containsAll(inner_collect12))
	cout<<"collect12 contain all of them inner_collect12 again"<<endl;

if(!collect12.isEmpty())
	cout<<"collect12 is not empty"<<endl;
else
	cout<<"collect12 is empty"<<endl;


cout<<"-----------------------------------------------------------------------------"<<endl;




Iterator<int,vector<int> > it13;

LinkedList<int,vector<int> > collect13;

LinkedList<int,vector<int> > inner_collect13;

for(int i=0;i<20;++i){
	inner_collect13.add(i);
}

for(int i=150;i<160;++i){
	collect13.add(i*2);
}
collect13.add(5);
collect13.add(8);
collect13.add(13);

collect13.addAll(inner_collect13);


if(collect13.contains(30))
	cout<<"collect13 contain 30"<<endl;

if(collect13.containsAll(inner_collect7))
	cout<<"collect13 contain all of them inner_collect13"<<endl;

it13=collect13.iterator();
while(it13.hasNext()){
	cout<<it13.next()<<endl;
}



collect13.retainAll(inner_collect13);
try{
collect13.removeAll(inner_collect13);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect13.add(10);
collect13.remove(10);

cout<<collect13.size()<<endl;

collect13.addAll(inner_collect13);
collect13.clear();

cout<<collect13.size()<<endl;

it13=collect13.iterator();
while(it13.hasNext()){
	cout<<it13.next()<<endl;
}

if(collect13.containsAll(inner_collect13))
	cout<<"collect13 contain all of them inner_collect7 again"<<endl;

if(!collect13.isEmpty())
	cout<<"collect13 is not empty"<<endl;
else
	cout<<"collect13 is empty"<<endl;




cout<<"-------------------------------------------------------------------------------------"<<endl;


Iterator<int,set<int> > it14;

LinkedList<int,set<int> > collect14;

LinkedList<int,set<int> > inner_collect14;

for(int i=0;i<20;++i){
	inner_collect14.add(i);
}

for(int i=150;i<160;++i){
	collect14.add(i*2);
}
collect14.add(5);
collect14.add(8);
collect14.add(13);

collect14.addAll(inner_collect14);


if(collect14.contains(30))
	cout<<"collect14 contain 30"<<endl;

if(collect14.containsAll(inner_collect8))
	cout<<"collect14 contain all of them inner_collect14"<<endl;

it14=collect14.iterator();
while(it14.hasNext()){
	cout<<it14.next()<<endl;
}


collect14.retainAll(inner_collect14);
try{
collect14.removeAll(inner_collect14);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect14.add(10);
collect14.remove(10);

cout<<collect14.size()<<endl;

collect14.addAll(inner_collect8);
collect14.clear();

cout<<collect14.size()<<endl;

it14=collect14.iterator();
while(it14.hasNext()){
	cout<<it14.next()<<endl;
}

if(collect14.containsAll(inner_collect14))
	cout<<"collect14 contain all of them inner_collect14 again"<<endl;

if(!collect14.isEmpty())
	cout<<"collect14 is not empty"<<endl;
else
	cout<<"collect14 is empty"<<endl;




cout<<"-------------------------------------------------------------------------"<<endl;




Iterator<int,list<int> > it15;

LinkedList<int,list<int> > collect15;

LinkedList<int,list<int> > inner_collect15;

for(int i=0;i<20;++i){
	inner_collect15.add(i);
}

for(int i=150;i<160;++i){
	collect15.add(i*2);
}
collect15.add(5);
collect15.add(8);
collect15.add(13);

collect15.addAll(inner_collect15);


if(collect15.contains(30))
	cout<<"collect15 contain 30"<<endl;

if(collect15.containsAll(inner_collect15))
	cout<<"collect15 contain all of them inner_collect15"<<endl;

it15=collect15.iterator();
while(it15.hasNext()){
	cout<<it15.next()<<endl;
}


collect15.retainAll(inner_collect15);
try{
collect15.removeAll(inner_collect15);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
collect15.add(10);
collect15.remove(10);

cout<<collect15.size()<<endl;

collect15.addAll(inner_collect15);
collect15.clear();

cout<<collect15.size()<<endl;

it15=collect15.iterator();
while(it15.hasNext()){
	cout<<it15.next()<<endl;
}

if(collect15.containsAll(inner_collect15))
	cout<<"collect15 contain all of them inner_collect15 again"<<endl;

if(!collect15.isEmpty())
	cout<<"collect15 is not empty"<<endl;
else
	cout<<"collect15 is empty"<<endl;


cout<<"---------------------------------------------------------------------------------"<<endl;


Iterator<string,vector<string> > it16;

LinkedList<string,vector<string> > collect16;

LinkedList<string,vector<string> > inner_collect16;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect16.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect16.add(s);
}
string s7="number"+to_string(5);
collect16.add(s4);
s7="number"+to_string(8);
collect16.add(s7);
s7="number"+to_string(13);
collect16.add(s7);

collect16.addAll(inner_collect16);

it16=collect16.iterator();
while(it16.hasNext()){
	cout<<it16.next()<<endl;
}


if(collect16.contains("number30"))
	cout<<"collect16 contain number30"<<endl;

if(collect16.containsAll(inner_collect16))
	cout<<"collect16 contain all of them inner_collect10"<<endl;

collect16.retainAll(inner_collect16);
try{
collect16.removeAll(inner_collect16);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s7="number"+to_string(600);
collect16.add(s7);
collect16.remove(s7);

cout<<collect16.size()<<endl;

collect16.addAll(inner_collect16);
collect16.clear();

cout<<collect16.size()<<endl;

it16=collect16.iterator();
while(it16.hasNext()){
	cout<<it16.next()<<endl;
}

if(collect16.containsAll(inner_collect16))
	cout<<"collect16 contain all of them inner_collect16 again"<<endl;

if(!collect16.isEmpty())
	cout<<"collect16 is not empty"<<endl;
else
	cout<<"collect16 is empty"<<endl;



cout<<"------------------------------------------------------------------------"<<endl;


Iterator<string,set<string> > it17;

LinkedList<string,set<string> > collect17;

LinkedList<string,set<string> > inner_collect17;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect17.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect17.add(s);
}
string s8="number"+to_string(5);
collect17.add(s8);
s8="number"+to_string(8);
collect17.add(s8);
s8="number"+to_string(13);
collect17.add(s8);

collect17.addAll(inner_collect17);

it17=collect17.iterator();
while(it17.hasNext()){
	cout<<it17.next()<<endl;
}


if(collect17.contains("number30"))
	cout<<"collect17 contain number30"<<endl;

if(collect17.containsAll(inner_collect17))
	cout<<"collect17 contain all of them inner_collect17"<<endl;

collect17.retainAll(inner_collect11);
try{
collect17.removeAll(inner_collect17);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s8="number"+to_string(600);
collect17.add(s8);
collect17.remove(s8);

cout<<collect17.size()<<endl;

collect17.addAll(inner_collect17);
collect17.clear();

cout<<collect17.size()<<endl;

it17=collect17.iterator();
while(it17.hasNext()){
	cout<<it17.next()<<endl;
}

if(collect17.containsAll(inner_collect17))
	cout<<"collect17 contain all of them inner_collect17 again"<<endl;

if(!collect17.isEmpty())
	cout<<"collect17 is not empty"<<endl;
else
	cout<<"collect17 is empty"<<endl;


cout<<"---------------------------------------------------------------------"<<endl;


Iterator<string,list<string> > it18;

LinkedList<string,list<string> > collect18;

LinkedList<string,list<string> > inner_collect18;

for(int i=0;i<20;++i){
	string s="number"+to_string(i);
	inner_collect18.add(s);
}

for(int i=150;i<160;++i){
	string s="number"+to_string(i*2);
	collect18.add(s);
}
string s9="number"+to_string(5);
collect18.add(s9);
s9="number"+to_string(8);
collect18.add(s9);
s9="number"+to_string(13);
collect18.add(s9);

collect18.addAll(inner_collect18);

it18=collect18.iterator();
while(it18.hasNext()){
	cout<<it18.next()<<endl;
}


if(collect18.contains("number30"))
	cout<<"collect18 contain number30"<<endl;

if(collect18.containsAll(inner_collect18))
	cout<<"collect18 contain all of them inner_collect18"<<endl;

collect18.retainAll(inner_collect18);
try{
collect18.removeAll(inner_collect18);
}
catch(int i){
	if (i==-1)
		cout<<"wrong collection type"<<endl;
}
s9="number"+to_string(600);
collect18.add(s9);
collect18.remove(s9);

cout<<collect18.size()<<endl;

collect18.addAll(inner_collect18);
collect18.clear();

cout<<collect18.size()<<endl;

it18=collect18.iterator();
while(it18.hasNext()){
	cout<<it18.next()<<endl;
}

if(collect18.containsAll(inner_collect18))
	cout<<"collect18 contain all of them inner_collect18 again"<<endl;

if(!collect18.isEmpty())
	cout<<"collect18 is not empty"<<endl;
else
	cout<<"collect18 is empty"<<endl;


cout<<"-----------------------------------------------------------------------------"<<endl;


}