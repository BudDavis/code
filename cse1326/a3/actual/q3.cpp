#include <iostream>
#include <string>
struct A
{
	std::string *Id;
	A(std::string S)
	{
		Id = new std::string(S);
	}
	~A()
	{
		delete Id;
	}
	A(const A &other)
	{
		Id = new std::string(*(other.Id));
	}
};

int main()
{
	A a("hello");
	A b = a;
	std::cout << *(b.Id)  << "  " << *a.Id << std::endl;
	std::cout << &(b.Id)  << "  " << &(*a.Id) << std::endl;
}
