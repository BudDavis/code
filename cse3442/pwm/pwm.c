#include <stdint.h>
#include "tm4c123gh6pm.h"

/*
 *

 * this is a pwm example taken directly out of the data sheet.
 *
 // M0PWM0  Pin 1 PB6 (4)
 // M0PWM1  Pin 4 PB7 (4)
 *
 */
#define PB6 0x40
#define PB7 0x80

int main(void)
{
    // Configure HW to work with 16 MHz XTAL, PLL enabled, sysdivider of 5, creating system clock of 40 MHz
    SYSCTL_RCC_R = SYSCTL_RCC_XTAL_16MHZ | SYSCTL_RCC_OSCSRC_MAIN
            | SYSCTL_RCC_USESYSDIV | (4 << SYSCTL_RCC_SYSDIV_S);

    // Enable the modules.
    SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGC2_GPIOB;
    _delay_cycles(3);

    /*
     3. In the GPIO module, enable the appropriate pins for their alternate function using the
     GPIOAFSEL register. To determine which GPIOs to configure, see Table 23-4 on page 1344.
     */

    GPIO_PORTB_AFSEL_R |= PB6 | PB7;
    GPIO_PORTB_ODR_R &= ~(PB6 | PB7);       //    disable open drain on PB6, PB7
    GPIO_PORTB_DEN_R |= PB6 | PB7;          //    enable digital I/O on PB6, PB7
    GPIO_PORTB_AMSEL_R &= ~(PB6 | PB7);     //    disable analog function on PB6, PB7

    GPIO_PORTB_PCTL_R &= ~(GPIO_PCTL_PB6_M | GPIO_PCTL_PB7_M);
    GPIO_PORTB_PCTL_R |= GPIO_PCTL_PB6_M0PWM0 | GPIO_PCTL_PB7_M0PWM1;

    // Clear PWM clock
    SYSCTL_RCC_R &= ~SYSCTL_RCC_PWMDIV_M;

    // system clock is 40 MHZ
    SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV | SYSCTL_RCC_PWMDIV_8;

    // Disable PWM0
    PWM0_0_CTL_R = 0x0;

    //  could have just set it to 0, instead of all this
    PWM0_0_GENA_R &= ~(PWM_0_GENA_ACTCMPBD_M | PWM_0_GENA_ACTCMPBU_M
            | PWM_0_GENA_ACTCMPAD_M | PWM_0_GENA_ACTCMPAU_M
            | PWM_0_GENA_ACTZERO_M | PWM_0_GENA_ACTLOAD_M);

    PWM0_0_GENA_R = PWM_0_GENA_ACTCMPAD_ONE | PWM_0_GENA_ACTLOAD_ZERO;

    // 10  mhz clock
    // 15 kkhz period

    PWM0_0_LOAD_R = 962;
    PWM0_0_CMPA_R = 307;;


    // enable outputs

    PWM0_ENABLE_R |= PWM_ENABLE_PWM0EN;
    // CTL_MODE = 1 count up/down, 0 = count down
    PWM0_0_CTL_R |= PWM_0_CTL_ENABLE; //  |PWM_0_CTL_MODE; // start PWM0 Generator 0

    while (1)
        ;
    return 0;

}
