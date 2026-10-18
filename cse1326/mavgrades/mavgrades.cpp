#include <iostream>
#include <fstream>
#include <string>

#include "json.hpp"

// This program will read the mavgrades data file, and
// perform various analysis of the data.
//

const std::string fileName = "allgradedata.json";

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
		std::cout << "data size is " << data.size() << std::endl;
		for (auto i : data) // by semester
		{
			std::cout << "i size is " << i.size() << std::endl;
			for (auto j : i) // by course
			{
				count++;
				std::cout << j << std::endl;
			}
		}
		std::cout << "the final count is " << count << std::endl;
	}
	return 0;
}

