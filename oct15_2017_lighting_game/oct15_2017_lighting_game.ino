int aLight = LOW;
int aBttn = 7;
int aledPin = 13;

int bLight = LOW;
int bBttn = 6;
int bledPin = 12;

int cLight = LOW;
int cBttn = 5;
int cledPin = 11;

int dLight = LOW;
int dBttn = 4;
int dledPin = 10;


void setup()
{ Serial.begin(9600);

  pinMode(aledPin, OUTPUT);
  pinMode (aBttn, INPUT);

  pinMode(bledPin, OUTPUT);
  pinMode (bBttn, INPUT);

  pinMode(cledPin, OUTPUT);
  pinMode (cBttn, INPUT);

  pinMode(dledPin, OUTPUT);
  pinMode (dBttn, INPUT);

  digitalWrite(aledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  digitalWrite(aledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(50);

  digitalWrite(bledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  digitalWrite(bledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(50);

  digitalWrite(cledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  digitalWrite(cledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(50);

  digitalWrite(dledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);
  digitalWrite(dledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(50);

  digitalWrite(aledPin, HIGH);

  digitalWrite(bledPin, HIGH);

  digitalWrite(cledPin, HIGH);

  digitalWrite(dledPin, HIGH);

  delay(100);


  digitalWrite(aledPin, LOW);

  digitalWrite(bledPin, LOW);

  digitalWrite(cledPin, LOW);

  digitalWrite(dledPin, LOW);
  delay(100);


  digitalWrite(aledPin, HIGH);

  digitalWrite(bledPin, HIGH);

  digitalWrite(cledPin, HIGH);

  digitalWrite(dledPin, HIGH);

  delay(100);

  digitalWrite(aledPin, LOW);

  digitalWrite(bledPin, LOW);

  digitalWrite(cledPin, LOW);

  digitalWrite(dledPin, LOW);

}

void loop()
{

  Serial.print (aLight);
  Serial.print(",");
  Serial.print (bLight);
  Serial.print(",");
  Serial.print (cLight);
  Serial.print(",");
  Serial.println (dLight);
  

  //Button A controls light C and B


  if (digitalRead(aBttn) == HIGH) {
    bttnA();

  }


  //Button B controls light A, B and C

  if (digitalRead(bBttn) == HIGH) {
    bttnB();
  }

  //Button C controls light  C and D


  if (digitalRead(cBttn) == HIGH) {
    bttnC();
  }

  //Button D controls light B, C and D

  if (digitalRead(dBttn) == HIGH) {
    bttnD();
  }

}




void bttnA () {
  while (digitalRead(aBttn) == LOW);
  //do nothing until button pressed
  if (digitalRead(aBttn) == HIGH) cLight = !cLight; bLight = !bLight;
  while (digitalRead(aBttn) == HIGH);
  digitalWrite(cledPin, cLight);
  digitalWrite(bledPin, bLight);
}

void bttnB () {

  while (digitalRead(bBttn) == LOW); //do nothing until button pressed
  if (digitalRead(bBttn) == HIGH) aLight = !aLight; bLight = !bLight; cLight = !cLight;
  while (digitalRead(bBttn) == HIGH);
  digitalWrite(aledPin, aLight);
  digitalWrite(bledPin, bLight);
  digitalWrite(cledPin, cLight);

}


void bttnC () {
  while (digitalRead(cBttn) == LOW); //do nothing until button pressed
  if (digitalRead(cBttn) == HIGH)  cLight = !cLight; dLight = !dLight;
  while (digitalRead(cBttn) == HIGH);
  digitalWrite(cledPin, cLight);
  digitalWrite(dledPin, dLight);
}

void bttnD () {
  while (digitalRead(dBttn) == LOW); //do nothing until button pressed
  if (digitalRead(dBttn) == HIGH) bLight = !bLight; cLight = !cLight; dLight = !dLight;
  while (digitalRead(dBttn) == HIGH);
  digitalWrite(bledPin, bLight);

  digitalWrite(cledPin, cLight);
  digitalWrite(dledPin, dLight);

}

