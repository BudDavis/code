#include <iostream>
#include <string>

enum class animal_kind {DOG,CAT};

struct animal
{
	animal_kind kind;
};

std::string animalType(animal &a)
{
	switch (a.kind)
	{

		DOG : return "DOG"; 
		CAT : return "CAT";
	}
	return "error";
}

int main()
{
	animal firstAnimal;
	firstAnimal.kind = animal_kind::DOG;

	std::cout << animalType(firstAnimal) << std::endl;
}
