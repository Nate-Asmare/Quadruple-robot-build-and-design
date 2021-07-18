
//this function is used to write the angle values to the servos
void writer(){
  frontRightLeg0.write(frontRightLeg0Val);
  frontRightLeg1.write(frontRightLeg1Val);
  frontRightLeg2.write(frontRightLeg2Val);
  frontLeftLeg0.write(frontLeftLeg0Val);
  frontLeftLeg1.write(frontLeftLeg1Val);
  frontLeftLeg2.write(frontLeftLeg2Val);
  backLeftLeg0.write(backLeftLeg0Val);
  backLeftLeg1.write(backLeftLeg1Val);
  backLeftLeg2.write(backLeftLeg2Val);
  backRightLeg0.write(backRightLeg0Val);
  backRightLeg1.write(backRightLeg1Val);
  backRightLeg2.write(backRightLeg2Val);
  armBody.write(armBodyVal);
  armShoulder.write(armShoulderVal);
  armElbow.write(armElbowVal);
  endEffector.write(endEffectorVal);
}

void arm(double x, double y, double z){
  a1 = 5.5; //cm
  a2 = 14; //cm
  a3 = 10; //cm
  armInverseKinematics(x,y,z);

  armBodyVal = armBodyValD + (theta1); 
  armShoulderVal = armShoulderValD + theta2;
  armElbowVal = (theta3*-1);
}

void frontRight(double x, double y, double z){
  a1 = 0; //cm
  a2 = 7; //cm
  a3 = 7; //cm
  elbowDownInverseKinematics(x,y,z);
  
  frontRightLeg0Val = frontRightLeg0ValD + theta1;
  frontRightLeg1Val = frontRightLeg1ValD + theta2;
  frontRightLeg2Val = frontRightLeg2ValD + (theta3);
}

void frontLeft(double x, double y, double z){
  a1 = 0; //cm
  a2 = 7; //cm
  a3 = 7; //cm
  elbowDownInverseKinematics(x,y,z);
  
  frontLeftLeg0Val = frontLeftLeg0ValD + (theta1*-1);
  frontLeftLeg1Val = frontLeftLeg1ValD + (theta2*-1);
  frontLeftLeg2Val = frontLeftLeg2ValD + (theta3*-1);
}

void backLeft(double x, double y, double z){
  a1 = 0; //cm
  a2 = 7; //cm
  a3 = 7; //cm
  elbowUpInverseKinematics(x,y,z);
  
  backLeftLeg0Val = backLeftLeg0ValD + theta1;
  backLeftLeg1Val = backLeftLeg1ValD + theta2;
  backLeftLeg2Val = backLeftLeg2ValD + (theta3);
}

void backRight(double x, double y, double z){
  a1 = 0; //cm
  a2 = 7; //cm
  a3 = 7; //cm
  elbowUpInverseKinematics(x,y,z);
  
  backRightLeg0Val = backRightLeg0ValD + (theta1*-1);
  backRightLeg1Val = backRightLeg1ValD + (theta2*-1);
  backRightLeg2Val = backRightLeg2ValD + (theta3*-1);
}

int eco(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  return distance= duration*0.034/2;
}

void attachAll(){
  frontRightLeg0.attach(23);
  frontRightLeg1.attach(25);
  frontRightLeg2.attach(2);
  frontLeftLeg0.attach(29);
  frontLeftLeg1.attach(31);
  frontLeftLeg2.attach(33);
  backLeftLeg0.attach(35);
  backLeftLeg1.attach(37);
  backLeftLeg2.attach(39);
  backRightLeg0.attach(41);
  backRightLeg1.attach(43);
  backRightLeg2.attach(45);
  armBody.attach(46);
  armShoulder.attach(48);
  armElbow.attach(50);
  endEffector.attach(44);
  backRight(12,0,0);
  backLeft(12,0,0);
  frontLeft(12,0,0);
  frontRight(12,0,0);
  arm(2,0,9.5);
  writer();
  }
