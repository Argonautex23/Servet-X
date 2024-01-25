
#include <DFRobot_Geiger.h>
#if defined ESP32
#define detect_pin D3
#else
#define detect_pin 3
#endif

DFRobot_Geiger  geiger(detect_pin);
void setup(){
   Serial.begin(115200);
   geiger.start();
	
}

void loop(){ 
  delay(3000);
  Serial.println(geiger.getCPM());
  //1 cifra entera
  Serial.println(geiger.getnSvh());
 //2 cifras enteras
  Serial.println(geiger.getuSvh());
  //0.00 2 cifras decimales
}
