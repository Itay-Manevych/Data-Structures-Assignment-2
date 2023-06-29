#include "CircularLinkedList.h"
 
int main()
{
	CircularLinkedList<int> li;
	cout << "The circular linked list is: " << "\n";
	cout << "\n";
	li.PrintList();
	cout << "\n";
	cout << "The length of the list is: " << li.GetLength(&li) << "\n";
	return 0; 
}