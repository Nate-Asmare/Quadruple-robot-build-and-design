void elbowDownInverseKinematics(double x, double y, double z){
  theta1 = radToDeg(atan(y/x)); //eq.1
  double r1 = sqrt(pow(x,2) + pow(y,2)); //eq.2
  psi1 = radToDeg(atan(-z/r1)); //eq.3
  double r2 = sqrt(pow(r1,2)+pow(-z,2)); //eq.4
  psi2 = radToDeg(acos((pow(a2,2)+pow(a3,2)-pow(r2,2))/(2*a2*a3))); //eq5
  theta3 = 90 - psi2; //eq6
  psi4 = radToDeg(acos((pow(r2,2)+pow(a2,2)-pow(a3,2))/(2*r2*a2))); //eq7
  psi3 = 45 - psi1; //eq8
  theta2 = psi3 - psi4; //eq9
}

void elbowUpInverseKinematics(double x, double y, double z){
  theta1 = radToDeg(atan(y/x)); //eq.1
  double r1 = sqrt(pow(x,2) + pow(y,2)); //eq.2
  psi1 = radToDeg(atan(z/r1)); //eq.3
  double r2 = sqrt(pow(r1,2)+pow(z,2)); //eq.4
  psi2 = radToDeg(acos((pow(a2,2)+pow(a3,2)-pow(r2,2))/(2*a2*a3))); //eq5
  theta3 = psi2 - 90; //eq6
  psi4 = radToDeg(acos((pow(r2,2)+pow(a2,2)-pow(a3,2))/(2*r2*a2))); //eq7
  psi3 = 45 - psi1; //eq8
  theta2 = psi4 - psi3; //eq9
}

void armInverseKinematics(double x, double y, double z){
  theta1 = radToDeg(atan(y/x)); //eq.1
  double r1 = sqrt(pow(x,2) + pow(y,2)); //eq.2
  double r2 = sqrt(pow(r1,2) + pow((z - a1),2)); //eq3
  psi1 = radToDeg(acos((pow(a2,2) + pow(r2,2) - pow(a3,2))/(2*a2*r2))); //eq4
  psi3 = radToDeg(atan((z - a1)/r1)); //eq5
  theta2 = psi1 + psi3; //eq6
  psi2 = radToDeg(acos((pow(a2,2) + pow(a3,2) - pow(r2,2))/(2*a2*a3))); //eq7
  theta3 = psi2 - 180;
}

double radToDeg(double rad){
  return rad * (180/PI);
}

double degToRad(double deg){
  return deg*(PI/180);
}
