void setup() {
  Serial.begin(115200);
  volt = 0;
  current = 0;
}

void loop() {
  volt analogRead(32);
  volt = map(volt,0,4095,0,73.8);
  Serial.println(analogRead(32));
  
}
