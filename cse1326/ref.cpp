#include <iostream>

int  zero (int&  v)
{
    v = 0;
    return 1;
}
int main()
{
    int X = 254;
    zero(X);
    zero(23);
    std::cout << 23 << std::endl;
    std::cout << X << std::endl;



}