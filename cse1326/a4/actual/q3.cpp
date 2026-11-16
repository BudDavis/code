#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

enum class breed {CAT,DOG,PIG}; 
struct pet
{
	breed kindOfPet;
	std::string name;
};

std::vector<pet> petList = { {breed::DOG,"killer"}, {breed::PIG,"snowball"}, {breed::CAT,"mouser"} };

int main()
{
	std::sort(petList.begin(),petList.end(),[](pet &A, pet &B){
		return A.kindOfPet < B.kindOfPet;});

	for (auto i:petList)
	{
		std::cout << i.name << std::endl;
	}
	return 0;
}
