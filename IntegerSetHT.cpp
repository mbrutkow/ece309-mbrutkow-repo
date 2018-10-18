#include <stdio.h>
#include <stdlib.h>
#include <iostream>
  
#include <time.h>   

using namespace std;


class IntegerSet {
protected:
   int size = 100;
   int hash(int key) const { return (key) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   IntegerSet():size(){}
   virtual bool insert(int) = 0;
   
  
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
 const int empty_since_start = -2;
  const int empty_after_removal = -1;
  //int failed_insertion = 0;
  //int hash(int key) const { return (key * 997) % size; }
public:
int failed_insertion = 0;
int collisions = 0;
   IntegerSetHT(int htsize = 100) : IntegerSet(htsize) {
		int size = htsize;
		probeDistance = 20;
		table = new int[size];
   
   
   for(int i=0; i<size; i++){
      table[i] = empty_since_start; 
      }// -1 means empty
	}
   //IntegerSetHT(): IntegerSet() {
	   //int size = htsize;
	 //  table = new int[size];
   //}
   
   bool insert(int data) { //Take in data
	    
		int index = hash(data);
		int bucketsProbed = 0;
		
		if(table[index] > 0) { //Runs once an insert
		    
		    }
		    while(bucketsProbed++ < probeDistance) {
		       
		
			if ( table[index] < 0 ) //If empty
			{
			table[ index ] = data;
			return true;
			}
		index = (index+1) % size;
		
		    }
    
    return false;
		
	}
   
   
   class iterator {
       int *point;
       int length;
       public:
	   iterator(int *array, int size = 3){ 
		   point = array;
		   length = size;
	   }
	   
	   iterator(){ 
		 //  point = array;
		   length = 3;
	   }
	   int i = 0;
	   bool end(){
		   
		   if(i >= length) {
			   return true;
		   }
		   
		   return false;
	   }
	   int getInt() {
		  
		  while(*point < 0) {
			
			increment();
	   }
	   return *point;
	   }
	   void increment(){
	       point++;
	       i++;
	   }
   };
	 
   iterator begin() {
	   int *point1;
	point1 = table;
	  iterator a(point1, size);
	  
	   return a; //Do I need a pointer to a object
	   
   }
};



int main(){
	IntegerSetHT set;
	set.insert(5);
	set.insert(99);
	set.insert(0);
	
	IntegerSetHT::iterator sit = set.begin();
	while(!sit.end())
	{
		printf("%d ", sit.getInt()); //Create way to ignore -1 or -2 
		sit.increment();
	}

	
	
	
}