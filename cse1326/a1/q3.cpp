#include <iostream>
#include <bits/stdc++.h>
/*
If you #include <bits/stdc++.h> in your program, a function called rand() is available that returns a random number.  Using range based for loops and std::array, fill an array with 10 elements with random numbers.  Calculate the min, max, and average value of the array.  Use <cstdint.h> for the types used in this program.  Name this program Q3.cpp .
*/
int main()
{
	std::array<uint32_t,10> a;
	for ( auto &element:a )
		element = rand();
	uint64_t sum = 0;
	uint32_t min = 99999;
	uint32_t max = 0;
	for ( auto element:a )
	{
		sum=sum+element;
		if (element < min) min=element;
		if (element > max) max=element;
	}
	std::cout << "avg " << sum/10.0 << std::endl;
	std::cout << "sum " << sum << std::endl;
	std::cout << "min " << min << std::endl;
	std::cout << "max " << max << std::endl;
	for (auto e:a)
	{
		std::cout << e << " ";
	}
	for (auto i:a)
	{
		std::cout << i << "  " ;
	}
	std::cout << std::endl;
	return 0;
}
