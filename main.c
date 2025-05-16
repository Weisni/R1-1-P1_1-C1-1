/*****************************************************************************************************************************************************
 * Project													=
 * Platine													=
 * Variante / uC / Version / Revision						=
 * Funktion													=
 * Editieren												=
 * Copyright												=
 * Hardware													=
 * Oszillator												=
 * Timer 1													=
 * Timing main												=
 * Timing Watchdog											=
 * Author													=	mm
 * Erstelldatum												=	3. Dezember 2020, 14:36
 * Dateiname												=	main.c
 *
 ****************************************************************************************************************************************************/

#include <xc.h>
#include <libpic30.h>
#include "main.h"
#include "KG-Lib/Timer/Timer1.h"

/********************************* Defines / Variables / Structs / Unions ****************************************************/

/********************************* SD / I2C / Buttons ****************************************************/

#define SD_DATA_START 0
#define SD1_DATA_POS 0
#define SD2_DATA_POS 1

#define MUX_STATE_BUTTON_MASK 0x7E

/********************************* Functions ****************************************************/

unsigned char reverse(unsigned char b)
{
	unsigned char r = 0;
	unsigned byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return r;
}

void SD_Communicate(void)
{
	SD_Segments_t SD_Bytes[2];
	SD_ParseBytes((unsigned char *)System_getDisplayString(), SD_Bytes, 2);

	static bool init = false;

	if (!init)
	{
		/**
		 * Display init
		 *
		 */

		init = true;
		Pin_Mode_t InitMode = PIN_MODE_OUTPUT_LOW;
		bool activelow = 0;
#ifdef DEV_SD1_ACTIVE_LOW
		activelow = true;
		InitMode = PIN_MODE_OUTPUT_HIGH;
#endif

		// segment for base 1 digits
		Pin_SingleInit(DEV_SD1_SEG_A_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD1_SEG_B_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD1_SEG_C_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD1_SEG_D_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD1_SEG_E_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD1_SEG_F_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD1_SEG_G_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD1_SEG_DP_PIN, InitMode, activelow);

		activelow = false;
#ifdef DEV_SD10_ACTIVE_LOW
		activelow = true;
		InitMode = PIN_MODE_OUTPUT_HIGH;
#endif

		// Segment for base 10 digits
		Pin_SingleInit(DEV_SD10_SEG_A_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD10_SEG_B_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD10_SEG_C_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD10_SEG_D_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD10_SEG_E_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD10_SEG_F_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD10_SEG_G_PIN, InitMode, activelow);
		Pin_SingleInit(DEV_SD10_SEG_DP_PIN, InitMode, activelow);
	}

	Pin_digitalWrite(DEV_SD1_SEG_A_PIN, SD_Bytes[0].Bits.SegA_Bit);
	Pin_digitalWrite(DEV_SD1_SEG_B_PIN, SD_Bytes[0].Bits.SegB_Bit);
	Pin_digitalWrite(DEV_SD1_SEG_C_PIN, SD_Bytes[0].Bits.SegC_Bit);
	Pin_digitalWrite(DEV_SD1_SEG_D_PIN, SD_Bytes[0].Bits.SegD_Bit);
	Pin_digitalWrite(DEV_SD1_SEG_E_PIN, SD_Bytes[0].Bits.SegE_Bit);
	Pin_digitalWrite(DEV_SD1_SEG_F_PIN, SD_Bytes[0].Bits.SegF_Bit);
	Pin_digitalWrite(DEV_SD1_SEG_G_PIN, SD_Bytes[0].Bits.SegG_Bit);
	Pin_digitalWrite(DEV_SD1_SEG_DP_PIN, SD_Bytes[0].Bits.SegP_Bit);

	Pin_digitalWrite(DEV_SD10_SEG_A_PIN, SD_Bytes[1].Bits.SegA_Bit);
	Pin_digitalWrite(DEV_SD10_SEG_B_PIN, SD_Bytes[1].Bits.SegB_Bit);
	Pin_digitalWrite(DEV_SD10_SEG_C_PIN, SD_Bytes[1].Bits.SegC_Bit);
	Pin_digitalWrite(DEV_SD10_SEG_D_PIN, SD_Bytes[1].Bits.SegD_Bit);
	Pin_digitalWrite(DEV_SD10_SEG_E_PIN, SD_Bytes[1].Bits.SegE_Bit);
	Pin_digitalWrite(DEV_SD10_SEG_F_PIN, SD_Bytes[1].Bits.SegF_Bit);
	Pin_digitalWrite(DEV_SD10_SEG_G_PIN, SD_Bytes[1].Bits.SegG_Bit);
	Pin_digitalWrite(DEV_SD10_SEG_DP_PIN, SD_Bytes[1].Bits.SegP_Bit);
}

/*************************************************************************************/

int main(void)
{
	/********************************* Init ****************************************************/

	// Pin_t dummy;
	// Pin_SingleInit(&dummy, 53, PIN_MODE_OUTPUT_HIGH, true);

	// while (1)
	// {
	// 	Pin_digitalWrite(&dummy, !Pin_digitalRead(&dummy));
	// }

	System_Init();

	while (1)
	{
		/********************************* Main ****************************************************/
		System_Compute();

		SD_Communicate();
	}
	return (EXIT_SUCCESS);
}

bool PrintoutFlag = false;