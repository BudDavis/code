#include <iostream>

template <class C>
class counted
{
	public:
	C c;
	int count;
	void increment()
	{
		count++;
	}
};

class employee
{
	std::string id;
	std::string name;
};

class product
{
	int partNumber;
};


int main()
{
	counted<employee> countedEmployee;
	counted<product> countedProduct;
	countedEmployee.increment();
	countedEmployee.increment();
	countedProduct.increment();

	std::cout << countedEmployee.count << std::endl;
	std::cout << countedProduct.count << std::endl;
	return 0;
}
