#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::map<std::string,std::vector<std::string>>  instructorsPerCourse;

int main()
{

	std::ifstream f("datafile");
	std::string line;
	while (std::getline(f,line)) 
	{
		int comma = line.find(','); 
		std::string name = line.substr(0,comma);
		std::string course = line.substr(comma+1);

		auto itr = instructorsPerCourse.find(course);
		if (itr==instructorsPerCourse.end())
		{
			std::vector<std::string> v;
			v.push_back(name);
			instructorsPerCourse.insert({course,v});
		}
		else
		{
			if (std::find( itr->second.begin(), itr->second.end(),name)==itr->second.end() )
			{
				(*itr).second.push_back(name);
			}
		}
	}
	auto itr = instructorsPerCourse.find("CSE3442");
	if (itr!=instructorsPerCourse.end())
	{
		for (auto &i:itr->second)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
		
	return 0;
}
