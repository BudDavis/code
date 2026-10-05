#include <iostream>
struct A { virtual void f() { std::cout << "A"; }};
struct B : A { void f() override { std::cout << "B"; }};
void f(A& a) {a.f();}
void g(A* a) {a->f();}
void h(A a) {a.f();}
int main()
{
	B b;
	f(b);
	g(&b);
	h(b);
	std::cout << std::endl;
}

