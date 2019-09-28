#include <ServoTimer2.h>
#include <VirtualWire.h>

ServoTimer2 servo1;
ServoTimer2 servo2;
ServoTimer2 servo3;
ServoTimer2 servo4;

void setup()
{
    Serial.begin(115200);

    vw_set_ptt_inverted(true);
    vw_set_rx_pin(3);
    vw_set_ptt_pin(4);
    vw_setup(2000);
    vw_rx_start();

    servo1.attach(9);
    servo2.attach(10);
    servo3.attach(11);
    servo4.attach(12);
    pinMode(26,OUTPUT);
    digitalWrite(26,LOW);
}

uint8_t val[10];

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen))
  {
	  for (uint8_t i = 0; i < buflen; i++)
	  {
      val[i] = buf[i];
	  }
  }
  servo1.write(map(val[2],0,255,1000,2000));
  servo2.write(map(val[2],0,255,1000,2000));
  servo3.write(map(val[2],0,255,1000,2000));
  servo4.write(map(val[2],0,255,1000,2000));

  Serial.print(val[0]);
  Serial.print("  ");
  Serial.print(val[1]);
  Serial.print("  ");
  Serial.print(val[2]);
  Serial.print("  ");
  Serial.print(val[3]);
  Serial.println();
}
