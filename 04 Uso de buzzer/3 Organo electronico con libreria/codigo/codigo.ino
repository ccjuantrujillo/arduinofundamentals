#include <pitches.h>
int melody[] = {NOTE_C4,NOTE_G3,NOTE_G3,NOTE_A3,NOTE_G3,0,NOTE_B3,NOTE_C4};
int noteDurations[] = {4,8,8,4,4,4,4,4};
int pinBuzzer = 13;

void setup() {
  Serial.begin(9600);
  for(int i=0;i<8;i++){
    int noteDuration = 1000/noteDurations[i];
    tone(pinBuzzer,melody[i],noteDuration);
    int pauseBetweenNotes = noteDuration*1.30;
    delay(pauseBetweenNotes);
    noTone(pinBuzzer);
  }
}

void loop() {
      char note = Serial.read();
    Serial.println(note);
  if(Serial.available()){
    char note = Serial.read();
    Serial.println(note);
    switch(note){
      case 'a':
      case 'A':
        makeTone(NOTE_C4);
        break;
      case 's':
      case 'S':
        makeTone(NOTE_D4);
        break;
      case 'd':
      case 'D':
        makeTone(NOTE_E4);
        break;
      case 'f':
      case 'F':
        makeTone(NOTE_F4);
        break;      
    }
  }
}

void makeTone(int melody){
  tone(pinBuzzer,melody,1000/4);
  delay((1000/4)*1.30);
  noTone(pinBuzzer);
}

