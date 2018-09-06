#include <stdio.h>

class Item {
public:
  const char * str;
  Item(const char *as = "") 
  { 
    str = as; 
  }
};


class List {
private:

// ListNode represents each 
// node of the list
  class ListNode {
  private:
    Item item; // data in the list
    ListNode *next;	
  public:
    ListNode(Item a) 
    { 
      item = a; 
      next=NULL; // automatically serves as a list tail
    }
    ListNode* getNext() 
    { 
      return next; 
    }
    void setNext(ListNode *n) 
    { 
      next = n; 
    }
    Item getItem() 
    { 
      return item; 
    }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;


  
public:
    void push_back(string str)
    {
        Item str2(str);
        append(str);
    }
    
    Item get(int n)
    {
        int i = 0;
        ListNode *temp = head;
        while(i<n)
        {
          temp = temp -> next;  //Load item and jump to next node
          i++;
        }
        return temp; //Return the Item that temp is pointing at
    }
    int length(){ //Find length of list
        int test = 1;
        ListNode *point = head;
        if (point = NULL) {return 0;}
        while(point != NULL) { //Until tail value equals NULL
            test++; 
            point = point -> getNext(); 
        }
        return test;
    }
    void remove_front() { //Remove first item from list
        Item header = getItem();
        remove(Item &header);
    }
    
    List::~List() //Destructor deallocates memory used in list
    {
        while(!empty())
        {
            Item t;
            remove(t);
        }
    }
    
  List();
  void append(Item a);    
  bool remove(Item &a);    
  bool empty(); 
};

List::List()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void List::append(Item a)
{
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}

bool List::remove(Item &copy) 
{
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element 
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool List::empty()
{
  return head==NULL;
}
