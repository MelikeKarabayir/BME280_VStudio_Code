//SENSOR SABITLERI
#define SEALEVELPRESSURE_HPA (926.5) // Test videosu için değiştirildi.Yaklaşık 1023.4 olmalı.
//#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
float payload_bir,basinc,sicaklik,nem,irtifa;
//KÜTÜPHANENİN KULLANILACAĞI DEĞİŞKEN TANIMLAMA
Adafruit_BME280 bme280;
void BFC_Sensor_Init_BME280(void)
{
	if (!bme280.begin(0x77)) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}
}

void BFC_Sensor_Read(void)
{
	 sicaklik = bme280.readTemperature();
	 nem = bme280.readHumidity();
	 basinc = bme280.readPressure() / 100.0F;
	 irtifa = bme280.readAltitude(SEALEVELPRESSURE_HPA);
}
void BFC_Sensor_Print_BME280(void)
{ 	
	Serial.print("P1, ");
	Serial.print(sicaklik);
	Serial.print(",");
	Serial.print(nem);
	Serial.print(",");
	Serial.print(basinc);
	Serial.print(",");
	Serial.println(irtifa);
}

