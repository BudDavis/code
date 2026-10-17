#include <iostream>

#define ADD(A,B)    (A+B)
float add (float a, float b)
{
	return a+b;
}

int add (float a, float b)
{
	return a+b;
}

int main()
{
//	auto x = add(1.0f,2.0f);
//	auto y = add(1,2);
	std::cout << ADD(1.0f,3.0f) << std::endl;
//	std::cout << "x = " << x << " y = " << y << std::endl;
}
