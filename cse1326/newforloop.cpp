#include <array>
#include <iostream>

std::array<int,10> X;

int main(int argc, char* argv[])
{
	for ( auto i:X )
		std::cout << i << std::endl;
}


