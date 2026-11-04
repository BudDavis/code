// exception1.cpp
#include <exception>
#include <iostream>
#include <string>

int main()
{
	std::string S = "umm, this is a wendys..";
	int i = std::stoi(S);
	std::cout << "as an integer, it is " << i << std::endl;
	return 0;
}
