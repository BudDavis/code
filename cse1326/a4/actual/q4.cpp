#include <iostream>
#include <vector>

int main()
{
	std::vector<std::pair<int,std::string>> V;
	V.push_back( {123,"hello"} );
	V.push_back( {456,"this"} );
	V.push_back( {789,"is easy"} );
	auto itr = V.begin();
	while (itr!=V.end())
	{
		std::cout << itr->first << " " << itr->second << std::endl;
		itr++;
	}
		

	return 0;
}
