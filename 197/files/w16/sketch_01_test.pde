

import processing.serial.*;


float f;
float x;
  Serial myPort;  // Create object from Serial class
String sval ="12";     // Data received from the serial port

/**
 * Patterns. 
 * 
 * Move the cursor over the image to draw with a software tool 
 * which responds to the speed of the mouse. 
 */
 
void setup() {
  


String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
print(portName);
  myPort = new Serial(this, portName,9600);
  
  size(300, 300);
 
}

void draw() {

  
  if ( myPort.available() > 0) 
  {  // If data is available,
  sval = myPort.readStringUntil('\n');         // read it and store it in val
  } 
//println(sval);//print it out in the console

 
try{
  //int a = Integer.parseInt(sval);
  if(sval != null){
    
   f = Float.parseFloat(sval);
  }
  else
  {
     f = 0;
  }
}

catch(NumberFormatException ex){ // handle your exception
  
}


//f = (float)sval;


 background(255);
  
    // Call the variableEllipse() method and send it the
  // parameters for the current mouse position
  // and the previous mouse position
stroke(204, 102, 0);
strokeWeight(5); 
line(20,60,20,280);

stroke(0, 0, 0);
strokeWeight(10); 
line(20,280,280,280);

stroke(0, 0, 255);
strokeWeight(3); 

println(f);
if(f > 300 ){
  f = 300;
}
x = map(f,0,80,20,280);
println(x);
line(x,150,x,280);

}