#include <stdio.h>
#include <stdlib.h>
#include <iostream>
  
#include <time.h>   

using namespace std;
class IntegerSet {
protected:
   int size;
   int hash(int key) const { return (key * key * key) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
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
   IntegerSetHT(int htsize = 1000) : IntegerSet(htsize) {
		int size = htsize;
		probeDistance = 20;
		table = new int[size];
   
   
   for(int i=0; i<size; i++){
      table[i] = empty_since_start; 
      }// -1 means empty
	}
   
	bool insert(int data) { //Take in data
	    
		int index = hash(data);
		int bucketsProbed = 0;
		
		if(table[index] > 0) { //Runs once an insert
		    collisions++;
		    }
		    while(bucketsProbed++ < probeDistance) {
		       
		
			if ( table[index] < 0 ) //If empty
			{
			table[ index ] = data;
			return true;
			}
		index = (index+1) % size;
		
		    }
    failed_insertion++;
    return false;
		
	}
};


nt main()
{
    IntegerSetHT a;
    srand(time(NULL));
	for(int i = 0; i<500; i++){
	     //srand(time(NULL));
	     int r = rand() % 1000 + 1;
	     printf(" %d \n", r);
	     a.insert(r);
	}
	cout<<"Number of Collisions: " << a.collisions; 
	cout<<"\nNumber of Failed Insertions: " << a.failed_insertion;

	return 0;
}




int main()
{
    MidSquare a;
    srand(time(NULL));
	for(int i = 0; i<500; i++){
	     //srand(time(NULL));
	     int r = rand() % 1000 + 1;
	     printf(" %d \n", r);
	     a.insert(r);
	}
	cout<<"Number of Collisions: " << a.collisions; 
	cout<<"\nNumber of Failed Insertions: " << a.failed_insertion;

	return 0;
}