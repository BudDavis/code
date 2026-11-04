#pragma once

#include <string>
#include "json.hpp"


class course
{
	public:
	std::string courseSubject;
	std::string courseNumber;
	std::string courseTitle;
	std::string sectionNumber;
	std::string year;
	std::string semester;
	public:
	const std::string shortName();
	course(nlohmann::json j);
};
