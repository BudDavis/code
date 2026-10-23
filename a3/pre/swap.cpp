#include <iostream>
template<typename T> 
void swap(T& A, T& B)
{
	T temp = A;
	A = B;
	B = temp;
}
	
int main()
{
	int A = 3;
	int B = 4;
	std::cout << A << " " << B << std::endl;
	swap(A,B);
	std::cout << A << " " << B << std::endl;
	return 0;
}
