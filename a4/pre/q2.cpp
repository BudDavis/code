#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

class fileInfo
{
	public:
	std::string infoFromFile;
};

std::map<std::string,std::vector<fileInfo*>> fileMap;

int main()
{
	std::ifstream f("filelist.txt");
	std::string S;
	while (std::getline(f,S))
	{
		// no matter what, we will need a fileInfo to put
		// in the map
		fileInfo *fi = new fileInfo{S};
		// find the key and look in the map
		std::string fname = S.substr(S.rfind('/')+1);
		auto itr = fileMap.find(fname);
                if(itr == fileMap.end())
		{
			std::vector<fileInfo*> V;
			V.push_back(fi);
			fileMap[fname] = V;
		}
		else
		{
			itr->second.push_back(fi);
		}
	}
	f.close();
	// search for something specific
	std::cout << "items in map = " << fileMap.size() << std::endl;
	for (auto j:fileMap.find("lcms2.pc")->second)
		
	{
		std::cout << j->infoFromFile << std::endl;
	}
	// clean up
	auto itr=fileMap.begin();
	while (itr!=fileMap.end())
	{
		// there will always be at least one item in the vector
		auto V = itr->second;
		for (auto &U:V)
		{
			delete U;
			U = nullptr;
		}
		V.erase(V.begin(),V.end());
		itr++;
	}

	return 0;
}
