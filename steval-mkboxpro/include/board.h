/*
 * Copyright (C) 2024 SSV Software Systems GmbH
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_steval-mkboxpro
 * @{
 *
 * @file
 * @brief       Board specific definitions for the SensorTile.box PRO
 *
 * @author      Marvin Drescher <mdr@ssv-embedded.de>
 */

#ifndef BOARD_H
#define BOARD_H

#include "cpu.h"
#include "periph_conf.h"
#include "periph_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Put here board specific definitions:
 - LEDs/buttons macros,
 - on-board drivers parameters
 - xtimer configuration
 */

#define LED0_PIN_NUM        9
#define LED0_PORT_NUM       PORT_F

#define LED1_PIN_NUM        6
#define LED1_PORT_NUM       PORT_F

#define LED2_PIN_NUM        11
#define LED2_PORT_NUM       PORT_H

#define LED3_PIN_NUM        12
#define LED3_PORT_NUM       PORT_H
/** @} */

/**
 * @name    Button pin configuration
 * @{
 */
#define BTN1_PIN            GPIO_PIN(PORT_C, 13)
#define BTN1_MODE           GPIO_IN_PU

#define BTN2_PIN            GPIO_PIN(PORT_E, 0)
#define BTN2_MODE           GPIO_IN_PU



// DIL24 connector
#define DIL_GP 				    GPIO_PIN(PORT_G, 3)
#define DIL_DEN 			    GPIO_PIN(PORT_G, 4)
#define DIL_INT4 			    GPIO_PIN(PORT_G, 15)
#define DIL_INT3 			    GPIO_PIN(PORT_G, 0)
#define DIL_INT2 		    	    GPIO_PIN(PORT_G, 6)
#define DIL_INT1 			    GPIO_PIN(PORT_G, 2)

#define SAI_FS 				    GPIO_PIN(PORT_A, 9)
#define SAI_SCK 			    GPIO_PIN(PORT_A, 8)
#define SAI_MCLK 			    GPIO_PIN(PORT_A, 3)
#define SAI_SD 				    GPIO_PIN(PORT_A, 10)

#define MDF1_CCK 			    GPIO_PIN(PORT_F, 10)
#define MDF1_SDI0 			    GPIO_PIN(PORT_D, 3)
#define MDF1_SDI1 			    GPIO_PIN(PORT_B, 12)
#define MDF1_SDI2 			    GPIO_PIN(PORT_E, 7)
#define MDF1_SDI3 			    GPIO_PIN(PORT_E, 4)

#ifdef __cplusplus
}
#endif

#include "stm32_leds.h"
#endif /* BOARD_H */
/** @} */
