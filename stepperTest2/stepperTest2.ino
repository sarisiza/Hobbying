/*
 
 * This code tests a stepper motor
 * Stepper motor will turn the amount of degrees that user inputs in serial monitor
  
 Needs: 
 * Stepper motor and ULN2003 based Darlington Driver
 * 
 Circuit:
 * In1 to D8
 * In2 to D9
 * In3 to D10
 * In4 to D11
 
 */

#include <Stepper.h>

//set stepper pins
int stepIn1 = 8;
int stepIn2 = 9;
int stepIn3 = 10;
int stepIn4 = 11;

//set amount of steps
int stepsPerRev = 2048;

//variables to get degrees
String incoming = "";
char incomingChar[10];
double desiredDeg;
boolean complete = false;
int desiredStep;

//initialize stepper
Stepper myStep(stepsPerRev,stepIn1,stepIn3,stepIn2,stepIn4);

void setup() {

  //set RPM
  myStep.setSpeed(12);

  //initialize Serial
  Serial.begin(9600);

  desiredDeg = 0;

}

void loop() {

  if(desiredDeg != 0){

    Serial.println(desiredDeg);
    desiredStep = (int)map(desiredDeg,-365,365,-stepsPerRev,stepsPerRev); //convert degrees to steps
    Serial.println(desiredStep);
    myStep.step(desiredStep); //move motor
    delay(1000);
    desiredDeg = 0;
    
  }
  else{
    //convert String to Int
    if(complete){
      incoming.toCharArray(incomingChar,10);
      desiredDeg = (double)atoi(incomingChar);
      Serial.print(desiredDeg);
      //clear String
      incoming = "";
      complete = false;
    }
    //read from Serial
    while(Serial.available()){
      char charEntrada = Serial.read();
      delay(10);
      incoming += charEntrada;
      if(charEntrada == '\n'){
        complete = true; 
      }
    }      
  }

}
