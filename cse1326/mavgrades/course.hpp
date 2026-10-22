#pragma once

#include <string>
#include "json.hpp"


class course
{
	std::string courseSubject;
	std::string courseNumber;
	public:
	const std::string shortName();
	course(nlohmann::json j);
};
