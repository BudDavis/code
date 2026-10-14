#include <stdint.h>
#include "tm4c123gh6pm.h"
#include <stdio.h>

int main()
{
	printf("%x\n",&GPIO_PORTC_DATA_BITS_R[(0xff<<2)]);
}
