// this is contained in one file for convenience
#include <iostream>
#include <string>
#include <array>

#include "limits.h"


struct animal
{
	int count;
	std::string name;
	public: 
		virtual std::string species()
		{
			return "unknown";
		}
		animal()
		{
			count = 1;
			std::cout << "i am in the animal constructor" << std::endl;
		}

};

struct dog : animal
{
	public: 
		std::string species()
		{
			return "dog";
		}
		dog()
		{
			name = "not assigned a name";
			std::cout << count << std::endl;
			std::cout << "i am in the dog constructor " << std::endl;
		}
};

struct cat : animal
{
	public:
		bool licensed;
		std::string species()
		{
			return "cat";
		}
		cat()
		{
			name = "not assigned a cat name";
			std::cout << count << std::endl;
			std::cout << "i am in the cat constructor " << std::endl;
		}
		cat (std::string n, bool licensed = true)
		{
			name = n;
			std::cout << count << std::endl;
			std::cout << "the cat is licensed = " << licensed << std::endl;
			std::cout << "i am in the cat constructor and its name is " << name << std::endl;
		}
};

int main()
{
	std::cout << "this is the main" << std::endl;
	std::array<animal*,3> pets = {nullptr};
	pets.at(0) = new cat("fluffy");
	pets.at(1) = new cat("tiger",false);
	pets.at(2) = new dog();
        animal A[4];
	A[2] = dog();
	A[1] = cat("floofy",true);
	//dog* D =  pets.at[0];
	for ( auto e : pets )
	{
		std::cout << "the animal is a " << e->species() << " name is " << e->name << std::endl;
	}
}




