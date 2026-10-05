#include <iostream>
struct A 
{
	virtual void f() { std::cout << "A" ; }
};
struct B : A 
{
	void f() override {std::cout << "B" ; }
};
A* get_object(bool selectA)
{
	return (selectA) ? new A() : new B();
}
int main()
{
	get_object(true)->f();
	get_object(false)->f();
	std::cout << std::endl;
}
