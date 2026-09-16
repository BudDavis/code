#include <iostream>
struct f
{
	int operator() ()
	{
	        int a;
       		int b;	       
		std::cout << "in () " << std::endl;
		return a*b;
	}
}g;

int some_func( int (*ff)() )
{
	std::cout << "in some_func " << std::endl;
	ff();
	return 0;
}

int main()
{
	//std::cout << g() << std::endl;
	std::cout << some_func(f()) << std::endl;

	// you cannot do this in C++ without a template !!!!!!!
	//
}
