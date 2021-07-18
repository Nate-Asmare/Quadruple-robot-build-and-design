
void setTurn(double angle){
  p = sqrt(pow(l,2)+pow(w,2)); //eq1
  q = p/2;
  alpha = radToDeg(acos((pow(l,2)+pow(p,2)-pow(w,2))/(2*l*p))); //eq2
  r = sqrt((2*pow(q,2))-(2*pow(q,2)*cos(degToRad(angle)))); //eq3
  psi = (180-angle)/2; //eq4

  //The below code is unique for turning left
  beta1Left = 180-psi-alpha; //eq5
  beta3Left = psi-alpha; //eq6
  beta4Left = beta3Left; //eq7
  beta2Left = psi+alpha-90; //eq8


  y1Left = -r*cos(degToRad(beta1Left)); //eq9
  z1Left = -r*sin(degToRad(beta1Left)); //eq10

  y2Left = -r*sin(degToRad(beta2Left)); //eq11
  z2Left = -r*cos(degToRad(beta2Left)); //eq12

  y3Left = r*cos(degToRad(beta3Left)); //eq13
  z3Left = r*sin(degToRad(beta3Left)); //eq14

  y4Left = r*cos(degToRad(beta4Left)); //eq15
  z4Left = r*sin(degToRad(beta4Left)); //eq16

  //The below code is unique for turning right
  beta1Right = psi-alpha; //eq5
  beta3Right = psi-(90-alpha); //eq6
  beta4Right = beta3Right; //eq7
  beta2Right = beta1Right; //eq8

  z1Right = r*sin(degToRad(beta1Right)); //eq9
  y1Right = r*cos(degToRad(beta1Right)); //eq10

  z3Right = -r*cos(degToRad(beta3Right)); //eq11
  y3Right = -r*sin(degToRad(beta3Right)); //eq12

  z2Right = r*sin(degToRad(beta2Right)); //eq13
  y2Right = r*cos(degToRad(beta2Right)); //eq14

  z4Right = -r*cos(degToRad(beta4Right)); //eq15
  y4Right = -r*sin(degToRad(beta4Right)); //eq16

  //Serial.println();
  //Serial.println(y2Right);

///
}

void turnRight(double delayer, double res, double height, double legLift){
  for(double i = 1; i <= res; i++){
    frontRight(height-(legLift/res)*i,0,0);
    backLeft(height-(legLift/res)*i,0,0);
    frontLeft(height,y1Right-(y1Right/res)*i,z1Right-(z1Right/res)*i);
    backRight(height,y2Right-(y2Right/res)*i,z2Right-(z2Right/res)*i);
    writer();
    delay(delayer);
  }  

  for(double i = 1; i <= res; i++){
    frontRight((height-legLift)+(legLift/res)*i,(y3Right/res)*i,(z3Right/res)*i);
    backLeft((height-legLift)+(legLift/res)*i,(y4Right/res)*i,(z4Right/res)*i);
    writer();
    delay(delayer);
  } 

  for(double i = 1; i <= res; i++){
    frontLeft(height-(legLift)*(i/res),0,0); // this code is a bit different because the rate of lifting the legs must be greater than the twist of robot body
    backRight(height-(legLift)*(i/res),0,0);
    frontRight(height,y3Right-(y3Right/res)*i,z3Right-(z3Right/res)*i);
    backLeft(height,y4Right-(y4Right/res)*i,z4Right-(z4Right/res)*i);
    writer();
    delay(delayer);
  }

  for(double i = 1; i <= res; i++){
    frontLeft((height-legLift)+(legLift/res)*i,(y1Right/res)*i,(z1Right/res)*i);
    backRight((height-legLift)+(legLift/res)*i,(y2Right/res)*i,(z2Right/res)*i);
    writer();
    delay(delayer);
  }
}

void turnLeft(double delayer, double res, double height, double legLift){
  
  for(double i = 1; i <= res; i++){
    frontLeft(height-(legLift/res)*i,0,0);
    backRight(height-(legLift/res)*i,0,0);
    frontRight(height,y3Left-(y3Left/res)*i,z3Left-(z3Left/res)*i);
    backLeft(height,y4Left-(y4Left/res)*i,z4Left-(z4Left/res)*i);
    writer();
    delay(delayer);
  }  

  for(double i = 1; i <= res; i++){
    frontLeft((height-legLift)+(legLift/res)*i,(y1Left/res)*i,(z1Left/res)*i);
    backRight((height-legLift)+(legLift/res)*i,(y2Left/res)*i,(z2Left/res)*i);
    writer();
    delay(delayer);
  } 

  for(double i = 1; i <= res; i++){
    frontRight(height-(legLift)*(i/res),0,0); // this code is a bit different because the rate of lifting the legs must be greater than the twist
    backLeft(height-(legLift)*(i/res),0,0);
    frontLeft(height,y1Left-(y1Left/res)*i,z1Left-(z1Left/res)*i);
    backRight(height,y2Left-(y2Left/res)*i,z2Left-(z2Left/res)*i);
    writer();
    delay(delayer);
  }

  for(double i = 1; i <= res; i++){
    frontRight((height-legLift)+(legLift/res)*i,(y3Left/res)*i,(z3Left/res)*i);
    backLeft((height-legLift)+(legLift/res)*i,(y4Left/res)*i,(z4Left/res)*i);
    writer();
    delay(delayer);
  } 
}
