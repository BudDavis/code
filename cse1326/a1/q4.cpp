#include <iostream>
int main()
{
	enum class BEVERAGES {DRIP, LATTE, CAPACINO, AMERICANO, ESPRESSO};
	BEVERAGES b;
	b = BEVERAGES::DRIP;
	switch (b)
	{
		case BEVERAGES::DRIP:std::cout << "drip" << std::endl; break;
		case BEVERAGES::LATTE:std::cout << "drip" << std::endl; break;
		case BEVERAGES::CAPACINO:std::cout << "drip" << std::endl; break;
		case BEVERAGES::AMERICANO:std::cout << "drip" << std::endl; break;
		case BEVERAGES::ESPRESSO:std::cout << "drip" << std::endl; break;

	};
	std::cout << std::endl;
}
