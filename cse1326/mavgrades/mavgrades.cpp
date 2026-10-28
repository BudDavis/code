#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "json.hpp"

// This program will read the mavgrades data file, and
// perform various analysis of the data.
#if 0
 "subject_id": "SPAN",
      "course_number": "5303",
      "course_title": "APPLIED SPANISH LINGUISTICS",
      "section_number": "001",
#endif
struct courses
{
	std::string course_number;
	std::string course_title;
	std::string section_number;
	courses(nlohmann::json d)
	{
		course_number = d["course_number"];
		course_title = d["course_title"];
		section_number = d["section_number"];
	}
};

const std::string fileName = "allgradedata.json";

std::vector<courses> courseList;

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
				// will want to do something with this eventually.
				courseList.push_back(courses(j));
			}
		}
		std::cout << "the final count is " << count << std::endl;
		std::cout << "in the vector " << courseList.size() << std::endl;
	}
	return 0;
}

