/*
 
 * This code tests a stepper motor
 * Stepper motor will turn 365 degrees back and forth
  
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

//initialize stepper
Stepper myStep(stepsPerRev,stepIn1,stepIn3,stepIn2,stepIn4);

void setup() {

  //set RPM
  myStep.setSpeed(12);

}

void loop() {

  //step one revolution in one direction
  myStep.step(stepsPerRev);
  delay(1000);

  //step on the other direction
  myStep.step(-stepsPerRev);
  delay(1000);

}
