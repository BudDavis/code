#include "course.hpp"


course::course(nlohmann::json j)
{
	courseSubject = j["subject_id"];
	courseNumber = j["course_number"];
}

const std::string course::shortName()
{
	return courseSubject + courseNumber;
}


