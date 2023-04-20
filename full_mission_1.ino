double positionX;
double positionY;
double positionZ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Gyr.init();
  EmoroServo.attach(SERVO_0);
  EmoroServo.attach(SERVO_1);
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

   
  EmoroServo.write (SERVO_0,1970);
  EmoroServo.write (SERVO_1,1000); 

  double Zstart =Gyr.readDegreesZ(); //Save last Z value afther 7sec
  delay (7000);
  
  double Zcurrent =Gyr.readDegreesZ();
  double deltaZ = Zcurrent - Zstart;
                                      //First Forward
    while (deltaZ < 90){
      
      Zcurrent =Gyr.readDegreesZ(); // read Z from gyro
      deltaZ = Zcurrent - Zstart;   // calculate dZ
    
       EmoroServo.write (SERVO_0,1500);
       EmoroServo.write (SERVO_1,1300);// Right turn/First turn
  }
    
    while (deltaZ >90){
      Zcurrent =Gyr.readDegreesZ(); // read Z from gyro
      deltaZ = Zcurrent - Zstart;   // calculate dZ
      EmoroServo.write (SERVO_0,1700);
      EmoroServo.write (SERVO_1,1500);// Fix from left/First fix
    }
EmoroServo.write (SERVO_0,1970);
EmoroServo.write (SERVO_1,1000);
delay (3500);
   Zstart =Gyr.readDegreesZ(); //Save last Z value afther 7sec
   Zcurrent =Gyr.readDegreesZ();
   deltaZ = Zcurrent - Zstart;
    while (deltaZ < 90){
       Zcurrent =Gyr.readDegreesZ(); // read Z from gyro
       deltaZ = Zcurrent - Zstart;   // calculate dZ
       EmoroServo.write (SERVO_0,1500);
       EmoroServo.write (SERVO_1,1300);
    }
    while (deltaZ >90){
      Zcurrent =Gyr.readDegreesZ(); // read Z from gyro
      deltaZ = Zcurrent - Zstart;   // calculate dZ
      EmoroServo.write (SERVO_0,1700);
      EmoroServo.write (SERVO_1,1500);// Fix from left

    }
    }
