#include <iostream>

template <typename T>
T limit(T val, T max)
{
	// this is a 'clamp' function, if val is > max, max is returned.
	if (val>max)
		return max;
	return val;
}

int main()
{
	float f = 1.001f;
        float fm = 1.0f;
	std::cout << limit<float>(f,fm) << std::endl;
}
