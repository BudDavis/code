#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


std::vector<std::string> files;

int main()
{
	std::ifstream f("filelist.txt");
	std::string S;
	while (std::getline(f,S))
	{
		std::string fname = S.substr(S.find('/'));
		files.push_back(fname);
	}
	f.close();
	std::cout << "there are " << files.size() << " names in the vector" << std::endl;

	// search for files whose filename is "map.h"
        std::vector<std::string>::iterator itr =  files.begin();
	while(itr!=files.end())
	{
		itr = std::find_if(itr,files.end(),[](std::string s)
		{
			return (s.find("/map.h")!=std::string::npos) && (s[s.size()-2]=='.');
		});
		if (itr!=files.end())
		{
        		std::cout << "found one " << *itr << std::endl;
			itr++; // skip over
		}
        }	
	return 0;
}
