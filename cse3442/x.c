#include <stdint.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"


int main()
{
	printf("%x\n",GPIO_PORTF_DATA_BITS_R);
}
