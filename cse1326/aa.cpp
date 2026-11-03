#include <algorithm>
#include <iostream>
#include <vector>

struct someClass
{
	someClass()
	{
	};
	bool operator <  (someClass B)
	{
		return true;
	}
};
std::vector<someClass> V;

int main()
{
	//V.push_back(someClass());
	//V.push_back(someClass());
	//V.push_back(someClass());
	sort(V.begin(),V.end());
#if 0
	for (auto i:V)
	{
		std::cout << i << std::endl;
	}
#endif
	return 0;

}

