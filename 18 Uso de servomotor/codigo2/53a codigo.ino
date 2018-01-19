#include <Stepper.h>
#define STEPS 200 //Número de pasos que necesita para dar una vuelta. 200 en nuestro caso
 
// Ponemos nombre al motor, el número de pasos y los pins de control
Stepper stepper(STEPS, 8,9,10,11); //Stepper nombre motor (número de pasos por vuelta, pins de control)
 
void setup()
{
  // Velocidad del motor en RPM
  stepper.setSpeed(75);
}
 
void loop()
{
  //Girar una vuelta entera en un sentido
  stepper.step(200);
  delay(100); //Pequeña pausa
 
  //Girar una vuelta entera en sentido contrario
  stepper.step(-200);
  delay(100); //Pequeña pausa
}
