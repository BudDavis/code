#include <iostream>
#include <string>

struct doctor
{
	std::string name;
	doctor(std::string n)
	{
		std::cout << "doctor constructor" << std::endl;
		name = n;
	}

	doctor(doctor& other)
	{
	}

	~doctor()
	{
		std::cout << "doctor destructor" << std::endl;
	}
};
int main()
{
	struct animal
	{
		std::string name;
		doctor *vet = nullptr;
		animal (std::string n, doctor* d)
		{
			std::cout << "animal constructor " << std::endl;
			name = n;
			vet = d;
		}
		~animal()
		{
			std::cout << "animal destructor " << std::endl;
		}
	};

	struct dog : animal
	{
		dog(std::string n,doctor *v) : animal(n,v)
		{
			std::cout << "dog constructor" << std::endl;
		}
		~dog()
		{
			std::cout << "dog destructor" << std::endl;
		}
	};
	std::cout << "start of main" << std::endl;
	doctor theVet("dr. smith");
	dog houseDog("rover",&theVet);
	dog yardDog("hunter",&theVet);
	std::cout << "end of main" << std::endl;
}
