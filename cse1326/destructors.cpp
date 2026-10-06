#include <iostream>
#include <string>
#include <array>
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
		std::cout << "doctor destructor" << name << std::endl;
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
			std::cout << "animal destructor " << name << std::endl;
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
			std::cout << "dog destructor" << name << std::endl;
		}
	};
	std::cout << "start of main" << std::endl;
	{
		doctor theVet("xxxxxxxx ");
	}
	std::cout << "after the scope" << std::endl;
	doctor theVet("dr. smith");
	dog houseDog("rover",&theVet);
	dog yardDog("hunter",&theVet);

	std::array<dog,3> dogs;


	dogs[0] = houseDog;
	dogs[1] = houseDog;
	dogs[2] = yardDog;
// fix me for wednesday
	for (auto &d:dogs)
	{
		std::cout << d.name << std::endl;
	}

	std::cout << "end of main" << std::endl;
}
