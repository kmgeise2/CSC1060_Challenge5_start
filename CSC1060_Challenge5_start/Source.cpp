// CSC1060_Challenge5_start

#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() 
{
	cout << "Create an array" << endl;
	DynamicArray<double> list;

	cout << "Push elements into the array" << endl;
	list.push(23.4);
	list.push(45.6);

	cout << "Print the array: ";
	list.print();

	return 0;
}