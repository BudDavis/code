#include <fstream>
int main()
{
	std::ofstream f;
	f.open("someFile",std::ios_base::out|std::ios_base::trunc);
	f << "first line " << std::endl;
	f.close();
	return 0;
}
