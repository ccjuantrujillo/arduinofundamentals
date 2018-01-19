int speakerPin = 13;
int numTones = 10;
int tones[]={261,277,294,311,330,349,370,392,415,440,446,494};
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(int i=0;i<numTones;i++){
    tone(speakerPin,tones[i]);
    delay(500);
  }
  noTone(speakerPin);
}
