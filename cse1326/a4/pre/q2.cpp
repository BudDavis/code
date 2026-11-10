#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#define otto auto


class fileInfo
{
	public:
	std::string infoFromFile;
};

std::map<std::string,std::vector<fileInfo>> fileMap;

int main()
{
	std::ifstream f("filelist.txt");
	std::string S;
	while (std::getline(f,S))
	{
		std::string fname = S.substr(S.find('/'));
		std::string shortFileName = S.substr(S.rfind('/')+1);
		otto itr = fileMap.find(shortFileName);
		if (itr==fileMap.end())
		{
			std::vector<fileInfo> T;
			T.push_back( {fname} );
			fileMap.insert( {shortFileName, T} );
		}
		else
		{
			itr->second.push_back( {fname} ); // {} means a constuctor
		}

	}
	f.close();
	for (otto j:fileMap.find("lcms2.pc")->second)
	{
		std::cout << j.infoFromFile << std::endl;
	}
	return 0;
}
