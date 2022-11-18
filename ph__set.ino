
/*

 //  선 단락 (P0 - Gnd 연결)후    P0값 = 2.5V 조절 (   
 
#include <Arduino.h>

const int adcPin = A0;
void setup() {
Serial.begin(9600);
}


void loop() {
int adcValue = analogRead(adcPin);
float phVoltage = (float)adcValue * 5.0 / 1024;
Serial.print("ADC = "); Serial.print(adcValue);
Serial.print("; Po = "); Serial.println(phVoltage, 3);
delay(1000);
}
*/


// PH meter 측정

#include <Arduino.h>
const int adcPin = A0;
// calculate your own m using ph_calibrate.ino
// When using the buffer solution of pH4 for calibration, m can be derived as:
// m = (pH7 - pH4) / (Vph7 - Vph4)
const float m = -5.243;                // 보정값 입력 
void setup() {
Serial.begin(9600);
}

void loop() {
float Po = analogRead(adcPin) * 5.0 / 1024;
float phValue = 7 - (2.5 - Po) * m;
Serial.print("ph value = "); Serial.println(phValue);
delay(500);
}



