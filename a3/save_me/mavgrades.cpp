#include <iostream>
#include "json.hpp"

int main()
{

	// Using initializer lists
	nlohmann::json example = {
  			{"happy", true},
  			{"pi", 3.141},
		   };
	std::cout << example["happy"] << std::endl;
  nlohmann::json  example2 = {
	  {"subject_id", "CSE"},
          {"course_number", "3310"},
	  {"course_title", "FUNDAMENTALS OF SOFTWARE ENGINEERING"},
    	  {"section_number", "4"}};




#if 0
    "grades": {
      "A": "19",
      "B": "38",
      "C": "7",
      "D": "0",
      "F": "0",
      "I": "0",
      "P": "0",
      "Q": "1",
      "W": "0",
      "Z": "0",
      "R": "0"
    },
    "grades_count": "65",
    "year": "2026",
    "semester": "Spring",
    "career": "UGRD",
    "instructor1": "Jimmie Davis",
    "instructor2": "",
    "instructor3": "",
    "instructor4": "",
    "instructor5": "",
    "course_gpa": 3.19,
    "drop_percent": 1.54
 };
#endif
}; // end of the main
 
