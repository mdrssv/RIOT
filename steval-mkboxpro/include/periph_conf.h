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
 * @brief       Configuration of CPU peripherals for SensorTile.box PRO board
 *
 * @author      Marvin Drescher <mdr@ssv-embedded.de>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#include "periph/cpu_common.h"
#include "periph/cpu_gpio.h"
#include "periph/cpu_spi.h"
#include "stm32u585xx.h"
#include <stdint.h>

/* Add specific clock configuration (HSE, LSE) for this board here */
#ifndef CONFIG_BOARD_HAS_LSE
#define CONFIG_BOARD_HAS_LSE 1
#endif
#ifndef CONFIG_BOARD_HAS_HSE
#define CONFIG_BOARD_HAS_HSE 1
#endif
#ifndef CONFIG_CLOCK_HSE
#define CONFIG_CLOCK_HSE MHZ(16)
#endif
#include "periph_cpu.h"

#include "cfg_timer_tim5.h"
#include "cfg_usb_otg_fs_u5.h"
#include "clk_conf.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        .dev = UART4,
        .rcc_mask = RCC_APB1ENR1_UART4EN,
        .rx_pin = GPIO_PIN(PORT_A, 1),
        .tx_pin = GPIO_PIN(PORT_A, 0),
        .rx_af = GPIO_AF8,
        .tx_af = GPIO_AF8,
        .bus = APB1,
        .irqn = UART4_IRQn,
        .type = STM32_USART,
        .clk_src = 0, /* Use APB clock */
    },
};
#define UART_0_ISR          	(isr_uart4)
#define UART_NUMOF          	ARRAY_SIZE(uart_config)

#define SPI_DUT_MISO 		GPIO_PIN(PORT_G, 10)
#define SPI_DUT_MOSI 		GPIO_PIN(PORT_B, 5)
#define SPI_DUT_SCLK 		GPIO_PIN(PORT_G, 9)
#define SPI_DUT_CS 		GPIO_PIN(PORT_G, 1)
#define SPI_DUT_CS2 		GPIO_PIN(PORT_G, 12)

static const spi_conf_t spi_config[] = {
    //  {
    //      .dev      = SPI1,
    //      .sclk_pin  = GPIO_PIN(PORT_A, 5),
    //      .miso_pin = GPIO_PIN(PORT_A, 6),
    //      .mosi_pin = GPIO_PIN(PORT_A, 7),
    //      .mosi_af  = GPIO_AF5,
    //      .miso_af  = GPIO_AF5,
    //      .sclk_af  = GPIO_AF5,
    //      .apbbus = APB2,
    //      .rccmask = RCC_APB2ENR_SPI1EN,
    //  },
    //  {
    //      .dev      = SPI2,
    //      .sclk_pin  = GPIO_PIN(PORT_I, 1),
    //      .miso_pin = GPIO_PIN(PORT_I, 2),
    //      .mosi_pin = GPIO_PIN(PORT_I, 3),
    //      .mosi_af  = GPIO_AF5,
    //      .miso_af  = GPIO_AF5,
    //      .sclk_af  = GPIO_AF5,
    //      .apbbus = APB1,
    //      .rccmask = RCC_APB1ENR1_SPI2EN,
    //  },
    {
        .dev = SPI3,
        .miso_pin = SPI_DUT_MISO,
        .mosi_pin = SPI_DUT_MOSI,
        .sclk_pin = SPI_DUT_SCLK,
        .cs_pin = SPI_DUT_CS,
        .mosi_af = GPIO_AF6,
        .miso_af = GPIO_AF6,
        .sclk_af = GPIO_AF6,
        .cs_af = GPIO_AF6,
        .apbbus = APB3,
        .rccmask = RCC_APB3ENR_SPI3EN,
    },
};

#define SPI_NUMOF ARRAY_SIZE(spi_config)

static const i2c_conf_t i2c_config[] = {
    {
        .dev = I2C1,
        .speed = I2C_SPEED_NORMAL,
        .scl_pin = GPIO_PIN(PORT_B, 6),
        .sda_pin = GPIO_PIN(PORT_B, 7),
        .scl_af = GPIO_AF4,
        .sda_af = GPIO_AF4,
        .bus = APB1,
        .rcc_mask = RCC_APB1ENR1_I2C1EN,
        .rcc_sw_mask = RCC_CCIPR1_I2C1SEL_1, /* 10: HSI16 selected */
        .irqn = I2C1_ER_IRQn,
    },
    {
        .dev = I2C2,
        .speed = I2C_SPEED_NORMAL,
        .scl_pin = GPIO_PIN(PORT_B, 13),
        .sda_pin = GPIO_PIN(PORT_B, 14),
        .scl_af = GPIO_AF4,
        .sda_af = GPIO_AF4,
        .bus = APB1,
        .rcc_mask = RCC_APB1ENR1_I2C2EN,
        .rcc_sw_mask = RCC_CCIPR1_I2C2SEL_1, /* HSI (16 MHz) */
        .irqn = I2C2_ER_IRQn,
    },
};

#define I2C_0_ISR isr_i2c1_er
#define I2C_1_ISR isr_i2c2_er

#define I2C_NUMOF ARRAY_SIZE(i2c_config)
/* put here the board peripherals definitions:
- Available clocks
- Timers
- UARTs
- PWMs
- SPIs
- I2C
- ADC
- RTC
- RTT
etc
 */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
/** @} */
