// ============================================================================
// Name: Bracket-matching example of stack usage               File: stackT.hpp
// ============================================================================
#pragma once
#include "tools.hpp"
//------------------------------------ Type definition for Stack of base type BT 
template <class BT> 
class Stack{
private:
	//-------------------------------- Type definition for dependent Cell class. 
	class Cell { 
	public:
		BT data;
		Cell* next;
		Cell( BT value, Cell* next ){
			data = value;
			this->next = next;
		}
		~Cell(){}
	};
    //--------------------------------------------------------------------------  
  	Cell* head;									  // Point at stack's data list. 
	
public:
    Stack(){  head = NULL; }
    ~Stack();
    //--------------------------------------------// Prototypes  
    void print  ( ostream& out );
    BT   pop    ( );						  	  // Pop top item and return it.												  
	// -------------------------------------------// Inline functions  
    BT   peek   ( ){ return head->data; }	      // Return top item; don't pop.
    void push   ( BT d ){ head = new Cell( d, head ); }  // Put data onto stack.     
    bool empty  ( ){ return head == NULL; } 
};

//------------------------------------------------------------------------------
template <class BT> 
void Stack<BT>::
print( ostream& out )  {
    Cell* scan = head;
    while ( scan != NULL ) {
        out << scan->data <<"  ";
        scan = scan->next;
    }
	out << endl;
}

template <class BT> 
inline ostream& operator<< ( ostream& out, Stack<BT>& st ){ 
	st.print( out );
	return out;
}

//----------------------------------------------------- Delete all dynamic data. 
template <class BT> 
Stack<BT>::~Stack() { 
	cout <<"Deleting cells on stack.\n"; 
    Cell* scan;
    while (head != NULL) {							// Same as while (scan) ...
        scan = head;
        head = head->next;
        delete scan;
    }
}

//----------------------------------------------------- Pop and return top item. 
template <class BT> 
BT Stack<BT>::pop() {
	Cell* popped = head;
	head = head->next;
    BT temp = popped->data;
	delete popped;
	return temp;
}

