#include "Header.h"


int main()
{
	myList l;
	myList l1;


	l.push(3);
	l.push(1);
	l.push(6);
	l.print();

	myList(l).print();
	
	l1 = myList(l);
	return 0;
}