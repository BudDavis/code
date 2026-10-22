#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "json.hpp"

#include "course.hpp"

// This program will read the mavgrades data file, and
// perform various analysis of the data.
//

const std::string fileName = "allgradedata.json";

std::vector<course> courseList;

int main () 
{
	std::ifstream dFile(fileName); 
	// todo .. deal with exceptions 
	{
	       	nlohmann::json data = nlohmann::json::parse(dFile); 
		// at this point, everything is in memory.  it took a long time, but we got it all.
		// in memory as a json object (of objects), so it is easy to deal with, but uses a lot 
		// of memory and cpu.
		int count=0;
		// std::cout << "data size is " << data.size() << std::endl;
		for (auto i : data) // by semester
		{
			//std::cout << "i size is " << i.size() << std::endl;
			for (auto j : i) // by course
			{
				count++;
				//std::cout << j << std::endl;
				courseList.push_back(course(j));
			}
		}
		std::cout << "the final count is " << count << std::endl;
	}
	// after this point, we no longer will deal with json representation
	std::cout << "in the vector " << courseList.size() << std::endl;
	for (auto i:courseList)
	{
		std::cout << i.shortName() << std::endl;
	}
	return 0;
}

