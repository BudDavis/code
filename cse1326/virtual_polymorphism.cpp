#include <iostream>
struct A { virtual void f() { std::cout << "A"; } };
struct B : A { void f() override { std::cout << "B"; } };
// delete override and see what happens...
void g(A& a) {a.f(); } // accepts A or B
int main()
{
	A a;
	B b;
	g(a);
	g(b);
	std::cout << std::endl;
}
