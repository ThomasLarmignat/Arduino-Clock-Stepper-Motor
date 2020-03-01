#include <Stepper.h>
#define ONEMINUTE (1000UL * 60)
unsigned long rolltime = millis() + ONEMINUTE;


const int stepsPerRevolution = 1024;  // Un demi tour
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int i = 0; 

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(30);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
if((long)(millis() - rolltime) >= 0) {
  myStepper.step(-stepsPerRevolution);
  rolltime += ONEMINUTE;
  i = i + 1; 

  if(i == 720) {//reglage problème décallage 
    myStepper.step(-stepsPerRevolution);
    i = 0 ;
  }
 }
}
