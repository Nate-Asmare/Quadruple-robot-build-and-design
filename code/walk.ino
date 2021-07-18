//two leg walk algorigm code here...

//three leg walk algorithm
void walkForward(double delayer, double res, double stepDistanceLeft, double stepDistanceRight, double height, double legLift){
  for(double i = 1; i <= res; i++){  //1 
      frontLeft(height-(legLift/res)*i,0,0);
      frontRight(height,0,stepDistanceRight-(stepDistanceRight/res)*i);
      backLeft(height,0,-stepDistanceLeft+(stepDistanceLeft/res)*i);
      backRight(height,0,(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //2
      frontLeft((height-legLift)+(legLift/res)*i,0,(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //3
      backRight(height-(legLift/res)*i,0,stepDistanceRight-(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //4
      backRight((height-legLift)+(legLift/res)*i,0,-(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //5
      frontRight(height-(legLift/res)*i,0,0);
      frontLeft(height,0,stepDistanceLeft-(stepDistanceLeft/res)*i);
      backRight(height,0,-stepDistanceRight+(stepDistanceRight/res)*i);
      backLeft(height,0,(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //6
      frontRight((height-legLift)+(legLift/res)*i,0,(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //7
      backLeft(height-(legLift/res)*i,0,stepDistanceLeft-(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //8
      backLeft((height-legLift)+(legLift/res)*i,0,-(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  } 
}


void walkBackward(double delayer,double res, double stepDistanceLeft, double stepDistanceRight, double height, double legLift){
  for(double i = 1; i <= res; i++){  //1 
      frontLeft(height,0,stepDistanceLeft-(stepDistanceLeft/res)*i);
      frontRight(height,0,-stepDistanceRight+(stepDistanceRight/res)*i);
      backLeft(height,0,stepDistanceLeft-(stepDistanceLeft/res)*i);
      backRight(height-(legLift/res)*i,0,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //2
      backRight((height-legLift)+(legLift/res)*i,0,(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //3
      frontLeft(height-(legLift/res)*i,0,stepDistanceLeft-(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //4
      frontLeft((height-legLift)+(legLift/res)*i,0,-(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //5
      frontLeft(height,0,-stepDistanceLeft+(stepDistanceLeft/res)*i);
      frontRight(height,0,(stepDistanceRight/res)*i);
      backRight(height,0,stepDistanceRight-(stepDistanceRight/res)*i);
      backLeft(height-(legLift/res)*i,0,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //6
      backLeft((height-legLift)+(legLift/res)*i,0,(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //7
      frontRight(height-(legLift/res)*i,0,stepDistanceRight-(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //8
      frontRight((height-legLift)+(legLift/res)*i,0,-(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  } 
}

//On testing phase
void moonWalk(double delayer, double res, double stepDistanceLeft, double stepDistanceRight, double height, double legLift){
  for(double i = 1; i <= res; i++){  //1 
      frontRight(height-(legLift/res)*i,0,0);
      backLeft(height-(legLift/res)*i,0,0);

      frontLeft(height,0,-stepDistanceRight+(stepDistanceRight/res)*i);
      backRight(height,0,stepDistanceLeft-(stepDistanceLeft/res)*i);

//      frontLeft(height-(legLift/res)*i,0,0);
//      frontRight(height,0,stepDistanceRight-(stepDistanceRight/res)*i);
//      backLeft(height,0,-stepDistanceLeft+(stepDistanceLeft/res)*i);
//      backRight(height,0,(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //2
      frontRight((height-legLift)+((legLift-0.5)/res)*i,0,(stepDistanceLeft/res)*i);
      backLeft((height-legLift)+((legLift-0.5)/res)*i,0,-(stepDistanceRight/res)*i);

      
//      frontLeft((height-legLift)+(legLift/res)*i,0,(stepDistanceLeft/res)*i);
//      writer();
//      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //3
      frontRight(height-0.5,0,stepDistanceLeft-(2*stepDistanceLeft/res)*i);
      backLeft(height-0.5,0,-stepDistanceRight+(2*stepDistanceRight/res)*i);
      
//      /backRight(height-(legLift/res)*i,0,stepDistanceRight-(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //4
      frontLeft(height-(legLift/res)*i,0,0);
      backRight(height-(legLift/res)*i,0,0);

      frontRight(height,0,-stepDistanceRight+(stepDistanceRight/res)*i);
      backLeft(height,0,stepDistanceLeft-(stepDistanceLeft/res)*i);
    
//      backRight((height-legLift)+(legLift/res)*i,0,-(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //5
      frontLeft((height-legLift)+((legLift-0.5)/res)*i,0,(stepDistanceLeft/res)*i);
      backRight((height-legLift)+((legLift-0.5)/res)*i,0,-(stepDistanceRight/res)*i);

//      frontRight(height-(legLift/res)*i,0,0);
//      frontLeft(height,0,stepDistanceLeft-(stepDistanceLeft/res)*i);
//      backRight(height,0,-stepDistanceRight+(stepDistanceRight/res)*i);
//      backLeft(height,0,(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //6
      frontLeft(height-0.5,0,stepDistanceLeft-(2*stepDistanceLeft/res)*i);
      backRight(height-0.5,0,-stepDistanceRight+(2*stepDistanceRight/res)*i);
      
//     / frontRight((height-legLift)+(legLift/res)*i,0,(stepDistanceRight/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //7
      backLeft(height-(legLift/res)*i,0,stepDistanceLeft-(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= res; i++){  //8
      backLeft((height-legLift)+(legLift/res)*i,0,-(stepDistanceLeft/res)*i);
      writer();
      delay(delayer);
  } 
}

void slideRight(double delayer, double stepDistanceLeft, double stepDistanceRight, double height, double legLift){
  for(double i = 1; i <= 3; i+=0.2){  //1 
      frontLeft(height-(legLift/3)*i,0,0);
      frontRight(height,-stepDistanceRight+(stepDistanceRight/3)*i,0);
      backLeft(height,stepDistanceRight-(stepDistanceRight/3)*i,0);
      backRight(height,-(stepDistanceRight/3)*i,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= 3; i+=0.2){  //2
      frontLeft((height-legLift)+(legLift/3)*i,-(stepDistanceRight/3)*i,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= 3; i+=0.2){  //3
      backRight(height-(legLift/3)*i,-stepDistanceRight+(stepDistanceRight/3)*i,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= 3; i+=0.2){  //4
      backRight((height-legLift)+(legLift/3)*i,(stepDistanceRight/3)*i,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= 3; i+=0.2){  //5
      frontLeft(height,-stepDistanceRight+(stepDistanceRight/3)*i,0);
      frontRight(height-(legLift/3)*i,0,0);
      backRight(height,stepDistanceRight-(stepDistanceRight/3)*i,0);
      backLeft(height,-(stepDistanceRight/3)*i,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= 3; i+=0.2){  //6
      frontRight((height-legLift)+(legLift/3)*i,-(stepDistanceRight/3)*i,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= 3; i+=0.2){  //7
      backLeft(height-(legLift/3)*i,-stepDistanceRight+(stepDistanceRight/3)*i,0);
      writer();
      delay(delayer);
  }
  for(double i = 1; i <= 3; i+=0.2){  //8
      backLeft((height-legLift)+(legLift/3)*i,(stepDistanceRight/3)*i,0);
      writer();
      delay(delayer);
  } 
}
