#include "course.hpp"
#include "json.hpp"
course::course(nlohmann::json d)
{
	courseSubject = d["subject_id"];
	courseNumber = d["course_number"];
	courseTitle = d["course_title"];
	sectionNumber = d["section_number"];
	year = d["year"];
	semester = d["semester"];
}

