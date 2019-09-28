#include <VirtualWire.h>

void setup() {
  //Serial.begin(9600);
  for(int i=5;i<13;i++)
    pinMode(i, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_tx_pin(4);
  vw_set_ptt_pin(13);
}

int a[13];
void loop() {
  uint8_t sen1 = map(analogRead(A0), 0, 1023, 0, 255);
  uint8_t sen2 = map(analogRead(A1), 0, 1023, 0, 255);
  uint8_t sen3 = map(analogRead(A2), 0, 1023, 0, 255);
  uint8_t sen4 = map(analogRead(A3), 0, 1023, 0, 255);
  uint8_t sw1 = digitalRead(2);

  char msg[6] = {sen1,sen2,sen3,sen4,sw1}; 

  vw_send((uint8_t *)msg,5);
  vw_wait_tx();
  delay(50);
}
