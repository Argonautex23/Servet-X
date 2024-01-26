#include <SPI.h>
#include <LoRa.h>
#include <SD.h>
File myFile;
void setup() {
  Serial.begin(9600);
  while (!Serial); {
;
  }
  Serial.println("LoRa Receiver");

  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
    LoRa.setSpreadingFactor(8);
  }
  Serial.print("Iniciando SD ...");
  if (!SD.begin(4)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
  // open the file. note that only one file can be open at a time,

  // so you have to close this one before opening another.
/*
  myFile = SD.open("test.txt", FILE_WRITE);


  // if the file opened okay, write to it:

  if (myFile) {

    Serial.print("Writing to test.txt...");

    myFile.println("testing 1, 2, 3.");

    // close the file:

    myFile.close();

    Serial.println("done.");

  } else {

    // if the file didn't open, print an error:

    Serial.println("error opening test.txt");

  }*/
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
      myFile = SD.open("datos.txt", FILE_WRITE);
      if (myFile) {
      myFile.println((char)LoRa.read());
      myFile.close(); 
      }
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
