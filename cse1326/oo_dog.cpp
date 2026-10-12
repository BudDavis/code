#include <iostream>
#include <string>
class animal
{
	public:
	virtual std::string kind() = 0; 
};

class dog : public animal
{
	public:
	std::string kind()
	{
		return "dog";
	}
};

class cat : public animal
{
	public:
	std::string kind()
	{
		return "cat";
	}
};

int main()
{
	animal*  firstAnimal = new cat();
	std::cout << firstAnimal->kind() << std::endl;
}
