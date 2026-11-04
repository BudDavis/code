// exception2.cpp
#include <exception>
#include <iostream>
#include <string>

struct someClass
{
	~someClass()
	{
		std::cout << "destructing " << std::endl;
	}
};

int main()
{
	int i;
	std::string S;
	bool valid = false;
	while(!valid)
	{
	        std::cin >> S;
		try
		{
			someClass SC;
			i = std::stoi(S);  // part of <string>
			valid = true;
		}
		//catch (const std::exception &e)
		//{
		//	std::cout << "Exception " << e.what() << " " << typeid(e).name() << std::endl;
		//}
		catch (const std::invalid_argument &e)
		{
			std::cout << "specific exception" << std::endl;
		}
		catch (...)
		{
			std::cout << "unknown exception" << std::endl;
		}
	}
	std::cout << "as an integer, it is " << i << std::endl;
	return 0;
}
