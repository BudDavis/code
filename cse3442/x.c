#include <stdint.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"


int main()
{
	uint32_t *p = (uint32_t*) 0x420053fc;
	printf("%x\n",&p[1]);
}
