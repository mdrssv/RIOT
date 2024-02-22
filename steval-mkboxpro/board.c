#include "cpu.h"
#include "periph/cpu_gpio.h"
#include "periph/gpio.h"
#include "board.h"
#define SETUP_LED(num) gpio_init(GPIO_PIN(LED##num##_PORT_NUM, LED##num##_PIN_NUM), GPIO_OUT);

void board_init(void) {
    // SPI3 
    PWR->SVMCR |= PWR_SVMCR_IO2SV;
    RCC->CCIPR3 &= ~RCC_CCIPR3_SPI3SEL;
    // Must be set to MSIK
    RCC->CCIPR3 |= RCC_CCIPR3_SPI3SEL_1;
    SETUP_LED(0);
    SETUP_LED(1);
    SETUP_LED(2);
    SETUP_LED(3);
}
