#include "Header.h"


int main()
{
	myList l;
	myList l1;


	l.push(3);
	l.push(1);
	l.push(6);
	std::cout << "List to copy\n";
	l.print();

	l1 = myList(l);
	std::cout << "Copied list\n";
	l1.print();
	
	myList b;

	myList a ;
	a = myList(l);
	std::cout << "a list\n";
	a.print();
	b.push(4);
	b.push(1);
	std::cout << "b list\n";
	b.print();
	

	/*a = b;
	std::cout << "a= b list\n";
	a.print();*/
	
	std::cout << "a ?= b || ";
	if (a == b)
		std::cout << "a == b\n";
	else
		std::cout << "a != b\n";

	a.swap(b);
	std::cout << "\nb list\n";
	b.print();
	std::cout << "a list\n";
	a.print();

	swap(a,b);
	std::cout << "\nb list\n";
	b.print();
	std::cout << "a list\n";
	a.print();
	return 0;
}