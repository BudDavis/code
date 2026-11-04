#include <fstream>
#include <iostream>
#include <string>
int main()
{
	std::ifstream f;
	std::string S;
	f.open("someFile",std::ios_base::in);
	while (std::getline(f,S))
	{
		std::cout << S << std::endl;
	}
	f.close();
	return 0;
}
