#include <iostream>

void whatIsTheType(int T)
{
	std::cout << "integer" << std::endl;
}
void whatIsTheType(float F)
{
	std::cout << "float" << std::endl;
}
void whatIsTheType(double F)
{
	std::cout << "double" << std::endl;
}
void whatIsTheType(void *p)
{
	std::cout << "void ptr" << std::endl;
}

int main()
{
	whatIsTheType(1);
	whatIsTheType(2.0f);
	whatIsTheType(2.0);
	whatIsTheType(nullptr);
}
