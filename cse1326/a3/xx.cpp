#include <iostream>
#include <vector>
#include "json.hpp"
#include <fstream>

int main()
{
    std::ifstream dFile("allgradedata.json");
    nlohmann::json data = nlohmann::json::parse(dFile);
    nlohmann::json j = data[0][0];
    int year = std::stoi(std::string(j["year"]));
    std::cout << year << std::endl;
    //int j = std::stoi(S);
}
