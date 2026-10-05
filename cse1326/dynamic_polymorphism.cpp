#include <iostream>
struct A 
{
	void f() {std::cout << "A"; }
};
struct B : A
{
	void f() {std::cout << "B"; }
};
void g(A& a) { a.f(); }
//void h(B& b) { b.f(); }
int main()
{
	A a;
	B b;
	g(a);
	g(b);
	std::cout << std::endl;
	// lets try this
	//h(a);
	//h(b);
	//std::cout << std::endl;
}
