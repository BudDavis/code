#include <iostream>
#include <string>

int main()
{
	std::string X = "cba";
	auto reverse = [](std::string S)
	{
		std::string R;
		for ( auto &ch : S)
			R = ch + R;
		return R;
	};
	
	auto Y = reverse(X);

	std::cout << "original " << X << " reversed " << Y << std::endl;

}
