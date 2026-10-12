#include <iostream>
#include <string>

struct powerPlug
{
 float voltage;
};

struct amplifier
{
   float power;  // in watts
   int channels = 2;
   std::string manufacturer;
   static inline int numAmps = 0;
   amplifier()
   {
	   numAmps++;
   } 
};


struct receiver : amplifier, powerPlug
{
    bool AM;
    bool FM;
    
};

int main()
{
    receiver myGreatHiFi;
    myGreatHiFi.manufacturer = "walmart cheapie";
    myGreatHiFi.AM = true;
    myGreatHiFi.FM = false;
    myGreatHiFi.voltage = 220;

    amplifier A;

    std::cout << "my great hifi has " << myGreatHiFi.channels << " channels" << std::endl;
    std::cout << myGreatHiFi.manufacturer << std::endl;
    std::cout << "and it runs on " << myGreatHiFi.voltage << std::endl;
    std::cout << "num amps is " << amplifier::numAmps << std::endl;
    return 0;
}
