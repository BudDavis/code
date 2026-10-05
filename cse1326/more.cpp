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
		animal (animal& other)
		{
			std::cout << "animal copy constructor" << std::endl;
			name = other.name;
			vet = other.vet;
		}
		~animal()
		{
			std::cout << "animal destructor " << std::endl;
		}
	};

	struct dog : animal
	{
		int numberOfPaws = 4;
		dog(std::string n,doctor *v) : animal(n,v)
		{
			std::cout << "dog constructor " << std::endl;
		}
		~dog()
		{
			std::cout << "dog destructor " << std::endl;
		}
		dog(dog& other):animal(other.name,other.vet)
		{
			std::cout << "dog copy constructor " << std::endl;
		}
		void print()
		{
			std::cout << "the dogs name is " << name << std::endl;
		}
	};
	std::cout << "----- start of main" << std::endl;
	doctor theVet("dr. smith");
	dog houseDog("rover",&theVet);
	dog yardDog("hunter",&theVet);
	animal a("",nullptr);
	std::cout << "before making the animal" << std::endl;
	//animal a = houseDog;
        a = static_cast<animal>(houseDog);
	std::cout << "after making the animal" << std::endl;

        dog dogs[]={ {dog("killer",&theVet)},{dog("fluffy",&theVet)} };
	std::cout << "----- end of main" << std::endl;
}
