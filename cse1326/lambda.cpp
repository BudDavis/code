#include <iostream>

int main(int argc,char *argv[])
{
	{
		std::cout << "simple lambda" << std::endl;
		auto cleverLambda = [](int a,int b)
		{
			// note the reasonable code formatting
			return a*b;
		};
		auto fptr = cleverLambda;
		std::cout << cleverLambda(1,2) << std::endl;
		std::cout << fptr(2,2) << std::endl;
	}
	std::cout << "simple with capture" << std::endl;
	int direction = 1;
	auto cleverLambdaWithCapture = [&direction](int a, int b)  // take out the & and see the compiler yell
	{
		direction = direction*-1;
		return direction*a*b;
	};
	std::cout << cleverLambdaWithCapture(1,1) << std::endl;
	direction = 0;
	std::cout << cleverLambdaWithCapture(1,1) << std::endl;

}
