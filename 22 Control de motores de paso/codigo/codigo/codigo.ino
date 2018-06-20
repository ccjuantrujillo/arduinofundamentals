#include <Stepper.h>
#define STEPS 1000
  
Stepper stepper(STEPS, 8, 9, 10, 11);
 
void setup() {
  stepper.setSpeed(10);
}
  
void loop() {
  stepper.step(100);
  delay(50);
  stepper.step(-100);
  delay(50);  
}
