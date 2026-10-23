#include <iostream>
#include <vector>

int main()
{
	std::vector<int> V;
	V.push_back(1); V.push_back(10); V.push_back(5);
	std::cout << "the vector is [0] = " << V[0] << " [1]  " << V[1] << " [2] = " << V[2] << std::endl;
	// declare it the old way
	std::vector<int>::iterator i;
	// and the new way
	auto j = V.begin();
	std::cout << V[0] << std::endl;
	// read
	std::cout << *j << std::endl;
	// write
	*j = 123;
	std::cout << "changed the begin to 123 " << std::endl;
	std::cout << "the vector is [0] = " << V[0] << " [1]  " << V[1] << " [2] = " << V[2] << std::endl;
	// increment
	std::cout << "incrementing " << std::endl;
	std::cout << *j++ << "   " << *j << std::endl;
	// decrement
	std::cout << "decrementing " << std::endl;
	std::cout << *j-- << "   " << *j << std::endl;
	// comparison
	auto k = V.end();
	auto l = k-1;
	std::cout << "comparison" << std::endl;
	std::cout << (k<l) << std::endl;
	// random access
	k = V.begin();
	std::cout << k[1] << " which should be 10 " << std::endl;
}
