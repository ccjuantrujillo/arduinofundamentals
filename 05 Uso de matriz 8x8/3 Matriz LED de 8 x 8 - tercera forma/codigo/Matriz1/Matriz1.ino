#include <MatrizLed.h>

MatrizLed pantalla;

void setup() {
  pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
}

void loop() {
  pantalla.borrar();
  for(int i = 0; i > -75; i--){
    pantalla.escribirFrase("CECCOS 2023", i);
    delay(100);
  }
}
