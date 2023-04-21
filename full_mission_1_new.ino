int sideNumber = 1;
double positionX;
double positionY;
double positionZ;

void goOneMeter() {
  EmoroServo.write (SERVO_0,1970);
  EmoroServo.write (SERVO_1,1000); 
  delay (7000);
}

void goHalfMeter() {
  EmoroServo.write (SERVO_0,1970);
  EmoroServo.write (SERVO_1,1000); 
  delay (3500);
}

void turnLeft(double zStart) {
  double zCurrent;
  double deltaZ = 0;
  EmoroServo.write (SERVO_0,1500); 
  EmoroServo.write (SERVO_1,1300);// Right turn/First turn
  while (deltaZ < 90){
    zCurrent = Gyr.readDegreesZ();
    deltaZ = zCurrent - zStart;
  }
  EmoroServo.write (SERVO_1,1500);// Right turn/First turn
}

void setup() {
  Serial.begin(9600);
  Gyr.init();
  EmoroServo.attach(SERVO_0);
  EmoroServo.attach(SERVO_1);
}

void loop() {
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

  if ( (sideNumber % 2) == 0){
    goOneMeter();
  }
  else {
    goHalfMeter();
  }
  turnLeft(positionZ);
  sideNumber = sideNumber + 1;
  if (sideNumber ==5){
  }
}
