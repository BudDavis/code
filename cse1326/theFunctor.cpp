#include <iostream>
float f=0;
struct machine
{
	void operator () ()
	{
		std::cout << "this is a function " <<  std::endl;
	}
};

int main()
{
	machine M;
	M();
	// add argument
	// add a global
	// demonstrate
}
