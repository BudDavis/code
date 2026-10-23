#include <iostream>
#include <string>
struct vehicle
{
	static int totalVehicles;
	virtual int horsePower()
	{
		return 0;
	}
	vehicle()
	{
		std::cout << "incrementing" << std::endl;
		totalVehicles++;
	}
	virtual ~vehicle()
	{
		std::cout << "decrementing" << std::endl;
		totalVehicles--;
	}
};

int vehicle::totalVehicles = 0;

struct electric : vehicle
{
	int numMotors;
	float amperage;
	int horsepower()
	{
		return numMotors*amperage;
	}
	electric(int numMotors_,float amperage_) : numMotors(numMotors_),amperage(amperage_) {};

	~electric()
	{
	}
};

struct petroleum : vehicle
{
	int engineDisplacement;
	int horsepower()
	{
		return engineDisplacement * 1;
	}

	petroleum(int ed):engineDisplacement(ed) 
	{
	}

	~petroleum()
	{
	}
};

int main()
{
	electric e(2,20);
	petroleum *p = new petroleum(350);
	std::cout << e.totalVehicles << std::endl;
	std::cout << p->horsePower() << std::endl;
	std::cout << e.horsePower() << std::endl;
	delete p;
	std::cout << e.totalVehicles << std::endl;
	return 0;
}
