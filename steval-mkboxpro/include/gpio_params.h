#ifndef GPIO_PARAMS_H
#define GPIO_PARAMS_H

#include "board.h"
#include "saul/periph.h"

#ifdef __cplusplus
extern "C" {
#endif
static const  saul_gpio_params_t saul_gpio_params[] =
{
    {
        .name = "LD0", 
        .pin = LED0_PIN,
        .mode = GPIO_OUT,
    },
    {
        .name = "LD1", 
        .pin = LED1_PIN,
        .mode = GPIO_OUT,
    },
    {
        .name = "LD2",  
        .pin = LED2_PIN,
        .mode = GPIO_OUT,
    },
    {
        .name = "LD3", 
        .pin = LED3_PIN,
        .mode = GPIO_OUT,
    },
    {
        .name = "SW1",
        .pin = BTN1_PIN,
        .mode = BTN1_MODE,
    },
    {
        .name = "SW2" /* Green LED */,
        .pin = BTN2_PIN,
        .mode = BTN2_MODE,
    }
};
#ifdef __cplusplus
}
#endif

#endif /* GPIO_PARAMS_H */
