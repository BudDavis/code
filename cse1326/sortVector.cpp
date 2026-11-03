#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> V;

void print(std::vector<int> V)
{
	for (auto i:V)
	{
		std::cout << i << std::endl;
	}
}

int main ()
{
	V.push_back(10);
	V.push_back(1);
	V.push_back(5);
	V.push_back(5);
	V.push_back(5);
        print(V);

	std::cout << "number of elements = to 5 is " << std::count(V.begin(),V.end(),5) << std::endl;

	std::sort(V.begin(),V.end()-1);
	std::cout << "after sort " << std::endl;
	print(V);
	return 0;
}
