#include<IRremote.h>
int IRpin = 2;
IRrecv IR(IRpin);
decode_results results;
int r = 3;
int g = 5;
int b =6;

void setup() 
{
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(OUTPUT, r);
  pinMode(OUTPUT, g);
  pinMode(OUTPUT, b);
}

void loop() 
{
  while(IR.decode(&results) == 0)
  {
    
  }

  if (IR.decode(&results))
  {
    unsigned int value = results.value;
    Serial.print(" KEY VALUE IN DECIMAL (DEC): ");
    Serial.println(results.value,DEC);
    switch(value)
    {
      case 16724175:
      Serial.println("You pressed key 1 - Red");
      analogWrite(r, 255);
      analogWrite(g, 0);
      analogWrite(b, 0);
      delay(1000);
      break;

      case 16718055:
      Serial.println("You pressed key 2 - Green");
      analogWrite(r, 0);
      analogWrite(g, 255);
      analogWrite(b, 0);
      delay(1000);
      break;

      case 16743045:
      Serial.println("You pressed key 3 - Blue");
      analogWrite(r, 0);
      analogWrite(g, 0);
      analogWrite(b, 255);
      delay(1000);
      break;

      case 16716015:
      Serial.println("You pressed key 4 - Dark Seagrass");
      analogWrite(r, 73);
      analogWrite(g, 107);
      analogWrite(b, 101);
      delay(1000);
      break;

      case 16726215:
      Serial.println("You pressed key 5 - Lavender");
      analogWrite(r, 167);
      analogWrite(g, 136);
      analogWrite(b, 191);
      delay(1000);
      break;

      case 16726215:
      Serial.println("You pressed key 5 - Lavender");
      analogWrite(r, 167);
      analogWrite(g, 136);
      analogWrite(b, 191);
      delay(1000);
      break;
    }
  }
  IR.resume();
}
