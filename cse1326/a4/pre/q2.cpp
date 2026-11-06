#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

template <typename func>
std::vector<std::vector<int>::iterator> sub_set ( std::vector<int> &I,func F)
{
	std::vector<std::vector<int>::iterator> retval;
	auto itr = I.begin();
	while (itr!=I.end())
	{
		if (F(*itr))
		{
			retval.push_back(itr);
		}
		itr++;
	}
	return retval;
}
int main()
{
	std::vector<int> V = {9,8,7,6,5,4,3,2,1,0,123,456};
	auto is_odd = [](int &A) { return (A%2)==0; };
	auto U = sub_set(V,is_odd);
	for (auto &j:U)
	{
		std::cout << *j << std::endl;
	}
	return 0;
}  
