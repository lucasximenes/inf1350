#include "pindefs.h" 

int state = 1;
unsigned long oldPisca;
unsigned long oldDebounceKey1;
unsigned long oldDebounceKey2;
unsigned long oldDebounceKey3;
unsigned long oldTempo;
unsigned long tempo;
void setup() {
  oldPisca = 0;
  tempo = 1000;
  oldDebounceKey1 = 0;
  oldDebounceKey2 = 0;
  oldDebounceKey3 = 0;
  pinMode(LED1, OUTPUT);
  pinMode (KEY1, INPUT_PULLUP);
  pinMode (KEY2, INPUT_PULLUP);
  digitalWrite(LED1, HIGH);
}
  void loop () {
    unsigned long now = millis();
    if(now >= oldPisca + tempo)
      {
      oldPisca = now;
      state = !state;
      digitalWrite(LED1, state);
      }
      
    if(now - oldDebounceKey1 > 150)
    {
      oldDebounceKey1 = now;
      if (digitalRead(KEY1) == LOW) 
      {
        if(tempo > 250)
        {
        tempo = tempo/2;
        }
      }
    }
    if(now - oldDebounceKey2 > 150)
    {
      oldDebounceKey2 = now;
      if (digitalRead(KEY2) == LOW) 
      {
        if(tempo < 8000)
        {
        tempo = tempo*2;
        }
      }
  }

  if(now - oldDebounceKey3 > 150)
    {
      oldDebounceKey3 = now;
      if (digitalRead(KEY3) == LOW) 
      {
        digitalWrite(LED1, state);
        if (tempo != 0){
          oldTempo = tempo;
          tempo = 0;
        }
        else {
          tempo = oldTempo;
          }  
      }
  }
}

