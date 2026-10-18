#include <iostream>
#include <string>

template <typename T>
T largest(T a,T b,T c)
{
	if ( (a>b) && (a>c) )
		return a;
	if ( (b>a) && (b>c) )
		return b;
	if ( (c>a) && (c>b) )
		return c;
	else
		return a;   // should never get here, if so who cares...
}

int main()
{
	std::cout << largest(std::string("A"),std::string("B"),std::string("C")) << std::endl;
	std::string z="a";
	std::string y="b";
	std::string x="c";
	std::cout << largest(z,y,x) << std::endl;
	std::cout << largest(0,2,34) << std::endl;
}
