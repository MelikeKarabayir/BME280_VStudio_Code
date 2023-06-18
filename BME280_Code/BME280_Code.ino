//KÜTÜPHANELERİ TANIMLA
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BME280.h>
#include "BFC_BME280.h"
unsigned long simdiki_zaman = 0;
unsigned long onceki_zaman = 0;
unsigned long aralik = 500;
int status;

void setup()
{
    Serial.begin(9600);
  
    BFC_Sensor_Init_BME280();
}

void loop()
{
  simdiki_zaman = millis();
  if (simdiki_zaman - onceki_zaman >= aralik)
  { 
    
    BFC_Sensor_Read();
    BFC_Sensor_Print_BME280();
  
    onceki_zaman = simdiki_zaman;
  }
  
}


