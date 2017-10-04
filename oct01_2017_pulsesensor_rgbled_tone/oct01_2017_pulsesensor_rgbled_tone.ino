
/*  Pulse Sensor Amped 1.5    by Joel Murphy and Yury Gitman   http://www.pulsesensor.com

  ----------------------  Notes ----------------------  ----------------------
  This code:
  1) Blinks an LED to User's Live Heartbeat   PIN 13
  2) Fades an LED to User's Live HeartBeat    PIN 5
  3) Determines BPM
  4) Prints All of the Above to Serial

  Read Me:
  https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino/blob/master/README.md
  ----------------------       ----------------------  ----------------------
*/

#define PROCESSING_VISUALIZER 1
#define SERIAL_PLOTTER  2

//  Variables
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat


//RGB pins
#define GREEN 3
#define BLUE 5
#define RED 6

int redVal;
int blueVal;
int greenVal;

int speaker = 2;                  // speaker on pin2 makes a beep with heartbeat



// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded!
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// SET THE SERIAL OUTPUT TYPE TO YOUR NEEDS
// PROCESSING_VISUALIZER works with Pulse Sensor Processing Visualizer
//      https://github.com/WorldFamousElectronics/PulseSensor_Amped_Processing_Visualizer
// SERIAL_PLOTTER outputs sensor data for viewing with the Arduino Serial Plotter
//      run the Serial Plotter at 115200 baud: Tools/Serial Plotter or Command+L
static int outputType = SERIAL_PLOTTER;


void setup() {
  pinMode(blinkPin, OUTPUT);        // pin that will blink to your heartbeat!
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);

  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);

  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS
  // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE,
  // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
  //   analogReference(EXTERNAL);
}


//  Where the Magic Happens
void loop() {
  serialOutput() ;

  if (QS == true && BPM <= 70) {    // A Heartbeat Was Found and BPM is lower than 70
    // BPM and IBI have been Determined
    // Quantified Self "QS" true when arduino finds a heartbeat

    blueFade();                      // Makes the LED Fade Effect Happen
    tone(speaker, 75); 
    serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.

    QS = false;                      // reset the Quantified Self flag for next time
delay(20);
  }

  if (QS == true && BPM > 70 && BPM <= 80) {   // A Heartbeat Was Found and BPM is between 70 and 80
    // BPM and IBI have been Determined
    // Quantified Self "QS" true when arduino finds a heartbeat

    greenFade();                      // Makes the LED Fade Effect Happen
    tone(speaker, 125); 

    serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.

    QS = false;                      // reset the Quantified Self flag for next time
delay(20);
  }

  if (QS == true && BPM > 80 && BPM <= 90) {   // A Heartbeat Was Found and BPM is between 80 and 90
    // BPM and IBI have been Determined
    // Quantified Self "QS" true when arduino finds a heartbeat

    yellowFade();                      // Makes the LED Fade Effect Happen
    tone(speaker, 175); 

    serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.

    QS = false;                      // reset the Quantified Self flag for next time
delay(20);
  }


  if (QS == true && BPM > 90) {    // A Heartbeat Was Found and BPM is larger than 90
    // BPM and IBI have been Determined
    // Quantified Self "QS" true when arduino finds a heartbeat

    redFade();                      // Makes the LED Fade Effect Happen
    tone(speaker, 225); 

    serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.

    QS = false;                      // reset the Quantified Self flag for next time
delay(20);
  }
 

else {
digitalWrite (GREEN, HIGH);
  digitalWrite (BLUE, HIGH);
 digitalWrite (RED, HIGH);
 noTone(speaker);
delay(20);

 }


}


void blueFade() {
  //tone(speaker, 60);            // tone pin, frequency, duration in mS

  redVal = 0;
  greenVal = 150;
  blueVal = 200;
  for (int i = 0; i < 255; i += 10)
  {
    redVal += 0;
    greenVal += 50;
    blueVal -= 50;

    analogWrite(GREEN, 255 - greenVal);
    analogWrite(BLUE, 255 - blueVal);






  }
  delay(90);

}

void greenFade() {
 // tone(speaker, 70);            // tone pin, frequency, duration in mS

  redVal = 50;
  greenVal = 200;
  blueVal = 0;
  for (int i = 0; i < 255; i += 10)
  {
    redVal += 50;
    greenVal -= 50;
    blueVal += 0;
    analogWrite(RED, 255 - redVal);
    analogWrite(GREEN, 255 - greenVal);


  }
  delay(90);

}
void yellowFade() {
 // tone(speaker, 80);            // tone pin, frequency, duration in mS

  redVal = 200;
  greenVal = 100;
  blueVal = 0;
  for (int i = 0; i < 255; i += 10)
  {
    redVal += 50;
    greenVal -= 100;
    blueVal += 0;
    analogWrite(RED, 255 - redVal);
    analogWrite(GREEN, 255 - greenVal);


  }
  delay(90);

}
void redFade() {
 // tone(speaker, 90);            // tone pin, frequency, duration in mS

  redVal = 200;
  greenVal = 0;
  blueVal = 50;
  for (int i = 0; i < 255; i += 15)
  {
    redVal -= 50;
    greenVal += 0;
    blueVal += 50;
    analogWrite(RED, 255 - redVal);
    analogWrite(BLUE, 255 - blueVal);


  }
  delay(90);

}

