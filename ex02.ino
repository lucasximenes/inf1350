#include "pindefs.h" 
#include <math.h> 
int state = 1;
unsigned long oldPisca;
unsigned long oldDebounceKey1;
unsigned long oldDebounceKey2;
unsigned long oldDebounceKey3;
unsigned long oldTempo;
unsigned long tempo;
int piscando;
void setup() {
  piscando = 1;
  oldPisca = 0;
  tempo = 1000;
  oldDebounceKey1 = 0;
  oldDebounceKey2 = 0;
  oldDebounceKey3 = 0;
  pinMode(LED1, OUTPUT);
  pinMode (KEY1, INPUT_PULLUP);
  pinMode (KEY2, INPUT_PULLUP);
  pinMode (KEY3, INPUT_PULLUP);
  digitalWrite(LED1, HIGH);
}
void loop () 
  {
    
    unsigned long now = millis();
    if((now >= oldPisca + tempo) && (piscando == 1))
      {
      oldPisca = now;
      state = !state;
      digitalWrite(LED1, state);
      }
      
    if(now - oldDebounceKey1 > 150)
    {
      if (digitalRead(KEY1) == LOW)
      {
        oldDebounceKey1 = now;
        if(tempo > 250)
        {
        tempo = tempo/2;
        }
      }
    }
    if(now - oldDebounceKey2 > 150)
    {
      if (digitalRead(KEY2) == LOW)
      {
        oldDebounceKey2 = now;
        if(tempo < 8000)
        {
        tempo = tempo*2;
        }
      }
  }

  if(now - oldDebounceKey3 > 150)
    {
      if (digitalRead(KEY3) == LOW)
      {
        oldDebounceKey3 = now;
        piscando = !piscando;  
      }
  }
  
  if(fabs(oldDebounceKey1 - oldDebounceKey2 < 1000) && oldDebounceKey1 != 0 && oldDebounceKey2 !=0)
  {
      digitalWrite(LED1, state);
      state = !state;
      piscando = !piscando;
  }
}

