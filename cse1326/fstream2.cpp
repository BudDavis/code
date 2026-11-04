#include <fstream>
#include <iostream>
int main()
{
	std::ifstream f;
	f.open("someFile",std::ios_base::in);
	std::string S;
        f >> S; // reads the first word
	std::cout << S << std::endl;
	f.close();
	return 0;
}
