/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"

#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_PORT BOARD_LED_RED_PORT
#define BOARD_LED_PIN  BOARD_LED_RED_PIN

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint32_t g_systickCounter;

/*******************************************************************************
 * Code
 ******************************************************************************/
void SysTick_Handler(void)
{
    if (g_systickCounter != 0U)
    {
        g_systickCounter--;
    }
}

void SysTick_DelayTicks(uint32_t n)
{
    g_systickCounter = n;
    while (g_systickCounter != 0U)
    {
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
	/*Hago otra modificacion del codigo*/

    /* Init output LED GPIO. */
    GPIO_PortInit(GPIO, BOARD_LED_PORT);
    /* Board pin init */
    BOARD_InitPins();
    BOARD_InitBootClocks();

    /* Set systick reload value to generate 1ms interrupt */
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
        while (1)
        {
        }
    }

    while (1)
    {
        /* Delay 500 ms */
        SysTick_DelayTicks(500U);
        GPIO_PortToggle(GPIO, BOARD_LED_PORT, 1u << BOARD_LED_PIN);
    }
}
