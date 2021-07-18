//www.elegoo.com
//2016.12.08
#include <Servo.h>

Servo myservo;

Servo fl0;
Servo fl1;
Servo fl2;
Servo fr0;
Servo fr1;
Servo fr2;
Servo br1;
Servo br0;
Servo br2;
Servo bl1;
Servo bl0;
Servo bl2;
// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int data;
void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the servo object

  fl0.attach(23);
  fl1.attach(25);
  fl2.attach(26);
  fr0.attach(29);
  fr1.attach(31);
  fr2.attach(33);
  br1.attach(35);
  br0.attach(37);
  br2.attach(39);
  bl1.attach(41);
  bl0.attach(43);
  bl2.attach(45);
  Serial.begin(9600);
}

void loop() {
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'

      fl0.write(pos);
      fl1.write(pos);
      fl2.write(pos);
      fr0.write(pos);
      fr1.write(pos);
      fr2.write(pos);
      br0.write(pos);
      br1.write(pos);
      br2.write(pos);
      bl0.write(pos);
      bl1.write(pos);
      bl2.write(pos);
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'

      fl0.write(pos);
      fl1.write(pos);
      fl2.write(pos);
      fr0.write(pos);
      fr1.write(pos);
      fr2.write(pos);
      br0.write(pos);
      br1.write(pos);
      br2.write(pos);
      bl0.write(pos);
      bl1.write(pos);
      bl2.write(pos);
    delay(5);                       // waits 15ms for the servo to reach the position
  } 
  /*
  data = Serial.parseInt();
  myservo.write(data);
  Serial.println(data);
  */
}
