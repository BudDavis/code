/*
Write a c++ program that demonstrates using a union.  In the union, have a 2 item array of short (uint16t) share memory with a single integer (uint32_t).  Demonstrate that the items share the same information by printing the data out with std::cout and by printing the address of each member of the union.  (you may need to describe how you know this information is correct, as std::cout will print decimal numbers by default). Name this Q5.cpp 
*/
#include <iostream>
int main()
{
	union 
	{
		uint16_t sh[2];
		uint32_t in;
	}u;
	
	u.in = 0x80000001;
	std::cout << u.sh[0] << " " << u.sh[1] << std::endl;
	std::cout << &u.sh[0] << " " << &u.sh[1] << " " << &u.in << std::endl;
	// and for real proof
	std::cout << std::hex << u.sh[0] << " " << u.sh[1] << " " << u.in << std::endl;
}

