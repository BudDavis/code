#include <iostream>
struct S
{
	int i;
	int j;
};
void print(S& s)
{
	std::cout << s.i << " " << s.j << std::endl;
}
int main()
{
	S a;
	a.i = 1;
	a.j = 2;
	print(a);

	S& b = a;
	print(b);

	b.i = 3;
	b.j = 4;
	print(b);
	// did it change a?
	print(a);
}
