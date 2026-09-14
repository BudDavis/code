#include <iostream>
#include "termcolor.hpp"
using namespace termcolor;
using namespace std;
int main()
{
	cout << on_blue;
	cout << red << "A" << endl;
	cout << on_white;
	cout << blue << "B" << endl;
	cout << reset;
}
