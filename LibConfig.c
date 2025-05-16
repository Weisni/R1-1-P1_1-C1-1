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
 * Erstelldatum												=	13. Januar 2021, 08:29
 * Dateiname												=	LibConfig.h
 *
 ****************************************************************************************************************************************************/

#include "LibConfig.h"

#ifdef __PIC24FJ256GA705__
#include "KG-Lib/Config/dev/FUSE_PIC24FJ256GA705.c"
#elif defined(__PIC24FJ1024GB610__)
#include "KG-Lib/Config/dev/FUSE_PIC24FJ1024GB610.c"
#else
#error unknown controller defined
#endif