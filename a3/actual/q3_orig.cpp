#include <iostream>
#include <string>
struct A
{
	std::string *Id;
	A(std::string S)
	{
// put code here
	}
// and here
};

int main()
{
	A a("hello");
	A b = a;
	std::cout << *(b.Id)  << "  " << *a.Id << std::endl;
	std::cout << &(b.Id)  << "  " << &(*a.Id) << std::endl;
}
