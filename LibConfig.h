/** @documentation:
 * This file is the configuration file for the KG-Lib. It is used to configure the library for the specific device.
 * The configuration file is used to enable or disable features of the library, depending on the device.
 * To configure the library, the user must define the device type, the number of outputs, and the number of options available.
 * To use a feature, the user must define the feature and assign the pins to the feature.
 *
 * @working_principle:
 * copy the file to the project folder and adjust the settings to the specific device.
 * make sure to use a build configuration for the correct MCU.
 * The library checks for the version of this file and may throw an error if the version is outdated.
 */

#ifndef LIBCONFIG_H
#define LIBCONFIG_H

#include <xc.h>
#include "GitVersion/GitVersion.h"

/*********************** Debug configs ************************/

#define DELAY_PRINT_DATA 0 // time in ms

#define CONFIG_ENABLE_WDT
#define CONFIG_BROWN_OUT_ENABLE

/*********************** Library debug ************************/

// #define KG_LIB_SHOW_WIP					// displays work in progress messages when compiling

/***********************************************************************************************
*********************************		GENERAL CONFIG			********************************
*	Software version must be updated on change!
*/

#define SYSTEM_HAS_VOLTAGE_REFERENCE // system has voltage reference to convert values to real world values with high accuracy
#ifdef SYSTEM_HAS_VOLTAGE_REFERENCE
#define SYSTEM_VOLTAGE_REFERENCE 2.5f // reference voltage nominal
#define SYSTEM_VOLTAGE_REFERENCE_PIN 32
#endif

#define USE_SOFTWARE_RESET
#ifdef USE_SOFTWARE_RESET
#define SOFTWARE_RESET_PIN_NUMBER 50
#endif

#if defined(__PIC24FJ1024GB610__)
/**
 * Defined DUAL_PARTITION to use 2 images within flash.
 * The bootloader is swapping between both images on update to preserve a fallback image.
 *
 */
#define DUAL_PARTITION
#endif

/***********************************************************************************************
*********************************		SYSTEM CONFIG			********************************/

/************
 * Device Type
 *
 * Select device type for settings and menu structure
 */
#define DEVICE_TYPE_RWZ 1
#define DEVICE_TYPE_WRS 2

#define DEVICE_TYPE DEVICE_TYPE_RWZ

/*	DEV_HAS_BOOTLOADER
 *
 * Device has bootloader and ESP32 for Updates
 */
#define DEV_HAS_BOOTLOADER

/*	FLASH_USER_MEMORY
 *
 * User memory neede for Main
 * define flash storage needed in int size
 */
#define FLASH_USER_MEMORY 0

/***********************************************************************************************
*********************************		MAINS CONFIG			********************************/
/* Select, if the device checks for mains voltage via +24N from the SMPS and
 * how many main fuses the device has. Each fuse has to have a seperate sense pin.
 */
#define DEV_MAINS_FUSE_COUNT 1

#if DEV_MAINS_FUSE_COUNT > 0
#define DEV_SENSE_MAINS // device does check mains voltage

#define SENSE_MAINS_PIN 35                 // �C Pin Number for sensing mains supply voltage (on DC side)
#define SENSE_MAINS_DIVIDER_RAIO 0.090909f // define the ratio (out / in) and set the threshold below

#if DEV_MAINS_FUSE_COUNT > 1
#error DEV_MAINS_FUSE_COUNT: only 1 main fuse supported! Must be implemented to be used!
#define SENSE_SUPPLY_F1_2_PIN 0 // �C Pin Number for sensing additional power supply voltage (on DC side)
#endif
#if DEV_MAINS_FUSE_COUNT > 2
#define SENSE_SUPPLY_F1_3_PIN 0 // �C Pin Number for sensing additional power supply voltage (on DC side)
#endif
#if DEV_MAINS_FUSE_COUNT > 3
#define SENSE_SUPPLY_F1_2_PIN 0 // �C Pin Number for sensing additional power supply voltage (on DC side)
#endif

/*	VOLTAGE DIVIDER
 * By default, the divider is irrelevant, because there is a 846 transistor
 * with the below described voltage divider, which limits the current to around 400�A,
 * meaning the base voltage settles to around 600 - 700mV.
 *
 * The default divider ratio = R2 / (R1 + R2):
 * R1 = 100k
 * R2 = 10k
 * (Ratio : 0.090909)
 *
 * If the circuit changes and a voltage divider is usable,
 * use the #define SENSE_MAINS_DIVIDER_RATIO and adapt the SENSE_MAINS_DIVIDER_THRESHOLD
 */
#define SENSE_MAINS_DIVIDER_RATIO 0.090909f // define the ratio (out / in) and set the threshold below
#define SENSE_MAINS_THRESHOLD 21.6f         // if sensed voltage falls below this threshold, system sets mains error
#endif

/***********************************************************************************************
*********************************		OPTION CONFIG			********************************/

#define DEV_OPTION_SLOT_COUNT 1 // how many options are available?

// Configure Compatible Options

#if DEV_OPTION_SLOT_COUNT > 0
#define UART_RX_OPTION_ENABLE
#define DEV_OPTION_O01_ENABLE // define if option is enabled
#define DEV_OPTION_O11_ENABLE // define if option is enabled
#define DEV_OPTION_O21_ENABLE // define if option is enabled
#define DEV_OPTION_O22_ENABLE // define if option is enabled
#define DEV_OPTION_O31_ENABLE // define if option is enabled
#define DEV_OPTION_O41_ENABLE // define if option is enabled

// maximum option count per option
#ifdef DEV_OPTION_O01_ENABLE
#define DEV_OPTION_O01_MAX 1
#else
#define DEV_OPTION_O01_MAX 0
#endif

#ifdef DEV_OPTION_O11_ENABLE
#define DEV_OPTION_O11_MAX 4
#else
#define DEV_OPTION_O11_MAX 0
#endif

#ifdef DEV_OPTION_O21_ENABLE
#define DEV_OPTION_O21_MAX 1
#else
#define DEV_OPTION_O21_MAX 0
#endif

#ifdef DEV_OPTION_O22_ENABLE
#define DEV_OPTION_O22_MAX 1
#else
#define DEV_OPTION_O22_MAX 0
#endif

#ifdef DEV_OPTION_O31_ENABLE
#define DEV_OPTION_O31_MAX 1
#else
#define DEV_OPTION_O31_MAX 0
#endif

#ifdef DEV_OPTION_O41_ENABLE
#define DEV_OPTION_O41_MAX 1
#else
#define DEV_OPTION_O41_MAX 0
#endif

// Option default settings

#ifdef DEV_OPTION_O01_ENABLE

#endif

#ifdef DEV_OPTION_O11_ENABLE
#if (DEVICE_TYPE == DEVICE_TYPE_WRS)
#define FW_O11_PK_1_FUNCTION_DEFAULT PK_FUNCTION_WRC_RAIN_AND_WIND
#define FW_O11_PK_2_FUNCTION_DEFAULT PK_FUNCTION_WRC_RAIN_AND_WIND
#define FW_O11_PK_1_DISABLE_DEFAULT 0
#define FW_O11_PK_2_DISABLE_DEFAULT 0
#define FW_O11_PK_1_HOLD_OFF_TIME_DEFAULT 6
#define FW_O11_PK_2_HOLD_OFF_TIME_DEFAULT 6
#endif
#if (DEVICE_TYPE == DEVICE_TYPE_RWZ)
#define FW_O11_PK_1_FUNCTION_DEFAULT PK_FUNCTION_ALARM
#define FW_O11_PK_2_FUNCTION_DEFAULT PK_FUNCTION_ERROR
#define FW_O11_PK_1_DISABLE_DEFAULT 0
#define FW_O11_PK_2_DISABLE_DEFAULT 0
#define FW_O11_PK_1_HOLD_OFF_TIME_DEFAULT 0
#define FW_O11_PK_2_HOLD_OFF_TIME_DEFAULT 0
#endif
#endif

#ifdef DEV_OPTION_O21_ENABLE
#define FW_O21_RAIN_SENSOR_SENSITIVITY_DEFUALT 1
#define FW_O21_WIND_SENSOR_SENSITIVITY_DEFAULT 1
#define FW_O21_WIND_SENSOR_REDUCED_SENSITIVITY_DEFAULT false
#define FW_O21_PK_HOLD_OFF_TIME_DEFAULT 6
#define FW_O21_WIND_SENSOR_TIMEOUT_DEFAULT 72
#define FW_O21_HEATER_POWER_DEFAULT 0
#define FW_O21_PK_FUNCTION_DEFAULT PK_FUNCTION_WRC_RAIN_AND_WIND
#define FW_O21_PK_DISABLE_DEFAULT 0
#endif

#ifdef DEV_OPTION_O22_ENABLE
#define FW_O22_THERMAL_SWITCH_CONTACT_TYPE_DEFAULT O22_SWITCH_NORMALLY_OPEN
#define FW_O22_HOLD_OPEN_DEFAULT 0
#endif

#ifdef DEV_OPTION_O31_ENABLE
#define FW_O31_OUTPUT_1_FUNCTIN_DEFAULT O31_EVENT_ALARM
#define FW_O31_OUTPUT_1_AUTO_RESET_DEFAULT 60 // 60 minutes is maximum for default
#define FW_O31_OUTPUT_1_REVERSE_SIGNAL_DEFAULT false
#define FW_O31_OUTPUT_2_FUNCTIN_DEFAULT O31_EVENT_ALARM
#define FW_O31_OUTPUT_2_AUTO_RESET_DEFAULT 60 // 60 minutes is maximum for default
#define FW_O31_OUTPUT_2_REVERSE_SIGNAL_DEFAULT false
#define FW_O31_INPUT_1_FUNCTIN_DEFAULT O31_RESET_SOURCE_ALL_OUTPUTS
#define FW_O31_INPUT_1_CONTACT_TYPE_DEFAULT O31_SWITCH_NORMALLY_OPEN
#endif

#ifdef DEV_OPTION_O41_ENABLE
#define FW_O41_FACP_AT_DEFAULT 0 // 0 = no FACP at reset
#endif
#endif

/***********************************************************************************************
*********************************		PROGRAMMING CONFIG			****************************/

#define PROGRAMM_DAT_CONTROLLER_PIN 25
#define PROGRAMM_CLK_CONTROLLER_PIN 24

/***********************************************************************************************


*********************************		I2C CONFIG			************************************/
// #define I2C1_ENABLE
#define I2C2_ENABLE

#define I2C_LINE_OPTION 2

#ifdef I2C1_ENABLE
#ifdef __24FJ256GA705__
// #define CONFIG_I2C1_ALTERNATE_PINS_ENABLE // define to use alternate pins (ASDA & ASCL)
#endif
#endif

/***********************************************************************************************
*********************************		UART CONFIG			************************************/

#define DEV_HAS_ESP // device has ESP for Updates and config

#define DEV_UART_DEBUG // device has debug uart

#define PROGRAMM_USE_AS_UART

#ifndef PROGRAMM_USE_AS_UART
#define UART_PIC_2_PC_CONTROLLER_PIN 27
#define UART_PC_2_PIC_CONTROLLER_PIN 28
#endif

#ifdef DEV_HAS_ESP
#define UART_PIC_2_ESP_CONTROLLER_PIN 82
#define UART_ESP_2_PIC_CONTROLLER_PIN 81
#endif

/***********************************************************************************************
*********************************		MENU CONFIG			************************************/

/**************
 * MENU BUTTONS
 */

#define DEV_BUTTON_OK_PIN 39
#define DEV_BUTTON_BACK_PIN 41
#define DEV_BUTTON_UP_PIN 38
#define DEV_BUTTON_DOWN_PIN 40

#if DEVICE_TYPE == DEVICE_TYPE_RWZ
#define DEV_BUTTON_RESET_ALARM_PIN 28

// if Device is able to change the action mode
#define DEV_HAS_ACTION_MODE
#endif

/**************
 * MENU LEDS
 */

#define DEV_LED_DUO_GREEN_PIN 43
#define DEV_LED_DUO_GREEN_ACTIVE_LOW

#define DEV_LED_DUO_RED_PIN 42
#define DEV_LED_DUO_RED_ACTIVE_LOW

/**
 * If SD is on I2C multiplexer, pin configuration is ignored and digital writes are omitted
 */
// #define DEV_SD_I2C

/**
 * SD Pin Configuration
 */
#ifndef DEV_SD_I2C
#define DEV_SD1_SEG_A_PIN 73
#define DEV_SD1_SEG_B_PIN 74
#define DEV_SD1_SEG_C_PIN 68
#define DEV_SD1_SEG_D_PIN 69
#define DEV_SD1_SEG_E_PIN 70
#define DEV_SD1_SEG_F_PIN 72
#define DEV_SD1_SEG_G_PIN 71
#define DEV_SD1_SEG_DP_PIN 67
#define DEV_SD1_ACTIVE_LOW

#define DEV_SD10_SEG_A_PIN 57
#define DEV_SD10_SEG_B_PIN 60
#define DEV_SD10_SEG_C_PIN 63
#define DEV_SD10_SEG_D_PIN 64
#define DEV_SD10_SEG_E_PIN 66
#define DEV_SD10_SEG_F_PIN 56
#define DEV_SD10_SEG_G_PIN 54
#define DEV_SD10_SEG_DP_PIN 61
#define DEV_SD10_ACTIVE_LOW
#endif

/**************************************
 * Menupoint config
 * ******
 * Menupoint 0 - 9 = Device specific
 * Menupoint A - D = Option Slots
 * Menupoint E		= unused
 * Menupoint F		= Factory Reset
 * Menupoints A-D are configured via option slot count
 */

/*********************************  PK Config ********************************************
 * PK Outputs:
 * PK		= External potential-free contact (ON BOARD!!)
 * Edit pin configuration by using controller pin numbers
 * I�C isn't possible right now
 */

#define DEV_PK_COUNT 0

#if DEV_PK_COUNT > 0
#define PK1_PIN 41 // PK1 pin
#endif
#if DEV_PK_COUNT > 1
#define PK2_PIN 45 // PK2 pin
#endif
#if DEV_PK_COUNT > 2
#define PK3_PIN 46 // PK3 pin
#endif
#if DEV_PK_COUNT > 3
#define PK4_PIN 46 // PK4 pin
#endif

/***********************************************************************************************
*********************************		DEVICE TYPE RWZ		************************************
************************************************************************************************
* The following settings are only available to devices configured as RWZ
*/

#if DEVICE_TYPE == DEVICE_TYPE_RWZ

/***********************************************************************************************
*********************************		SYSTEM CONFIG		***********************************/

// if device is SHEVS, CRC check is mandatory!
#define CRC_CHECK

/***********************************************************************************************
*********************************		LED CONFIG			************************************/

#define DEV_LED_OK_PIN 53
#define DEV_LED_OK_ACTIVE_LOW

#define DEV_LED_ALARM_PIN 52
#define DEV_LED_ALARM_ACTIVE_LOW

#define DEV_LED_ERROR_PIN 51
#define DEV_LED_ERROR_ACITVE_LOW

#define DEV_LED_UP_PIN 49
#define DEV_LED_UP_ACTIVE_LOW

#define DEV_LED_DOWN_PIN 48
#define DEV_LED_DOWN_ACTIVE_LOW

#define DEV_LED_WRC_PIN 47
#define DEV_LED_WRC_ACTIVE_LOW

/*	Maintanance counter
 * if enabled, maintanance counter and mode is activated
 */
#define DEV_HAS_MAINTANANCE_COUNTER

#ifdef DEV_HAS_MAINTANANCE_COUNTER
#define MENU_MAINTANANCE_ENABLE

#define DEV_LED_MAINTANANCE_PIN 44
#define DEV_LED_MAINTANANCE_ACTIVE_LOW
#endif

/***********************************************************************************************
*********************************		SHE CONFIG			************************************/

#define DEV_SHE_GROUP_COUNT 1

#if DEV_SHE_GROUP_COUNT > 0
#define DEV_HAS_SHE
#endif

#define SYSTEM_LINE_REF_PIN 27
#define SYSTEM_LINE_REF_DIVIDER_RATIO 0.189935f // ratio of Voltage divider on VREF
#define SYSTEM_LINE_VOLTAGE_MAX 15.27f
#define SYSTEM_LINE_VOLTAGE_MIN 13.42f

// pin assignment for SHE groups
#if DEV_SHE_GROUP_COUNT > 0

/*************
 * MCP Config
 */
#define DEV_HAS_MCP
#define MCP_HAS_WARNING_TONE

#ifdef DEV_HAS_MCP
#define MCP_SHE1_PIN_LED_OK 95
#define MCP_SHE1_PIN_LED_ERROR 96
#define MCP_SHE1_PIN_LED_ALARM 97
#define MCP_SHE1_PIN_BUTTON_ALARM 9
#define MCP_SHE1_PIN_BUTTON_RESET_ALARM 93

// active low config
// #define MCP_SHE1_PIN_LED_OK_ACTIVE_LOW
// #define MCP_SHE1_PIN_LED_ERROR_ACTIVE_LOW
// #define MCP_SHE1_PIN_LED_ALARM_ACTIVE_LOW

// Warning Tone
#ifdef MCP_HAS_WARNING_TONE
#define MCP_SHE1_PIN_WARNING_TONE 87

#define MCP_SHE1_PIN_BUTTON_RESET_WARNING_TONE 94

// if defined, button is active low
#define MCP_SHE1_BUTTON_RESET_WARNING_TONE_ACTIVE_LOW 0
#endif
#endif

/*************
 * RM Config
 */

#define DEV_HAS_RM
#ifdef DEV_HAS_RM
#define RM_SHE1_PIN_AN_IN 92
#define RM_SHE1_PIN_RESET 98
#endif
#endif

/***********************************	Thermal Alarm
 * Define if device does sense temperature and is capable of activating thermal alarm
 */

#if DEV_SHE_GROUP_COUNT > 0
#define DEV_HAS_THERMAL_ALARM
#endif

/***********************************************************************************************
*********************************		FACP CONFIG			************************************/
/* Define if the device has an FACP input or not.
 * Maximum FACP input is 1, besides that, the RM input is also capable of FACP functions with the module MA
 */

#if DEV_SHE_GROUP_COUNT > 1
#define DEV_HAS_FACP
#error "FACP not fully implemented!"
#endif

/***********************************************************************************************
*********************************		OUTPUT CONFIG			********************************/
/* Define how many outputs the device has
 * (actuator outputs like a default SHEVS)
 *
 *** PIN_UP / PIN_DOWN setup:
 *		+DC				+DC
 *	   __|__		   __|__
 *	  |	 K1 |		  |  K4 |
 *	     |_______________|_________| ULN |--PIN_�C
 *
 *** PIN_SENSE setup:
 *
 *
 *** Output Pin configuration:
 * Edit pin configuration by using controller pin numbers
 * I�C isn't possible right now
 */

#define DEV_OUTPUT_COUNT 1

#if DEV_OUTPUT_COUNT > 0

#define OUTPUT_1_PIN_UP 100         // Output 1 pin for drive up
#define OUTPUT_1_PIN_DOWN 99        // Output 1 pin for drive down
#define OTUPUT_1_PIN_DOWN_SENSE 7   // Output 1 pin for drive down / switch to sense circuit (delayed beacause of overlapping switch positions!)
#define OUTPUT_1_PIN_SENSE 10       // Output 1 pin for sense of wire break and short circuit
#define OUTPUT_1_PIN_SENSE_ENABLE 1 // Output 1 pin to enable sense circuit
#define OUTPUT_1_PIN_FUSE 3         // Output 1 pin for fuse sense

#if DEV_OUTPUT_COUNT > 1
#error Max output count is 1!
#define OUTPUT_2_PIN_UP 0    //
#define OUTPUT_2_PIN_DOWN 0  //
#define OUTPUT_2_PIN_SENSE 0 //
#define OUTPUT_2_PIN_FUSE 0  //
#endif

#if DEV_OUTPUT_COUNT > 3
#define OUTPUT_3_PIN_UP 0    //
#define OUTPUT_3_PIN_DOWN 0  //
#define OUTPUT_3_PIN_SENSE 0 //
#define OUTPUT_3_PIN_FUSE 0  //

#define OUTPUT_4_PIN_UP 0    //
#define OUTPUT_4_PIN_DOWN 0  //
#define OUTPUT_4_PIN_SENSE 0 //
#define OUTPUT_4_PIN_FUSE 0  //
#endif
#endif

#if (DEV_OUTPUT_COUNT > 0)
#define DEV_HAS_VENTILATION_GROUP
#endif

/***********************************************************************************************
*********************************		DCDC CONFIG			********************************
* if device uses a single battery and a DCDC converter to boost voltage up to 24 Volts,
* enable this define to get access to the pin configuration
*/

// #define DEV_HAS_DCDC_CONVERTER

#ifdef DEV_HAS_DCDC_CONVERTER
#define DCDC_ENABLE_PIN 3
#endif

/***********************************************************************************************
*********************************		VENTILATION BUTTONS			****************************/
/* Configure the input pins for ventilation buttons
 *
 */

#if DEV_OUTPUT_COUNT > 0
#define DEV_HAS_VENTILATION_BUTTON
#define DEV_VENT_1_BUTTON_UP_PIN 79
#define DEV_VENT_1_BUTTON_DOWN_PIN 78
#define DEV_VENT_1_LED_POSITION_INDICATOR_PIN 91
#endif

#if DEV_OUTPUT_COUNT > 1
#define DEV_VENT_2_BUTTON_UP_PIN 0
#define DEV_VENT_2_BUTTON_DOWN_PIN 0
#define DEV_VENT_2_LED_POSITION_INDICATOR_PIN 0
#endif

#if DEV_OUTPUT_COUNT > 2
#define DEV_VENT_3_BUTTON_UP_PIN 0
#define DEV_VENT_3_BUTTON_DOWN_PIN 0
#define DEV_VENT_3_LED_POSITION_INDICATOR_PIN 0
#endif

#if DEV_OUTPUT_COUNT > 3
#define DEV_VENT_4_BUTTON_UP_PIN 0
#define DEV_VENT_4_BUTTON_DOWN_PIN 0
#define DEV_VENT_4_LED_POSITION_INDICATOR_PIN 0
#endif

/***********************************************************************************************
*********************************		EWRC CONFIG			********************************/
/* Wind Rain Control Inputs:
 * EWRC		= External Wind Rain Control (input with jumper, just pullup input)
 *
 *
 */
#define DEV_HAS_EWRC

#ifdef DEV_HAS_EWRC
#define DEV_EWRC_INPUT 1 // External Wind Rain Sensor inputs

#define EWRC1_INPUT_PIN 76

#if DEV_EWRC_INPUT > 1
#error DEV_EWRC_INPUT: Maximum EWRC count is 1!
#endif
#endif

/***********************************************************************************************
*********************************		CHARGE CONFIG			********************************/

#define CHARGE_BATTERY_CAPACITY_AH 2 // battery capacity in Ah
#define CHARGE_BATTERY_COUNT 2       // number of batterys in parallel

#if CHARGE_BATTERY_COUNT > 0
#define EPS_CHANGE_SUPPLY_PIN 90 // define the pin number which is connected to the ups power source switch

/**
 * Define Pin Mapping
 */

#define CHARGE_PIN_PWM 20              // PWM output for charger, adjusting the output of the buck converter
#define CHARGE_PIN_BATTERY_OFF 89      // bistable relay to turn the battery off
#define CHARGE_PIN_BATTERY_ON 88       // bistable relay to turn the battery on
#define CHARGE_PIN_BATTERY_REVERSED 23 // battery reversed input pin (digital)
#define CHARGE_PIN_SHUNT_AN_IN 33      // shunt analog input pin
#define CHARGE_PIN_ENABLE 4            // P-Channel FET to activate charging
#define CHARGE_PIN_U_BATTERY_IN 11     // pirmary battery voltage monitoring (monitoring without activation of the bistable relay)
#define CHARGE_PIN_U_CHARGE_IN 34      // charge voltage input
#define CHARGE_PIN_LOAD_ENABLE 26      // battery test activation

/**
 * Define if signal is active low
 */
#define CHARGE_PIN_PWM_ACTIVE_LOW 0
#define CHARGE_PIN_BATTERY_OFF_ACTIVE_LOW 0
#define CHARGE_PIN_BATTERY_ON_ACTIVE_LOW 0
#define CHARGE_PIN_BATTERY_REVERSED_ACTIVE_LOW 1
#define CHARGE_PIN_ENABLE_ACTIVE_LOW 0
#define CHARGE_PIN_LOAD_ENABLE_ACTIVE_LOW 0
#endif

/***********************************************************************************************
*********************************		DEVICE TYPE WRS		************************************
************************************************************************************************
* The following settings are only available to devices configured as RWZ
*/

#elif DEVICE_TYPE == DEVICE_TYPE_WRS

#define FW_WRC_LINK_WIND_DEFAULT SETTING_VALUE_LOGIC_CONNET_OR_LINKED
#define FW_WRC_LINK_RAIN_DEFAULT SETTING_VALUE_LOGIC_CONNET_OR_LINKED

/***********************************************************************************************
*********************************		LED CONFIG			************************************/

#define DEV_LED_WIND_PIN 27
#define DEV_LED_WIND_ACTIVE_LOW

#define DEV_LED_RAIN_PIN 28
#define DEV_LED_RAIN_ACTIVE_LOW

#define DEV_LED_PANEL_POWER_PIN 39
#define DEV_LED_PANEL_POWER_ACTIVE_LOW

#define DEV_LED_PANEL_WIND_PIN 38
#define DEV_LED_PANEL_WIND_ACTIVE_LOW

#define DEV_LED_PANEL_RAIN_PIN 37
#define DEV_LED_PANEL_RAIN_ACTIVE_LOW

/***********************************************************************************************
*********************************		WRC INPUT CONFIG			************************************/

#define DEV_RAINSENSOR_PULS_PIN 2
#define DEV_RAINSENSOR_SENSE_PIN 11

#define DEV_WINDSENSOR_SENSE_PIN 22

#define DEV_HEATER_PULS_PIN 40
#define DEV_HEATER_SENSE_PIN 12

/********************************  Number of WRC Outputs ************************************
 * Define how many outputs the device has
 * switch setup:
 *          ________________________ NC / Close
 * 	 C -- K1	 	 _______________ Auf
 *		  |_______ K2_______________ NO
 *             |____________|
 *
 *** Output Pin configuration:
 * Edit pin configuration by using controller pin numbers
 * I�C isn't possible right now
 */

#define DEV_WRC_OUTPUT_COUNT 2

#if DEV_WRC_OUTPUT_COUNT > 0
#define WRC_OUTPUT_1_PK1 41 // Output 1 pin K1
#define WRC_OUTPUT_1_PK2 44 // Output 1 pin K2
#endif
#if DEV_WRC_OUTPUT_COUNT > 1
#define WRC_OUTPUT_2_PK1 45 // Output 2 pin K1
#define WRC_OUTPUT_2_PK2 46 // Output 2 pin K2
#endif
#if DEV_WRC_OUTPUT_COUNT > 2
#define WRC_OUTPUT_3_PK1 46 // Output 3 pin K1
#define WRC_OUTPUT_3_PK2 46 // Output 3 pin K2
#endif
#if DEV_WRC_OUTPUT_COUNT > 3
#define WRC_OUTPUT_4_PK1 46 // Output 4 pin K1
#define WRC_OUTPUT_4_PK2 46 // Output 4 pin K2
#endif

// DEFAULT SETTINGS OF WRC OUTPUT
#define FW_WRC_OUTPUT_HOLD_OFF_TIME_DEFAULT 6
#define FW_WRC_OUTPUT_FUNCTION_DEFAULT PK_FUNCTION_WRC_RAIN_AND_WIND
#define FW_WRC_OUTPUT_DISABLE_DEFAULT 0

/***********************************************************************************************
*********************************		WRC CONFIG			********************************/
/* Wind Rain Control Inputs:
 * WRC		= Connector for Wind- / Rainsensor (active input with computation)
 */

#define DEV_WRC_INPUT 1 // Wind Rain Sensor Inputs

#define DEV_WRC_VENTILATION_BUTTON_COUNT 2

#if (DEV_WRC_VENTILATION_BUTTON_COUNT > 0)
#define DEV_HAS_VENTILATION_BUTTON
#define DEV_WRC_VENTILATION_BUTTON_1_UP_PIN 3
#define DEV_WRC_VENTILATION_BUTTON_1_DOWN_PIN 15
#endif
#if (DEV_WRC_VENTILATION_BUTTON_COUNT > 1)
#define DEV_WRC_VENTILATION_BUTTON_2_UP_PIN 4
#define DEV_WRC_VENTILATION_BUTTON_2_DOWN_PIN 16
#endif
#if (DEV_WRC_VENTILATION_BUTTON_COUNT > 2)
#define DEV_WRC_VENTILATION_BUTTON_3_UP_PIN 35
#define DEV_WRC_VENTILATION_BUTTON_3_DOWN_PIN 33
#endif
#if (DEV_WRC_VENTILATION_BUTTON_COUNT > 3)
#define DEV_WRC_VENTILATION_BUTTON_4_UP_PIN 35
#define DEV_WRC_VENTILATION_BUTTON_4_DOWN_PIN 33
#endif
#endif

// DEFAULT SETTINGS OF WRC OUTPUT
#define FW_WRC_RAIN_STEP_DEFAULT 1                // default sensititvity: step 1, 0 = Off
#define FW_WRC_WIND_STEP_DEFAULT 40               // default sensititvity: step 1, 0 = Off
#define FW_WRC_RAIN_PULSED_HEATING_DEFAULT 0      // pulsed heating off
#define FW_WRC_WIND_REDUCED_SENSITIVITY_DEFAULT 0 // reduced sensititvity off
#define FW_WRC_WIND_TIMEOUT_DEFAULT 72            // hours

/***********************************************************************************************
*********************************		MENU CONFIG			********************************/

/*****************************
 * Comment out defines to exclude whole menupoints
 * or comment out just single menupoints
 */

//********** MAINMENU RWZ ***********

#define MENU_SYSTEM_ENABLE // Enable menu for system functions
#define MENU_TEST_ENABLE   // Enable menu for test functions

#ifdef DEBUG
#define MENU_VDS_ENABLE // Enable menu for VDS test functions
#endif

#ifdef MENU_SYSTEM_ENABLE
#define MENU_WIFI_ENABLE
#endif

// *** RWZ Specific ***

#if DEVICE_TYPE == DEVICE_TYPE_RWZ
#ifdef DEV_HAS_SHE
#define MENU_SHE_ENABLE
#endif

#ifdef DEV_HAS_VENTILATION_GROUP
#define MENU_VENTILATION_ENABLE
#endif

#ifdef DEV_HAS_ACTION_MODE
#define MENU_ACTION_MODE_ENABLE
#endif
#endif

// *** WRS Specific ***
#if DEVICE_TYPE == DEVICE_TYPE_WRS
#define MENU_SENSORTEST_ENABLE
#define MENU_DEACTIVATE_OUTPUTS_ENABLE
#endif
//********** MAINMENU WRS ***********

#if DEVICE_TYPE == DEVICE_TYPE_WRS
#define MENU_WIND_ENABLE
#define MENU_RAIN_ENABLE
#define MENU_PK1_ENABLE
#define MENU_PK2_ENABLE
#endif

//********** MAINMENU MAINTANANCE ***********

#ifdef MENU_MAINTANANCE_ENABLE
#define MENU_MAINTANANCE_RESET_COUNTER_ENABLE
#define MENU_MAINTANANCE_SET_INTERVAL_ENABLE
#define MENU_MAINTANANCE_SET_COUNTER_STATE_ENABLE
#endif

//********** SUBMENU SHE ***********

#ifdef MENU_SHE_ENABLE
#define MENU_CLOSE_AFTER_ALARM_ENABLE
#define MENU_ALARM_CLOSE_ENABLE
#define MENU_ALARM_ON_ERROR_ENABLE
#define MENU_THERMAL_ALARM_ENABLE
#define MENU_ALARM_OUTPUT_DELAY_ENABLE
#define MENU_ALARM_OUTPUT_SIGNAL_MODE_ENABLE
#define MENU_RM_MODE_ENABLE
#endif

//********** SUBMENU VENTILATION ***********

#ifdef MENU_VENTILATION_ENABLE
#define MENU_AUTOMATIC_ENABLE
#define MENU_EWRC_ENABLE
#define MENU_USE_POSITION_ENABLE
#define MENU_POSITION_PROGRAMMING_ENABLE
#define MENU_VENTILATION_DURATION_ENABLE
#endif

//********** SUBMENU TEST ***********

#ifdef MENU_TEST_ENABLE
#define MENU_TESTALARM_ENABLE
#define MENU_BATTERYTEST_ENABLE
#endif

//********** SUBMENU VDS ***********

#ifdef MENU_VDS_ENABLE
#define VDS_MENU_WATCHDOG_ENABLE
#define VDS_MENU_CRC_ENABLE

#if defined(VDS_MENU_CRC_ENABLE)
#define VDS_CRC_CHECK_VALUE 0x222222lu
#endif

#define VDS_MENU_ALARM_REPULSE_ENABLE
#endif

/****************************************************************************************************************
 * ##############################################################################################################
 * #########################								#####################################################
 * #########################	Automatic configuration		#####################################################
 * #########################	KEEP OUT OF THIS AREA		#####################################################
 * #########################								#####################################################
 * ##############################################################################################################
 *
 *			!!! DONT TOUCH ANY CONFIGURATION BELOW THIS LINE !!!
 *
 * All configurations below here does have massive effects on the library routines.
 * If something does not work or can't be configured, contact one of the library administrators!
 */

#define LIBCONFIG_VER_HV 1
#define LIBCONFIG_VER_NV 2
#define LIBCONFIG_VER_BF 2

/****	SYSTEM CONFIG	*****
 */

#define UART_RX_FLASH_ENABLE
#define UART_RX_SD_ENABLE
#define UART_RX_HELP_ENABLE

#if defined(DEV_HAS_FACP)
#error DEV_HAS_FACP: FACP not fully implemented!
#error DEV_HAS_FACP: Decision made by TR and MS on 23rd of Mai 2022
#endif

#if CHARGE_BATTERY_COUNT > 0 && !defined(DEV_SENSE_MAINS)
#error DEV_SENSE_MAINS must be defined if CHARGE_BATTERY_COUNT is defined > 1!
#endif

#if DEV_OUTPUT_COUNT > 0
#define DEV_HAS_OUTPUT
// group assignment check
#if DEV_OUTPUT_COUNT > 1
#error DEV_OUTPUT_COUNT: Only 1 Output possible!
#error DEV_OUTPUT_COUNT: Decision made by TR and MS on 23rd of Mai 2022
#endif
#endif

#if DEV_OPTION_SLOT_COUNT > 0
#define DEV_HAS_OPTION

#if DEV_OPTION_SLOT_COUNT > 4
#error DEV_OPTION_SLOT_COUNT: only up to 4 slots are supported!
#endif
#endif

#if CHARGE_BATTERY_COUNT > 0
#define DEV_HAS_EPS
#if CHARGE_BATTERY_COUNT > 2
#error CHARGE_BATTERY_COUNT: more than 2 Batterys not supported
#endif
#endif

#if DEV_EWRC_INPUT > 0
#define DEV_HAS_EWRC
#endif

#ifdef DEV_SENSE_MAINS

#if DEV_MAINS_FUSE_COUNT > 2
#error DEV_MAINS_FUSE_COUNT: Only 1 mains fuse implemented right now!
#endif

#endif

// button config

#if DEV_BUTTON_OK_PIN == I2C ||   \
    DEV_BUTTON_BACK_PIN == I2C || \
    DEV_BUTTON_UP_PIN == I2C ||   \
    DEV_BUTTON_DOWN_PIN == I2C || \
    (DEVICE_TYPE == DEVICE_TYPE_RWZ && DEV_BUTTON_RESET_ALARM_PIN == I2C)
#define BUTTON_I2C_OPERATION
#endif

// Menu config

#if (DEV_SHE_GROUP_COUNT > 0)

#define UART_RX_MCP_ENABLE
#define UART_RX_RM_ENABLE

#if DEV_SHE_GROUP_COUNT > 1
#error DEV_SHE_GROUP_COUNT: Only 1 SHE Group is possible!
#error Decision made by TR and MS on 23rd of Mai 2022
#endif
#endif

#if (DEV_WRC_VENTILATION_BUTTON_COUNT > 0)
#ifndef DEV_HAS_VENTILATION
#define DEV_HAS_VENTILATION
#endif
#endif

#if defined(__PIC24FJ2560GA705__)
#if PROGRAMM_DAT_CONTROLLER_PIN == 23
#ifdef CONTROLLERPIN_23
#error "double pin configuration!"
#endif
#ifndef PROGRAMM_USE_AS_UART
#define CONTROLLERPIN_23
#endif
#if PROGRAMM_CLK_CONTROLLER_PIN == 24
#ifdef CONTROLLERPIN_24
#error "double pin configuration!"
#endif
#ifndef PROGRAMM_USE_AS_UART
#define CONTROLLERPIN_24
#endif
#define CONFIG_PROG_CHANNEL 1 // select the porgramming pins (PGEDx & PGECx)
#else
#error "selected PGD1 (23) but not PGC1 (24)"
#endif
#elif PROGRAMM_DAT_CONTROLLER_PIN == 9
#ifdef CONTROLLERPIN_9
#error "double pin configuration!"
#endif
#ifndef PROGRAMM_USE_AS_UART
#define CONTROLLERPIN_9
#endif
#if PROGRAMM_CLK_CONTROLLER_PIN == 10
#ifdef CONTROLLERPIN_10
#error "double pin configuration!"
#endif
#ifndef PROGRAMM_USE_AS_UART
#define CONTROLLERPIN_10
#endif
#define CONFIG_PROG_CHANNEL 2 // select the porgramming pins (PGEDx & PGECx)
#else
#error "selected PGD2 (9) but not PGC2 (10)"
#endif
#elif PROGRAMM_DAT_CONTROLLER_PIN == 45
#ifdef CONTROLLERPIN_45
#error "double pin configuration!"
#endif
#ifndef PROGRAMM_USE_AS_UART
#define CONTROLLERPIN_45
#endif
#if PROGRAMM_CLK_CONTROLLER_PIN == 46
#ifdef CONTROLLERPIN_46
#error "double pin configuration!"
#endif
#ifndef PROGRAMM_USE_AS_UART
#define CONTROLLERPIN_46
#endif
#define CONFIG_PROG_CHANNEL 3 // select the porgramming pins (PGEDx & PGECx)
#else
#error "selected PGD3 (45) but not PGC3 (46)"
#endif
#else
#error "Programm pins not selected"
#endif
#elif defined(__PIC24FJ1024GB610__)
#if PROGRAMM_DAT_CONTROLLER_PIN == 21
#if PROGRAMM_CLK_CONTROLLER_PIN != 20
#error wrong config of PROGRAMM_CLK_CONTROLLER_PIN
#else
#define CONFIG_PROG_CHANNEL 3
#endif
#elif PROGRAMM_DAT_CONTROLLER_PIN == 25
#if PROGRAMM_CLK_CONTROLLER_PIN != 24
#error wrong config of PROGRAMM_CLK_CONTROLLER_PIN
#else
#define CONFIG_PROG_CHANNEL 1
#endif
#elif PROGRAMM_DAT_CONTROLLER_PIN == 27
#if PROGRAMM_CLK_CONTROLLER_PIN != 26
#error wrong config of PROGRAMM_CLK_CONTROLLER_PIN
#else
#define CONFIG_PROG_CHANNEL 2
#endif
#else
#error wrong config of PROGRAMM_DAT_CONTROLLER_PIN
#endif
#endif

// **************************************** UART config **************************************** //

#ifdef PROGRAMM_USE_AS_UART
#define UART_PIC_2_PC_CONTROLLER_PIN PROGRAMM_DAT_CONTROLLER_PIN
#define UART_PC_2_PIC_CONTROLLER_PIN PROGRAMM_CLK_CONTROLLER_PIN
#endif

#define UART_NOT_IN_USE 0   // Dont touch!
#define UART_DEV_FUNCTION 1 // Dont touch!
#define UART_ESP_FUNCTION 2 // Dont touch!

#ifdef DEV_HAS_ESP
#define UART1_FUNCTION_SELECT UART_ESP_FUNCTION
// #define UART1_USE_DMA // enable DMA for UART1
#endif

#ifdef DEV_UART_DEBUG
#define UART2_FUNCTION_SELECT UART_DEV_FUNCTION
// #define UART2_USE_DMA // enable DMA for UART2
#endif

#define UART_ESP_TX_INVERTED false
#define UART_ESP_RX_INVERTED false

#define UART_DEV_TX_INVERTED false
#define UART_DEV_RX_INVERTED false

#ifdef DEV_HAS_ESP
#define UART_RX_ESP_ENABLE
#endif

// **************************************** WRC config **************************************** //

#if DEV_WRC_INPUT > 0 || DEV_EWRC_INPUT > 0
#define UART_RX_WRC_ENABLE
#endif

#if DEV_WRC_INPUT > 0
#define DEV_HAS_WRC
#endif

#endif /* LIBCONFIG_H */
