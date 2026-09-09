#include <iostream>

int main(int argc,char *argv[])
{
	auto l = [](int a,int b)
	{
		return a*b;
	};
	auto fptr = l;
	std::cout << l(1,2) << std::endl;
	std::cout << fptr(2,2) << std::endl;
}
