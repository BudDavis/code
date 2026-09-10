#include <iostream>
int sum(float A, char B)
{
    return A;
}
int sum(float A, float B)
{
    return A+B;
}
int sum(int A,int B = 1)
{
    return A+B;
}
int main()
{
    int S = 123;
    std::cout << sum(S) << std::endl;
    std::cout << sum(S,2) << std::endl;
}