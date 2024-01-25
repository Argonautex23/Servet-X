#include <GP2YDustSensor.h>

const uint8_t SHARP_LED_PIN = 7;   // Sharp Dust/particle sensor Led Pin
const uint8_t SHARP_VO_PIN = A0;    // Sharp Dust/particle analog out pin used for reading 

GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1010AU0F, SHARP_LED_PIN, SHARP_VO_PIN);


char polvo;
void setup() {
  Serial.begin(9600);
  dustSensor.setBaseline(0.4); // No establezca voltaje de polvo según sus propios experimentos.
  dustSensor.setCalibrationFactor(1.1); // calibrar contra instrumento de precisión
  dustSensor.begin();
  
}

void loop() {
 sensorpolvo();
 Serial.print (polvo);
 
}

void sensorpolvo() {
  
  Serial.print("Dust density: ");
  Serial.print(dustSensor.getDustDensity());
  int DensidadPolvo = dustSensor.getDustDensity();
  Serial.print(" ug/m3; Running average: ");
  Serial.print(dustSensor.getRunningAverage());
  int RunningAverage = dustSensor.getRunningAverage();
  Serial.println(" ug/m3");
  delay(1000);
  //cambiar delay

  char polvo = DensidadPolvo + RunningAverage;
   
}
