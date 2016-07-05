#include "xparameters.h"
#include "xgpio.h"
#include <stdio.h>
#include <stdlib.h>

void simple_delay (int simple_delay)
{
        volatile int i = 0;
        for (i = 0; i < simple_delay; i++);
}

int main(int argc, char *argv[])
{
        XGpio led_gpio;              /* LED Instance */

        /* Initialize LED GPIO settings */
        XGpio_Initialize(&led_gpio, XPAR_AXI_GPIO_0_DEVICE_ID);
        XGpio_SetDataDirection(&led_gpio, 1, 0);

        /* Output something via UART1, 115200 baudrate */
        printf("Start to blink led_gpio !!!\n\r");

        int led_value = 0x03;   /* default led_gpio value */
        while(1) {
                printf("led_gpio value set to 0x%X\n\r", led_value);

                /* Set GPIO Channel 1 value. */
                XGpio_DiscreteWrite(&led_gpio, 1 , led_value);

                /* sleep and change led_gpio value */
                simple_delay(10000000);
                led_value = ~led_value;
        }

        return 0;
}
