#include <iostream>
#include <string>
#include <map>
class dog
{
	public:
	int license;  // this needs to be unique for each dog.
	std::string name;
	dog(int l,std::string n):license(l),name(n)
	{
	}
};

std::map<int,dog> dogs;

int main()
{
	// add some dogs
	dog d(123,"killer");
	dogs.insert(std::pair(123,d));
	dogs.insert(std::pair(345,dog(345,"sleepy")));
	// alternate syntax
	dogs.insert({678,dog(678,"blue")});
	// and even shorter
	dogs.insert({9,{9,"red"}});

	// c++17
	for (const auto& [k, v] : dogs) 
	{
        	std::cout << k << " " << v.name << std::endl;
	}
	//for (auto p:dogs)
	//{
//		std::cout << p.first << " " << p.second << std::endl;
//	}
	//get a pair, use .first and .second
	//
	//
	// use an iterator

	return 0;
}
