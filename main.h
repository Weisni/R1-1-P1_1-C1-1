/*****************************************************************************************************************************************************
 * Project													=
 * Platine													=
 * Variante / uC / Version / Revision										=
 * Funktion													=
 * Editieren													=
 * Copyright													=
 * Hardware													=
 * Oszillator													=
 * Timer 1													=
 * Timing main													=
 * Timing Watchdog												=
 * Author													=	mm
 * Erstelldatum													=	3. Dezember 2020, 14:35
 * Dateiname													=	main.h
 *
 ****************************************************************************************************************************************************/

#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include "KG-Lib/KG-Lib.h"
#include "KG-Lib/UART/UART.h"
#include <libpic30.h>

// function defines
// #define UART_PRINT_TIMESTAMP				// prints timestamp before wait4main
// #define USE_LT_WRS

// parameters

#define I2C_DATA_SIZE 5 // I2C data array size

/*********************** Device settings ************************/

/*********************** I2C Init ************************/
#define LED_DATA_POS 2
#define MIXED_DATA_POS 3

#define MIXED_BYTE_WRITE_MASK 0b00000001
#define MIXED_BYTE_READ_MASK 0b11111110

/*********************** I2C / MUX functions ************************/

void MUX_Communicate(void);
void I2C_SD_Communicate(unsigned char *textString);
void I2C_Buttons_Communicate(void);
void I2C_LEDCommunicate(void);
void LED_test(void);

/*********************** Debounce functions ************************/

ButtonEvent_t Debounce_timeToState(unsigned long TimeOld, unsigned long TimeNow);

/*********************** Interrupt handler ************************/

void InterruptHandler_T1(void);

#endif /* MAIN_H */
