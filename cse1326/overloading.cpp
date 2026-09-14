#include <iostream>
void print(int a)
{
	std::cout << "an integer " << a << std::endl;
}
#if 0
void print(float& a)
{
	std::cout << "a float " << a << std::endl;
}
#endif

void print(float a)
{
	std::cout << "a float " << a << std::endl;
}

void print(double a) /*= delete ; */
{
	std::cout << "a double " << a << std::endl;
}

int main()
{
	int i = 1;
	float f = 1.1;
	double d = 1.001;
	print (i);
	print (f);
	print (d);
}
