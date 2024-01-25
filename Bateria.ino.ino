int transistor = 8;


void setup() {
  pinMode(transistor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(transistor, HIGH);
  delay(1000);
  Serial.println("Battery:");
  Serial.println(analogRead(A0));
  delay(1000);
  digitalWrite(transistor, LOW);
  delay(1000);
}
