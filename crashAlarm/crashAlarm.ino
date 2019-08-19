/*
 * 
 * This code creates an alarm to prevent crashing
 * 
 Circuit:
 * Echo connected to D4
 * Trig connected to D5
 * Buzzer connected to D9 with 100ohms resistor
 * 
 */

//ultrasonic inputs
int echo = 4;
int trig = 5;

//buzzer input
int buzz = 9;

void setup() {

  //initialize serial
  Serial.begin(9600);
  //set pinmode for ultrasonic sensor
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  //set pinmode for buzzer
  pinMode(buzz,OUTPUT);

}

void loop() {

  float distCM;
  int pulseMs;
  int freq;
  int sel;
  int ms;

  //send a small square wave on trig to start finder
  digitalWrite(trig,LOW);
  delayMicroseconds(20);
  digitalWrite(trig,HIGH);
  delayMicroseconds(100);
  digitalWrite(trig,LOW);

  //measure pulse lenght from echo pin
  pulseMs = pulseIn(echo,HIGH);

  //calculate distance in CM
  distCM = pulseMs/29.387/2;

  //get four different ranges of distance for switch
  sel = map(distCM,2,148,0,3);

 //update frequency and duration of alarm
  switch(sel){
    case 0:
      freq = 1000;
      ms = 300;
      break;
    case 1:
      freq = 500;
      ms = 400;
      break;
    case 2:
      freq = 100;
      ms = 500;
      break;
    case 3:
      freq = 0;
      ms = 600;
      break;
  }

  //print to serial
  Serial.println(distCM);
  Serial.println(freq);

  //turn buzzer on and off
  tone(buzz,freq);
  delay(ms);
  noTone(buzz);
  delay(ms);

  delay(50);

}
