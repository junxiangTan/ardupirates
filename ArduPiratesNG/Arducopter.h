/*
 www.ArduCopter.com - www.DIYDrones.com
 Copyright (c) 2010.  All rights reserved.
 An Open Source Arduino based multicopter.
 
 File     : Arducopter.h
 Version  : v1.0, Aug 27, 2010
 Author(s): ArduCopter Team
             Ted Carancho (aeroquad), Jose Julio, Jordi Muñoz,
             Jani Hirvinen, Ken McEwans, Roberto Navoni,          
             Sandro Benigno, Chris Anderson
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.

* ************************************************************** *
ChangeLog:


* ************************************************************** *
TODO:


* ************************************************************** */

#include "WProgram.h"


/*************************************************************/
// [kidogo] Moved the below settings out of ArduUser.h to here
// since these settings should not be edited by the user
/*************************************************************/


/*************************************************************/
// General definitions
//
// Airframe
#define QUAD 0
#define HELI 1
#define HEXA 2
#define OCTA 3

//Modes
#define FM_ACRO_MODE           0  // DIP3 down (ON)  = Acrobatic Mode
#define FM_STABLE_MODE         1  // DIP3 up   (OFF) = Stable Mode.
#define AP_NORMAL_STABLE_MODE  2  // Just Stable Mode 
#define AP_ALTITUDE_HOLD       3  // Just Altitude Hold
#define AP_GPS_HOLD            4  // Just GPS Hold
#define AP_ALT_GPS_HOLD        5  // Full Automatic (GPS and Altitude Hold)
//#define AP_WAYPOINT            6  // Waypoint Navigation...NOT USED YET

// Radio related definitions
#define CH_ROLL 0
#define CH_PITCH 1
#define CH_THROTTLE 2
#define CH_RUDDER 3
#define CH_1 0
#define CH_2 1
#define CH_3 2
#define CH_4 3
#define CH_5 4
#define CH_6 5
#define CH_7 6
#define CH_8 7
#define CH_9 8    // PL3
#define CH_10 9   // PB5
#define CH_11 10  // PE3

//Axis
#define ROLL 0
#define PITCH 1
#define YAW 2
#define XAXIS 0
#define YAXIS 1
#define ZAXIS 2

#define GYROZ 0
#define GYROX 1
#define GYROY 2
#define ACCELX 3
#define ACCELY 4
#define ACCELZ 5
#define LASTSENSOR 6


/* AM PIN Definitions */
/* Will be moved in future to AN extension ports */
/* due need to have PWM pins free for sonars and servos */

#define FR_LED 3  // Mega PE4 pin, OUT7
#define RE_LED 2  // Mega PE5 pin, OUT6
#define RI_LED 7  // Mega PH4 pin, OUT5
#define LE_LED 8  // Mega PH5 pin, OUT4

/*
#define FR_LED AN12  // Mega PE4 pin, OUT7
#define RE_LED AN14  // Mega PE5 pin, OUT6
#define RI_LED AN10  // Mega PH4 pin, OUT5
#define LE_LED AN8  // Mega PH5 pin, OUT4
*/

/*************************************************************/
// Special patterns for future use

/*
#define POFF  L1\0x00\0x00\0x05
#define PALL  L1\0xFF\0xFF\0x05

#define GPS_AM_PAT1 L\0x00\0x00\0x05
#define GPS_AM_PAT2 L\0xFF\0xFF\0x05
#define GPS_AM_PAT3 L\0xF0\0xF0\0x05
*/

/* AM PIN Definitions - END */

// [kidogo] End of imported settings from ArduUser.h

/* ************************************************************** */
/* APM Hardware definitions */

#define LED_Yellow 36  // A_LED
#define LED_Green 37   // B_LED
#define LED_Red 35     // C_LED

#define A_LED_PIN   LED_Green  // For legacy issues
#define B_LED_PIN   LED_Yellow
#define C_LED_PIN   LED_Red

// Programmable hardware switches/relays 
#define RELAY 47  // Onboard relay (PL2)
#define SW1 41    // Push button close to I2C port (PG0)
#define SW2 40    // Slide switch next to DIP switched (PG1)

// Due limitations of Arduino libraries, these pins needs to be controlled differently so no real PIN numbers
//#define DIP1  (PE7)
//#define DIP2  (PE6) 
//#define DIP3  (PL6)
//#define DIP4  (PL/)

/* ************************************************************** */
/* Expansion PIN's that people can use for various things. */

// AN0 - 7 are located at edge of IMU PCB "above" pressure sensor and Expansion port
// AN0 - 5 are also located next to voltage dividers and sliding SW2 switch
// AN0 - 3 has 10kOhm resistor in serial, include 3.9kOhm to make it as voltage divider
// AN4 - 5 are direct GPIO pins from atmega1280 and they are the latest pins next to SW2 switch
// Look more ArduCopter Wiki for voltage dividers and other ports
#define AN0  54  // resistor, vdiv use, divider 1 closest to relay
#define AN1  55  // resistor, vdiv use, divider 2
#define AN2  56  // resistor, vdiv use, divider 3
#define AN3  57  // resistor, vdiv use, divider 4 closest to SW2
#define AN4  58  // direct GPIO pin, default as analog input, next to SW2 switch
#define AN5  59  // direct GPIO pin, default as analog input, next to SW2 switch
#define AN6  60  // direct GPIO pin, default as analog input, close to Pressure sensor, Expansion Ports
#define AN7  61  // direct GPIO pin, default as analog input, close to Pressure sensor, Expansion Ports

// AN8 - 15 are located at edge of IMU PCB "above" pressure sensor and Expansion port
// AN8 - 15 PINs are not connected anywhere, they are located as last 8 pins on edge of the board above Expansion Ports
// even pins (8,10,12,14) are at edge of board, Odd pins (9,11,13,15) are on inner row
#define AN8  62  // NC
#define AN9  63  // NC
#define AN10  64 // NC
#define AN11  65 // NC
#define AN12  66 // NC
#define AN13  67 // NC
#define AN14  68 // NC
#define AN15  69 // NC

// Defines for Voltage Dividers
#define VDIV1  AN0  // AN0 as default and primary
#define VDIV2  AN1  // AN1 for secondary battery
#define VDIV3  AN2
#define VDIV4  AN3


/* ************************************************** */
#define EE_LAST_LOG_PAGE 0xE00
#define EE_LAST_LOG_NUM 0xE02
#define EE_LOG_1_START 0xE04

/* ************************************************** */
/* Serial port definitions */
#define SERIAL0_BAUD 38400      // this is the main USB out 38400 57600 115200
#define SERIAL1_BAUD 115200
#define SERIAL2_BAUD 115200
#define SERIAL3_BAUD 115200

FastSerialPort0(Serial);		// FTDI/console
FastSerialPort1(Serial1);		// GPS port (except for GPS_PROTOCOL_IMU)
FastSerialPort3(Serial3);		// Telemetry port (optional, Standard and ArduPilot protocols only)


#ifdef SerXbee               // Xbee/Telemetry port 
//#define SerBau  115200      // Baud setting moved close next to port selection
#define SerPri  Serial3.print
#define SerPrln Serial3.println
#define SerPriln Serial3.println
#define SerRea  Serial3.read
#define SerAva  Serial3.available
#define SerRea  Serial3.read
#define SerFlu  Serial3.flush
#define SerBeg  Serial3.begin
#define SerP    Serial3.printf_P
#define SerPor  "FTDI"
#endif

#ifndef SerXbee              // If we don't have SerXbee set, it means we have are using Serial0
//#define SerBau  115200      // Baud setting moved close next to port selection
#define SerPri  Serial.print
#define SerPrln Serial.println
#define SerPriln Serial.println
#define SerRea  Serial.read
#define SerAva  Serial.available
#define SerRea  Serial.read
#define SerFlu  Serial.flush
#define SerBeg  Serial.begin
#define SerP    Serial.printf_P
#define SerPor  "Telemetry"
#endif


/* *********************************************** */
// IMU definitions
// Sensor: GYROX, GYROY, GYROZ, ACCELX, ACCELY, ACCELZ
uint8_t sensors[6] = {1, 2, 0, 4, 5, 6};  // For ArduPilot Mega Sensor Shield Hardware

// Sensor: GYROX, GYROY, GYROZ,   ACCELX, ACCELY, ACCELZ,     MAGX, MAGY, MAGZ
int SENSOR_SIGN[]={
  1, -1, -1,    -1, 1, 1,     -1, -1, -1}; 
 //{-1,1,-1,1,-1,1,-1,-1,-1};
/* APM Hardware definitions, END */

/* *********************************************** */
/* General definitions */
#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0


// ADC : Voltage reference 3.3v / 12bits(4096 steps) => 0.8mV/ADC step
// ADXL335 Sensitivity(from datasheet) => 330mV/g, 0.8mV/ADC step => 330/0.8 = 412
// Tested value : 408
#define GRAVITY 408 //this equivalent to 1G in the raw data coming from the accelerometer 
#define Accel_Scale(x) x*(GRAVITY/9.81)//Scaling the raw data of the accel to actual acceleration in meters for seconds square

#define ROLL_DEF  0      // Level values for roll, used to calculate roll_acc_offset
#define PITCH_DEF 0      // Level values for pitch, used to calculate pitch_acc_offset
#define Z_DEF  GRAVITY   // Stable level value for Z, used to calculate z_acc_offset, same as GRAVITY

#define ToRad(x) (x*0.01745329252)  // *pi/180
#define ToDeg(x) (x*57.2957795131)  // *180/pi

// IDG500 Sensitivity (from datasheet) => 2.0mV/º/s, 0.8mV/ADC step => 0.8/3.33 = 0.4
// Tested values : 
#define Gyro_Gain_X 0.4  //X axis Gyro gain
#define Gyro_Gain_Y 0.4  //Y axis Gyro gain
#define Gyro_Gain_Z 0.4  //Z axis Gyro gain
#define Gyro_Scaled_X(x) x*ToRad(Gyro_Gain_X) //Return the scaled ADC raw data of the gyro in radians for second
#define Gyro_Scaled_Y(x) x*ToRad(Gyro_Gain_Y) //Return the scaled ADC raw data of the gyro in radians for second
#define Gyro_Scaled_Z(x) x*ToRad(Gyro_Gain_Z) //Return the scaled ADC raw data of the gyro in radians for second

/*For debugging purposes*/
#define OUTPUTMODE 1  //If value = 1 will print the corrected data, 0 will print uncorrected data of the gyros (with drift), 2 Accel only data

// Altitude control methods   
#define ALTITUDE_CONTROL_NONE 0   
#define ALTITUDE_CONTROL_BARO 1   
#define ALTITUDE_CONTROL_SONAR 2   
#define SONAR_STATUS_BAD 0   
#define SONAR_STATUS_OK 1 

int AN[6]; //array that store the 6 ADC channels
int AN_OFFSET[6]; //Array that store the Offset of the gyros and accelerometers
int gyro_temp;

float G_Dt=0.02;                  // Integration time for the gyros (DCM algorithm)
float Accel_Vector[3]= {0, 0, 0}; // Store the acceleration in a vector
float Accel_Vector_unfiltered[3]= {0, 0, 0}; // Store the acceleration in a vector
float Gyro_Vector[3]= {0, 0, 0};  // Store the gyros rutn rate in a vector
float Omega_Vector[3]= {0, 0, 0}; // Corrected Gyro_Vector data
float Omega_P[3]= {0, 0, 0};      // Omega Proportional correction
float Omega_I[3]= {0, 0, 0};      // Omega Integrator
float Omega[3]= {0, 0, 0};
//float Accel_magnitude;
//float Accel_weight;

float errorRollPitch[3] = {0, 0, 0};
float errorYaw[3] = {0, 0, 0};
float errorCourse = 0;
float COGX = 0; // Course overground X axis
float COGY = 1; // Course overground Y axis

float roll = 0;
float pitch = 0;
float yaw = 0;

unsigned int counter = 0;

float DCM_Matrix[3][3]= {
  { 1,0,0 },
  { 0,1,0 },
  { 0,0,1 }}; 
  
float Update_Matrix[3][3]={
  { 0,1,2 },
  { 3,4,5 },
  { 6,7,8 }}; //Gyros here

float Temporary_Matrix[3][3]={
  { 0,0,0 },
  { 0,0,0 },
  { 0,0,0 }};

// GPS variables
float speed_3d=0;
int GPS_ground_speed=0;

// Main timers
long timer=0; 
long timer_old;
long GPS_timer;
long GPS_timer_old;
float GPS_Dt=0.2;   // GPS Dt

// Attitude control variables
float command_rx_roll=0;        // User commands
float command_rx_roll_old;
float command_rx_roll_diff;
float command_rx_pitch=0;
float command_rx_pitch_old;
float command_rx_pitch_diff;
float command_rx_yaw=0;
float command_rx_yaw_diff;
int control_roll;           // PID control results
int control_pitch;
int control_yaw;
//float K_aux;


boolean SW_DIP1;  // closest to SW2 slider switch
boolean SW_DIP2;
boolean SW_DIP3;
boolean SW_DIP4;  // closest to header pins

boolean BATTLOW = FALSE;    // We should be always FALSE, if we are TRUE.. it means destruction is close, 
                            // shut down all secondary systems that uses our precious mAh's

// Attitude PID controls
float roll_I=0;
float roll_D;
float err_roll;
float pitch_I=0;
float pitch_D;
float err_pitch;
float yaw_I=0;
float yaw_D;
float err_yaw;
float heading_I=0;  // used only by heli

//Position control
long target_longitude;
long target_latitude;
byte target_position;
float gps_err_roll;
float gps_err_roll_old;
float gps_roll_D;
float gps_roll_I=0;
float gps_err_pitch;
float gps_err_pitch_old;
float gps_pitch_D;
float gps_pitch_I=0;
float command_gps_roll;
float command_gps_pitch;
float gps_err_lat;
float gps_err_lat_old;
float gps_lat_D;
float gps_lat_I=0;
float gps_err_lon;
float gps_err_lon_old;
float gps_lon_D;
float gps_lon_I=0;

// object avoidance
float RF_roll_I=0;
float RF_pitch_I=0;
float RF_throttle_I=0;
float command_RF_roll = 0;
float command_RF_pitch = 0;
float command_RF_throttle = 0;
byte RF_new_data = 0;

//Altitude control variables
int altitude_control_method = ALTITUDE_CONTROL_NONE;  // switch to indicate whether we are using Sonar or Barometer
int initial_throttle;  // the base throttle value used for the control PIDs.  captured when user switched into autopilot
int err_altitude;
int err_altitude_old;
int ch_throttle_altitude_hold;  // throttle value passed to motor_output function

//Barometer Sensor variables
long target_baro_altitude;    // target altitude in cm
long press_baro_altitude  = 0;
byte baro_new_data        = 0;
float baro_altitude_I;
float baro_altitude_D;

// Sonar Sensor variables
int target_sonar_altitude;   // target altitude in cm
long press_sonar_altitude = 0;
int sonar_status = SONAR_STATUS_BAD;  // indicates if sonar values can be trusted
int sonar_valid_count = 0;  // from -5 ~ 5 -ve = number of invalid readings, +ve = number of valid readings (in a row)
long sonar_threshold;  // threshold at which we should transfer control to barometer (normally 80% of sonar's max distance)
byte sonar_new_data = 0;
float sonar_altitude_I;
float sonar_altitude_D;

#define BATTERY_VOLTAGE(x) (x*(INPUT_VOLTAGE/1024.0))*VOLT_DIV_RATIO

#define AIRSPEED_PIN 1		// Need to correct value
#define BATTERY_PIN 1		// Need to correct value
#define RELAY_PIN 47

float 	battery_voltage 	= LOW_VOLTAGE * 1.05;		// Battery Voltage, initialized above threshold for filter

//AP_NORMAL_STABLE_MODE  2  // Just Stable Mode 
//AP_ALTITUDE_HOLD       3  // Just Altitude Hold
//AP_GPS_HOLD            4  // Just GPS Hold
//AP_ALT_GPS_HOLD        5  // Full Automatic (GPS and Altitude Hold)
//AP_WAYPOINT            6  // NOT IN USE

byte AP_mode = 2;  //Default Normal Stable Mode.
//byte cam_mode = 0;  // moved to general settings, 31-10-10, jp

//  PID Tuning - Enjin
byte Pitch_Roll_PID = 1;
byte Yaw_PID = 0;
byte Baro_PID = 0;
byte Sonar_PID = 0;
byte GPS_PID = 0;
byte ACC_offset_x_adj = 0;
byte ACC_offset_y_adj = 0;
byte P_PID = 1;
byte I_PID = 0;
byte D_PID = 0;
byte ON_PID = 0;
byte Plus = 0;
byte Minus = 0;
byte Camera_Smooth_Roll_adj = 0;
byte Camera_Smooth_Pitch_adj = 0;
byte Camera_Roll_Centre_adj = 0;
byte Camera_Focus_adj = 0;
byte Camera_Trigger_adj = 0;
byte Camera_Release_adj = 0;

// Camera Trigger
int Focus_counter = 0;
int Trigger_counter = 0;
int PictureCapture_counter = 0;
byte Focus_status = 1;
byte Trigger_status = 0;
byte PictureCapture_status = 0;


// Mode LED timers and variables, used to blink LED_Green
byte gled_status = HIGH;
long gled_timer;
int gled_speed;

long cli_timer;
byte cli_status = LOW;
byte cli_step;

long  t0;
int   num_iter;
float aux_debug;

// Radio definitions
int   roll_mid;
int   pitch_mid;
int   yaw_mid;

int   Neutro_yaw;
int   ch_roll;
int   ch_pitch;
int   ch_throttle;
int   ch_yaw;
int   ch_aux;
int   ch_aux2;
int   ch_flightmode;

// Quad motors
int frontMotor;
int backMotor;
int leftMotor;
int rightMotor;

// Hexa motors
int LeftCWMotor;
int LeftCCWMotor;
int RightCWMotor;
int RightCCWMotor;
int FrontCWMotor;
int BackCCWMotor;

// Octa Motors   
int Front_MotorCW;
int Front_Right_MotorCCW;
int Right_MotorCW;
int Back_Right_MotorCCW;
int Back_MotorCW;
int Back_Left_MotorCCW;
int Left_MotorCW;  
int Front_Left_MotorCCW;

byte  motorArmed = 0;                              // 0 = motors disarmed, 1 = motors armed
byte  motorSafety = 1;                             // 0 = safety off, 1 = on.  When On, sudden increases in throttle not allowed
int   minThrottle = 0;
byte  safetyOff = 0;                              // During normal Flight, the motor Safety feature is switched off.
boolean flightOrientation = 0;                    // 0 = +, 1 = x this is read from DIP1 switch during system bootup

// Serial communication
char   queryType;
long   tlmTimer = 0;

// Arming/Disarming
uint8_t Arming_counter=0;
uint8_t Disarming_counter=0;
uint8_t Safety_counter=0;

// Performance monitoring
// ----------------------
long 	perf_mon_timer 				= 0;
float 	imu_health 				= 0;		//Metric based on accel gain deweighting
int 	G_Dt_max 				= 0;		//Max main loop cycle time in milliseconds
byte 	gyro_sat_count 				= 0;
byte 	adc_constraints 			= 0;
byte 	renorm_sqrt_count 			= 0;
byte 	renorm_blowup_count 		        = 0;
int 	gps_fix_count				= 0;
byte	gcs_messages_sent			= 0;

// System Timers
// --------------
unsigned long fast_loopTimer		        = 0;		// Time in miliseconds of main control loop
unsigned long medium_loopTimer		        = 0;		// Time in miliseconds of navigation control loop
byte   medium_loopCounter			= 0;		// Counters for branching from main control loop to slower loops
byte   slow_loopCounter				= 0;		// 
unsigned long deltaMiliSeconds 		        = 0;		// Delta Time in miliseconds
unsigned long dTnav				= 0;		// Delta Time in milliseconds for navigation computations
int   mainLoop_count 				= 0;
unsigned long elapsedTime			= 0;		// for doing custom events
//unsigned int GPS_timer			= 0;


								
/* ******************************************************** */
/* Logging Stuff	- These should be 1 (on) or 0 (off) */
//only GPS, SEN, RANGEFINDER, PID, and RADIO are currently available

#define LOG_ATTITUDE 0	        // Logs basic attitude info
#define LOG_GPS 1		// Logs GPS info
#define LOG_PM 0		// Logs IMU performance monitoring info£
#define LOG_CTUN 0		// Logs control loop tuning info
#define LOG_NTUN 0		// Logs navigation loop tuning info
#define LOG_MODE 0		// Logs mode changes
#define LOG_RAW 0		// Logs raw accel/gyro data
#define LOG_SEN 1               // Logs sensor data
#define LOG_RANGEFINDER 1       // Logs data from range finders
#define LOG_PID 1               // Logs navigation loop PID values (GPS, Altitude)
#define LOG_RADIO 1             // Logs radio values

//  GCS Message ID's
#define MSG_ACKNOWLEDGE 0x00
#define MSG_HEARTBEAT 0x01
#define MSG_ATTITUDE 0x02
#define MSG_LOCATION 0x03
#define MSG_PRESSURE 0x04
#define MSG_STATUS_TEXT 0x05
#define MSG_PERF_REPORT 0x06
#define MSG_COMMAND 0x22
#define MSG_VALUE 0x32
#define MSG_PID 0x42
#define MSG_TRIMS 0x50
#define MSG_MINS 0x51
#define MSG_MAXS 0x52
#define MSG_IMU_OUT 0x53

#define SEVERITY_LOW 1
#define SEVERITY_MEDIUM 2
#define SEVERITY_HIGH 3
#define SEVERITY_CRITICAL 4

// Debug options - set only one of these options to 1 at a time, set the others to 0
#define DEBUG_SUBSYSTEM 0 		// 0 = no debug
					// 1 = Debug the Radio input
					// 2 = Debug the Servo output
					// 3 = Debug the Sensor input
					// 4 = Debug the GPS input
					// 5 = Debug the GPS input - RAW HEX OUTPUT
					// 6 = Debug the IMU
					// 7 = Debug the Control Switch
					// 8 = Debug the Servo DIP switches
					// 9 = Debug the Relay out
					// 10 = Debug the Magnetometer
					// 11 = Debug the ABS pressure sensor
					// 12 = Debug the stored waypoints
					// 13 = Debug the Throttle
					// 14 = Debug the Radio Min Max
					// 15 = Debug the EEPROM - Hex Dump
								

#define DEBUG_LEVEL SEVERITY_LOW
					// SEVERITY_LOW
					// SEVERITY_MEDIUM
					// SEVERITY_HIGH
					// SEVERITY_CRITICAL



// Radio Modes, mainly just Mode2 
#define MODE1           1 
#define MODE2           2
#define MODE3           3
#define MODE4           4

// Frame models
#define QUAD            0            // Normal Quad 
#define QUADCOAX        1            // Quad with double motors as coax
#define HEXA            2            // Hexa
#define HEXARADIAL      3
#define HEXACOAX        4
#define OCTO            5

#define PWM             0
#define I2C             1
#define UART            2



// Following variables stored in EEPROM
float KP_QUAD_ROLL;
float KI_QUAD_ROLL;
float STABLE_MODE_KP_RATE_ROLL;
float KP_QUAD_PITCH;
float KI_QUAD_PITCH;
float STABLE_MODE_KP_RATE_PITCH;
float KP_QUAD_YAW;
float KI_QUAD_YAW;
float STABLE_MODE_KP_RATE_YAW;
float STABLE_MODE_KP_RATE;       //NOT USED NOW
float KP_GPS_ROLL;
float KI_GPS_ROLL;
float KD_GPS_ROLL;
float KP_GPS_PITCH;
float KI_GPS_PITCH;
float KD_GPS_PITCH;
float GPS_MAX_ANGLE;
float KP_ALTITUDE;
float KI_ALTITUDE;
float KD_ALTITUDE;
int acc_offset_x;
int acc_offset_y;
int acc_offset_z;
int gyro_offset_roll;
int gyro_offset_pitch;
int gyro_offset_yaw;
float Kp_ROLLPITCH;
float Ki_ROLLPITCH;
float Kp_YAW;
float Ki_YAW;
float GEOG_CORRECTION_FACTOR=0;
int MAGNETOMETER;
float Kp_RateRoll;
float Ki_RateRoll;
float Kd_RateRoll;
float Kp_RatePitch;
float Ki_RatePitch;
float Kd_RatePitch;
float Kp_RateYaw;
float Ki_RateYaw;
float Kd_RateYaw;
float xmitFactor;
float ch_roll_slope          = 1;
float ch_pitch_slope         = 1;
float ch_throttle_slope      = 1;
float ch_yaw_slope           = 1;
float ch_aux_slope           = 1;
float ch_aux2_slope          = 1;
float ch_roll_offset         = 0;
float ch_pitch_offset        = 0;
float ch_throttle_offset     = 0;
float ch_yaw_offset          = 0;
float ch_aux_offset          = 0;
float ch_aux2_offset         = 0;
byte cam_mode                = 0;
byte mag_orientation         = 0;    // mag variables, reserved for future use, 31-10-10, jp
float mag_declination        = 0.0;  
float mag_offset_x           = 0;    // is int enough for offsets.. checkit, 31-10-10, jp
float mag_offset_y           = 0;
float mag_offset_z           = 0;
int MIN_THROTTLE;
//float eeprom_counter;                // reserved for eeprom write counter, 31-10-10, jp
//float eeprom_checker;                // reserved for eeprom checksums, 01-11-10, jp

// obstacle avoidance
float KP_RF_ROLL;
float KD_RF_ROLL;
float KI_RF_ROLL;
float KP_RF_PITCH;
float KD_RF_PITCH;
float KI_RF_PITCH;
float RF_MAX_ANGLE;    // Maximun command roll and pitch angle from obstacle avoiding control
float RF_SAFETY_ZONE;  // object avoidance will move away from objects within this distance (in cm)

// sonar for altitude hold
float KP_SONAR_ALTITUDE;
float KI_SONAR_ALTITUDE;
float KD_SONAR_ALTITUDE;

// Camera related settings

int CAM_SMOOTHING;      // Camera movement smoothing on pitch axis
int CAM_SMOOTHING_ROLL; // Camera movement smoothing on roll axis
int CAM_CENT;           // Camera center
int CAM_FOCUS;          // Camera trigger Servo Focus position
int CAM_TRIGGER;        // Camera trigger Servo Trigger position 
int CAM_RELEASE;        // Camera trigger Servo Release Trigger Button position

// This function call contains the default values that are set to the ArduCopter
// when a "Default EEPROM Value" command is sent through serial interface
void defaultUserConfig() {
  KP_QUAD_ROLL               = 4.0;
  KI_QUAD_ROLL               = 0.15;
  STABLE_MODE_KP_RATE_ROLL   = 1.2;
  KP_QUAD_PITCH              = 4.0;
  KI_QUAD_PITCH              = 0.15;
  STABLE_MODE_KP_RATE_PITCH  = 1.2;
  KP_QUAD_YAW                = 3.0;
  KI_QUAD_YAW                = 0.15;
  STABLE_MODE_KP_RATE_YAW    = 2.4;
  STABLE_MODE_KP_RATE        = 0.2;     // NOT USED NOW
  KP_GPS_ROLL                = 0.012;   //0.013;
  KI_GPS_ROLL                = 0.001;   //0.005;
  KD_GPS_ROLL                = 0.015;   //0.012;
  KP_GPS_PITCH               = 0.010;   //0.013;
  KI_GPS_PITCH               = 0.001;   //0.005;
  KD_GPS_PITCH               = 0.015;   //0.01;
  GPS_MAX_ANGLE              = 22;
  KP_ALTITUDE                = 0.08;
  KI_ALTITUDE                = 0.05;
  KD_ALTITUDE                = 0.06;
  acc_offset_x               = 2048;
  acc_offset_y               = 2048;
  acc_offset_z               = 2048;
  gyro_offset_roll           = 1659;
  gyro_offset_pitch          = 1650;
  gyro_offset_yaw            = 1650;
  Kp_ROLLPITCH               = 0.0014;
  Ki_ROLLPITCH               = 0.00000015;
  Kp_YAW                     = 1.0;
  Ki_YAW                     = 0.00002;
  GEOG_CORRECTION_FACTOR     = 0.0;      // will be automatically calculated
  MAGNETOMETER               = 0;
  Kp_RateRoll                = 1.95;
  Ki_RateRoll                = 0.0;
  Kd_RateRoll                = 0.0;
  Kp_RatePitch               = 1.95;
  Ki_RatePitch               = 0.0;
  Kd_RatePitch               = 0.0;  
  Kp_RateYaw                 = 3.2;
  Ki_RateYaw                 = 0.0;
  Kd_RateYaw                 = 0.0;
  xmitFactor                 = 0.32;
  roll_mid                   = 1500;
  pitch_mid                  = 1500;
  yaw_mid                    = 1500;
  ch_roll_slope              = 1;
  ch_pitch_slope             = 1;
  ch_throttle_slope          = 1;
  ch_yaw_slope               = 1;
  ch_aux_slope               = 1;
  ch_aux2_slope              = 1;
  ch_roll_offset             = 0;
  ch_pitch_offset            = 0;
  ch_throttle_offset         = 0;
  ch_yaw_offset              = 0;
  ch_aux_offset              = 0;
  ch_aux2_offset             = 0;
  cam_mode                   = 0;
  mag_orientation            = 0;  // reserved for future, 31-10-10, jp
  mag_declination            = 0.0;
  mag_offset_x               = 0;
  mag_offset_y               = 0;
  mag_offset_z               = 0;
  MIN_THROTTLE               = 1040; // used to be #define but now in EEPROM
  KP_RF_ROLL                 = 0.10;
  KI_RF_ROLL                 = 0.00;
  KD_RF_ROLL                 = 0.03;
  KP_RF_PITCH                = 0.10;
  KI_RF_PITCH                = 0.00;  
  KD_RF_PITCH                = 0.03;
  RF_MAX_ANGLE               = 10.0;
  RF_SAFETY_ZONE             = 120.0;  // object avoidance will avoid objects within this range (in cm)
  KP_SONAR_ALTITUDE          = 0.8;
  KI_SONAR_ALTITUDE          = 0.3;
  KD_SONAR_ALTITUDE          = 0.7;
  CAM_SMOOTHING              = 1000;   // Camera movement smoothing on pitch axis
  CAM_SMOOTHING_ROLL         = 1140;   // Camera movement smoothing on roll axis
  CAM_CENT                   = 1570;   // Camera center
  CAM_FOCUS                  = 1710;   // Camera trigger Servo Focus position
  CAM_TRIGGER                = 1780;   // Camera trigger Servo Trigger position 
  CAM_RELEASE                = 1500;   // Camera trigger Servo Release position
}

// EEPROM storage addresses
#define KP_QUAD_ROLL_ADR       0
#define KI_QUAD_ROLL_ADR       8
#define STABLE_MODE_KP_RATE_ROLL_ADR 4
#define KP_QUAD_PITCH_ADR      12
#define KI_QUAD_PITCH_ADR      20
#define STABLE_MODE_KP_RATE_PITCH_ADR 16
#define KP_QUAD_YAW_ADR        24
#define KI_QUAD_YAW_ADR        32
#define STABLE_MODE_KP_RATE_YAW_ADR 28
#define STABLE_MODE_KP_RATE_ADR 36      // NOT USED NOW
#define KP_GPS_ROLL_ADR        40
#define KI_GPS_ROLL_ADR        48
#define KD_GPS_ROLL_ADR        44
#define KP_GPS_PITCH_ADR       52
#define KI_GPS_PITCH_ADR       60
#define KD_GPS_PITCH_ADR       56
#define GPS_MAX_ANGLE_ADR      64
#define KP_ALTITUDE_ADR        68
#define KI_ALTITUDE_ADR        76
#define KD_ALTITUDE_ADR        72
#define acc_offset_x_ADR       80
#define acc_offset_y_ADR       84
#define acc_offset_z_ADR       88
#define gyro_offset_roll_ADR   92
#define gyro_offset_pitch_ADR  96
#define gyro_offset_yaw_ADR    100
#define Kp_ROLLPITCH_ADR       104
#define Ki_ROLLPITCH_ADR       108
#define Kp_YAW_ADR             112
#define Ki_YAW_ADR             116
#define GEOG_CORRECTION_FACTOR_ADR 120
#define MAGNETOMETER_ADR       124
#define XMITFACTOR_ADR         128
#define KP_RATEROLL_ADR        132
#define KI_RATEROLL_ADR        136
#define KD_RATEROLL_ADR        140
#define KP_RATEPITCH_ADR       144
#define KI_RATEPITCH_ADR       148
#define KD_RATEPITCH_ADR       152
#define KP_RATEYAW_ADR         156
#define KI_RATEYAW_ADR         160
#define KD_RATEYAW_ADR         164
#define CHROLL_MID             168
#define CHPITCH_MID            172
#define CHYAW_MID              176
#define ch_roll_slope_ADR      180
#define ch_pitch_slope_ADR     184
#define ch_throttle_slope_ADR  188
#define ch_yaw_slope_ADR       192
#define ch_aux_slope_ADR       196
#define ch_aux2_slope_ADR      200
#define ch_roll_offset_ADR     204
#define ch_pitch_offset_ADR    208
#define ch_throttle_offset_ADR 212
#define ch_yaw_offset_ADR      216
#define ch_aux_offset_ADR      220
#define ch_aux2_offset_ADR     224
#define cam_mode_ADR           228
#define mag_orientation_ADR    232  // reserved for future, 31-10-10, jp
#define mag_declination_ADR    236  // reserved for future, 31-10-10, jp
#define mag_offset_x_ADR       240
#define mag_offset_y_ADR       244
#define mag_offset_z_ADR       248
#define MIN_THROTTLE_ADR       252
#define KP_RF_ROLL_ADR         256
#define KI_RF_ROLL_ADR         260
#define KD_RF_ROLL_ADR         264
#define KP_RF_PITCH_ADR        268
#define KI_RF_PITCH_ADR        272
#define KD_RF_PITCH_ADR        276
#define RF_MAX_ANGLE_ADR       280
#define RF_SAFETY_ZONE_ADR     284
#define KP_SONAR_ALTITUDE_ADR  288
#define KI_SONAR_ALTITUDE_ADR  292
#define KD_SONAR_ALTITUDE_ADR  296
#define CAM_SMOOTHING_ADR      300   // Camera movement smoothing on pitch axis
#define CAM_SMOOTHING_ROLL_ADR 304   // Camera movement smoothing on roll axis
#define CAM_CENT_ADR           308   // Camera center
#define CAM_FOCUS_ADR          312   // Camera trigger Servo Focus position
#define CAM_TRIGGER_ADR        316   // Camera trigger Servo Trigger position 
#define CAM_RELEASE_ADR        320   // Camera trigger Servo Release position

//#define eeprom_counter_ADR     238  // hmm should i move these?!? , 31-10-10, jp
//#define eeprom_checker_ADR     240  // this too... , 31-10-10, jp



// end of file
