
#include "pitches.h"

int pitch = NOTE_C8;
float noteDuration[] = { 18, 20, 25, 32 };
int noteDurCount = 4;
int couplet = 3;
int dusk = 50;

void setup(){
  Serial.begin(9600);
}

void loop(){

  int reading = analogRead(0);
  Serial.println(reading);


  if(reading <= dusk){
    for(int repeat=0; repeat < couplet; repeat++){
      for(int idx=0; idx < noteDurCount; idx++){
        int noteDur = noteDuration[idx];

        tone(8, pitch);
        delay(noteDur);
        // stop the tone
        noTone(8);

        delay(noteDur);
      } 
      // delay after couplet 
      delay(random(350,600));
    }
    // delay after repeating song 
    delay(random(200,300)); 
  }
}

