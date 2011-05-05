#ifndef APM_BMP085_h
#define APM_BMP085_h


class APM_BMP085_Class
{
  private:
    // State machine
    uint8_t BMP085_State;
	// Internal calibration registers
	int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
    uint16_t ac4, ac5, ac6;  
	void Command_ReadPress();
	void Command_ReadTemp();
	void ReadPress();
	void ReadTemp();
	void Calculate();
  public:
	int32_t RawPress;
	int32_t RawTemp;
	int16_t Temp;
	int32_t Press;
	int32_t Pres_zero;
	//int Altitude; // Meters*10
	uint8_t oss;
	//int32_t Press0;  // Pressure at sea level
	long GetAltitude(); // altitude (centimeters)
	long GetASL(); // altitude AboveSeaLevel (centimeters)
	void Calibrate(); // set the relative pressure to zero

	APM_BMP085_Class();  // Constructor
	void Init();
	uint8_t Read();	
};

extern APM_BMP085_Class APM_BMP085;

#endif