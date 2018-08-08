int ldr1=A0;
int ldr2=A1;
bool goalDetected = false;
int resumeButton=5;
int resetButton=4;
int count=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(resumeButton,INPUT_PULLUP);
  pinMode(resetButton,INPUT_PULLUP);
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
 
 // Serial.println(digitalRead(resumeButton));
  delay(1000);
  if(goalDetected == false) {
    if(ldr1Value() < 300|| ldr2Value()<300) {
      goalDetected = true;
      count++;
      Serial.println();
      Serial.println(count);
      Serial.println("GOAL!!");
      
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
      }
}
