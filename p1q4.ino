double positionX;
double positionY;
double positionZ;
void setup() {
  // put your setup code here, to run once:
  InitEmoro();
  ReadEmoroHardware();
  Serial.begin(9600);
  Gyr.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  positionX = Gyr.readDegreesX();
  positionY = Gyr.readDegreesY();
  positionZ = Gyr.readDegreesZ();
  char buf[64];
  Lcd.locate(0, 0);
  sprintf(buf,"X    Y    Z");
  Lcd.print(buf);
  sprintf(buf,"%3d %3d %3d",(int)positionX,(int)positionY,(int)positionZ);
  Lcd.locate(1, 0);
 Lcd.print(buf);
}
