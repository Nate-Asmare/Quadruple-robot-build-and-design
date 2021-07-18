#include <Servo.h>
//for ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;

long duration;
int distance;

int fromAndroid;
int temp = 0;
int motion = 0; // A variable to hold in wich mothion state the robot is in
                //by default the motion is forward
                // 0 Forward
                // 1 Backward
                // 2 Rotate Right
                // 3 Rotate Left
int sentHeightForward = 13; //by default the height is set to 13
int sentDelayForward = 8, sentResolutionForward = 10, sentStepDistanceLeftForward = 3, sentStepDistanceRightForward = 3, sentLegLiftForward = 1;
int sentHeightBackward = 13; //by default the height is set to 12
int sentDelayBackward = 8, sentResolutionBackward = 10, sentStepDistanceLeftBackward = 3, sentStepDistanceRightBackward = 3, sentLegLiftBackward = 1;
int sentAngleLeft = 10, sentDelayLeft = 5, sentResolutionLeft = 14, sentHeightLeft = 11, sentLegLiftLeft = 1;
int sentAngleRight = 10, sentDelayRight = 5, sentResolutionRight = 14, sentHeightRight = 11, sentLegLiftRight = 1;

Servo frontRightLeg0;
Servo frontRightLeg1;
Servo frontRightLeg2;
Servo frontLeftLeg0;
Servo frontLeftLeg1;
Servo frontLeftLeg2;
Servo backLeftLeg0;
Servo backLeftLeg1;
Servo backLeftLeg2;
Servo backRightLeg0;
Servo backRightLeg1;
Servo backRightLeg2;
Servo armBody;
Servo armShoulder;
Servo armElbow;
Servo endEffector;

//this double variables will be used to hold the angle values for the servo motors
//by default this values are set so that the robot will be in standing position default hight (10cm form elbow joint to ground)/

  const double frontRightLeg0ValD = 90;
  const double frontRightLeg1ValD = 90;
  const double frontRightLeg2ValD = 90;
  const double frontLeftLeg0ValD = 90;
  const double frontLeftLeg1ValD = 90;
  const double frontLeftLeg2ValD = 90;
  const double backLeftLeg0ValD = 90;
  const double backLeftLeg1ValD = 90;
  const double backLeftLeg2ValD = 90;
  const double backRightLeg0ValD = 90;
  const double backRightLeg1ValD = 90;
  const double backRightLeg2ValD = 90;
  const double armBodyValD = 90;
  const double armShoulderValD = 35;
  const double armElbowValD = 90;
  const double endEffectorValD = 180;
  
  double frontRightLeg0Val = frontRightLeg0ValD;
  double frontRightLeg1Val = frontRightLeg1ValD;
  double frontRightLeg2Val = frontRightLeg2ValD;
  double frontLeftLeg0Val = frontLeftLeg0ValD;
  double frontLeftLeg1Val = frontLeftLeg1ValD;
  double frontLeftLeg2Val = frontLeftLeg2ValD;
  double backLeftLeg0Val = backLeftLeg0ValD;
  double backLeftLeg1Val = backLeftLeg1ValD;
  double backLeftLeg2Val = backLeftLeg2ValD;
  double backRightLeg0Val = backRightLeg0ValD;
  double backRightLeg1Val = backRightLeg1ValD;
  double backRightLeg2Val = backRightLeg2ValD;
  double armBodyVal = armBodyValD;
  double armShoulderVal = armShoulderValD;
  double armElbowVal = armElbowValD;
  double endEffectorVal = endEffectorValD;

//variables to hold angle values from inverse kinematics 
  double theta1 = 0;
  double theta2 = 0;
  double theta3 = 0;
  double psi1 = 0;
  double psi2 = 0;
  double psi3 = 0;
  double psi4 = 0;

//Variables to hold the dimention of the leg or arm
  double a1 = 0;
  double a2 = 0;
  double a3 = 0; 

//variables to hold x,y,z cordenates for the arm
  double x = 2;
  double y = 0;
  double z = 9.5;

  double delayerArm = 0.25;

//variables to hold the foot print on surface dimentions (this are approximate values), refer the documentation to learn more
  double w = 23; // distance between the front leg foot print and back leg foot print
  double l = 15; // distance between the front legs or back legs

//variables for setTurn method
double q, p, alpha, r, psi;
double beta1Left, beta3Left, beta4Left, beta2Left, y1Left, z1Left, y2Left, z2Left, y3Left, z3Left, y4Left, z4Left;
double beta1Right, beta3Right, beta4Right, beta2Right, y1Right, z1Right, y2Right, z2Right, y3Right, z3Right, y4Right, z4Right;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600);
  // put your setup code here, to run once:
  attachAll();
  
  setTurn(10); //default turning angle is 10degrees
}

  
void loop() {
  //Serial.println(eco());
//  armBody.write(90);
//  armShoulder.write(15);
//  armElbow.write(90);

//    arm(5,0,0);
//    writer();
//
//    Serial.println(theta1);
//    Serial.println(theta2);
//    Serial.println(theta3);
    
// walk(8,3,3,12,3);

    backRight(12,4,1.8);
    backLeft(12,4,0);
    frontLeft(12,4,0);
    frontRight(12,4,0);
    //writer();

  if(Serial.available() > 0 || temp > 0)
  {
    delay(50); //this delay is for blutooth checking
    fromAndroid = Serial.read();
     
    if(fromAndroid > 0)
      temp = fromAndroid;
      
    backRight(12,0,0);
    backLeft(12,0,0);
    frontLeft(12,0,0);
    frontRight(12,0,0);
     
    if(temp>=20 && temp<26 && motion == 0){
      sentHeightForward = temp - 12;
      temp = 17; //17 is just a roundom number hat is not used in the code
    }else if(temp>86 && temp<115 && motion == 0){
      sentDelayForward = temp - 85;
      temp = 17;
    }else if(temp>=56 && temp<86 && motion == 0){
      sentResolutionForward = temp - 55;
      temp = 17;
    }else if(temp>=36 && temp<46 && motion == 0){
      sentStepDistanceLeftForward = temp - 35;
      temp = 17;
    }else if(temp>=46 && temp<56 && motion == 0){
      sentStepDistanceRightForward = temp - 45;
      temp = 17;
    }else if(temp>=26 && temp<36 && motion == 0){
      sentLegLiftForward = temp - 25;
      temp = 17;
    }else if(temp>=20 && temp<26 && motion == 1){
      sentHeightBackward = temp - 12;
      temp = 17;
    }else if(temp>86 && temp<115 && motion == 1){
      sentDelayBackward = temp - 85;
      temp = 17;
    }else if(temp>=56 && temp<86 && motion == 1){
      sentResolutionBackward = temp - 55;
      temp = 17;
    }else if(temp>=36 && temp<46 && motion == 1){
      sentStepDistanceLeftBackward = temp - 35;
      temp = 17;
    }else if(temp>=46 && temp<56 && motion == 1){
      sentStepDistanceRightBackward = temp - 45;
      temp = 17;
    }else if(temp>=26 && temp<36 && motion == 1){
      sentLegLiftBackward = temp - 25;
      temp = 17;
    }else if(temp>=20 && temp<26 && motion == 2){
      sentHeightRight = temp - 12;
      temp = 17;
    }else if(temp>86 && temp<115 && motion == 2){
      sentDelayRight = temp - 85;
      temp = 17;
    }else if(temp>=56 && temp<86 && motion == 2){
      sentResolutionRight = temp - 55;
      temp = 17;
    }else if(temp>=26 && temp<36 && motion == 2){
      sentLegLiftRight = temp - 25;
      temp = 17;
    }else if(temp>=125 && temp<144){
      sentAngleRight = temp - 124;
      setTurn(sentAngleRight);
      temp = 17;
    }else if(temp>=20 && temp<26 && motion == 3){
      sentHeightLeft = temp - 12;
      temp = 17;
    }else if(temp>86 && temp<115 && motion == 3){
      sentDelayLeft = temp - 85;
      temp = 17;
    }else if(temp>=56 && temp<86 && motion == 3){
      sentResolutionLeft = temp - 55;
      temp = 17;
    }else if(temp>=26 && temp<36 && motion == 3){
      sentLegLiftLeft = temp - 25;
      temp = 17;
    }else if(temp>=125 && temp<144 && motion == 3){
      sentAngleLeft = temp - 124;
      setTurn(sentAngleLeft);
      temp = 17;
    }else{
    //Serial.println(sentHeight);
    switch(temp){
      case 1: //go forward
        if(eco()>10){
          walkForward(sentDelayForward,sentResolutionForward,sentStepDistanceLeftForward,sentStepDistanceRightForward,sentHeightForward,sentLegLiftForward);
        }c
        break;
      case 3: //go backward
        walkBackward(sentDelayBackward,sentResolutionBackward,sentStepDistanceLeftBackward,sentStepDistanceRightBackward,sentHeightBackward,sentLegLiftBackward);
        break;
      case 5: //turn left
        //walkForward(8,-3,3,12,3);
        turnLeft(sentDelayLeft, sentResolutionLeft,sentHeightLeft, sentLegLiftLeft);
        break;
      case 7: //turn right
        turnRight(sentDelayRight,sentResolutionRight,sentHeightRight,sentLegLiftRight);
        break; 
      case 13: //slide to the left
        //turn2(15,20,11,5);
        break;
      case 15: //slide to the right
       // turn2(15,-20,11,5);
        break;
      case 14: //Open endeffector
        endEffectorVal -=5;
        endEffector.write(endEffectorVal);
        break;
      case 16: //Close endeffector
        endEffectorVal +=5;
        endEffector.write(endEffectorVal);
        break;
      case 2: //Increase x axis for robot arm
        x += delayerArm;
        arm(x,y,z);
        writer();
        break;
      case 4: //Decrease x axis for robot arm
        x -= delayerArm;
        arm(x,y,z);
        writer();
        break;
      case 6: //Increase y axis for robot arm
        y += delayerArm;
        arm(x,y,z);
        writer();
        break;
      case 8: //Decrease y axis for robot arm
        y -= delayerArm;
        arm(x,y,z);
        writer();
        break; 
      case 10: //Increase the z axis for robot arm
        z += delayerArm;
        arm(x,y,z);
        writer();
        break;
      case 12: //Decrease the z axis for robot arm
        z -= delayerArm;
        arm(x,y,z);
        writer();
        break; 
      case 9: //front leg squat
        //code here
        break;
      case 11: //back leg squat
        //code here
        break; 
      case 120: //User choose forward motion
        motion = 0;
        temp = 17;
        break;
      case 121: //User choose backward motion
        motion = 1;
        temp = 17;
        break;
      case 122: //User choose Rotate Right motion
        motion = 2;
        temp = 17;
        break;
      case 123: //User choose Rotate Left motion
        motion = 3;
        temp = 17;
        break;
    }
    }

  } 

}
