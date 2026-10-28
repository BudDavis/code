#include <vector>
#include <iostream>

int main()
{
	std::vector<int> V = { 100,90,80,70,60,50,40,30,20,10,-1 };

        V.push_back(35);
	std::cout << *(V.begin()) << " " << *(V.begin() + 1)  << std::endl;

	V.erase(V.begin());
	V.erase(V.begin(),V.end());
        for (auto i:V)
	{
	       std::cout << i << " ";
	}
	std::cout << std::endl;
}
