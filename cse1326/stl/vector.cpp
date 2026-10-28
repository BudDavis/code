#include <iostream>
#include <vector>
#include <string>

struct room
{
	std::string number;
	bool lights;
	room(std::string n,bool l)
	{
		number = n;
		lights = l;
	}
};

//std::vector<room> nedermann =  {push_back( room ("202",true))};


//nedermann.push_back( room{"202",true} );

int main()
{
        std::vector<room> nedermann;
        nedermann.push_back( room ("202",true));
        nedermann.push_back( room ("229",true));
        nedermann.push_back( room ("212",true));
	std::cout << nedermann.size() << std::endl;
	// for loop
	std::cout << "the for loop" << std::endl;
	for ( auto i : nedermann)
	{
		std::cout << i.number << std::endl;
	}
	std::cout << "the while loop " << std::endl;
	auto j=nedermann.begin();
	while (j!= nedermann.end())
	{
		std::cout << (j++)->number << std::endl;
	}
}
