#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "course.hpp"
#include "json.hpp"

// This program will read the mavgrades data file, and
// perform various analysis of the data.

const std::string fileName = "allgradedata.json";

// when your only tool is a hammer, every problem needs a nail.
// (that is why I am using a vector....)
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
		for (auto i : data) // by semester
		{
			for (auto j : i) // by course
			{
				// ignore graduate classes
				if (j["career"]=="UGRD")
				{
					count++;
					// std::cout << j << std::endl;
					// will want to do something with this eventually.
					courseList.push_back(course(j));
				}
			}
		}
		std::cout << "the data file is loaded into memory,C++ style" << std::endl;
	}
	// the json is now all out of scope.  perhaps the memory will be given back for future use.
        std::string searchSubject = "CSE";
	std::string searchYear = "2025";
	std::string searchSemester = "Fall";	
	auto if_subject_and_year_and_semester = [&](course &C)
	{
		return (C.courseSubject == searchSubject) && (C.year == searchYear) && (C.semester == searchSemester);
	};
	auto count = std::count_if(courseList.begin(),courseList.end(),if_subject_and_year_and_semester);
	std::cout << "Fall 2025 " << count << std::endl;
	searchSemester = "Spring";
	auto count2 = std::count_if(courseList.begin(),courseList.end(),if_subject_and_year_and_semester);
	std::cout << "Spring 2025 " << count2 << std::endl;
	return 0;
}

