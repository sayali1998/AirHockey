#include "SevenSegmentTM1637.h"

const byte PIN_CLK = 4; 
const byte PIN_DIO = 5;
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

int ldr1=A0;
int ldr2=A1;
bool goalDetected = false;
int resumeButton=5;
int resetButton=4;
uint8_t count=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(resumeButton,INPUT_PULLUP);
  pinMode(resetButton,INPUT_PULLUP);
  display.begin();
  display.setBacklight(100);
  display.print("INIT");
  delay(1000);
}

int ldr1Value()
{
  return analogRead(ldr1);
  }

int ldr2Value()
{
  return analogRead(ldr2);
  }


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(ldr1Value());
  Serial.println(ldr2Value());

  display.print(count);
 
 // Serial.println(digitalRead(resumeButton));
  delay(1000);
  if(goalDetected == false) {
    if(ldr1Value() < 300|| ldr2Value()<300) {
      goalDetected = true;
      count++;
      Serial.println();
      Serial.println(count);
      Serial.println("GOAL!!");
      display.clear();
      display.print("GOAL");
      delay(1000);
      display.print(count);
      
    }
  }
  else {
    if(digitalRead(resumeButton) == LOW) {
      goalDetected = false;
      Serial.println(goalDetected);
      Serial.println("REsume");
    }
  }
    if(digitalRead(resetButton)==LOW)
    {
      count=0;
      goalDetected=false;
      Serial.println("Game Reset");
      display.print("Over");
      delay(1000);
      display.print(count);
      }
}
