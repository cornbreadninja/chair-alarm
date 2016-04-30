// Binary Chair Alarm
// original analog version called Chair Alarm is based on the bildr article 
// http://bildr.org/2012/11/flexiforce-arduino/

// This version uses X number of pressure-sensitive switches to detect my weight,
// which turns it into a binary reading.

// If one or more sensors detects weight for 20 continuous minutes, a small motor
// will buzz to let me know that it's time to stand up and walk around.


int sensorsPin = 8;       // digital pin 3 that carries all sensor input
int motorPin = 4;         // tiny vibration motor for feedback
int curCounter = 0;       // current counter - goes up by 1 every second while sitting (uses delay)


void setup() {
  //Serial.begin(9600);               // remember, not all boards can use Serial (Trinket, ArdPro)
  pinMode(motorPin, OUTPUT);          // set the pin the motor is on as an output
  pinMode(sensorsPin, INPUT_PULLUP);
}

void loop() {
  int sensorsPinReading = digitalRead(sensorsPin);
  //Serial.println(sensorsPinReading);


  // check to see how long I've been sitting
  if (curCounter >= 1200) {            // 20 minutes = 1200 seconds
    digitalWrite(motorPin, HIGH);      // buzz the motor after x time
  }


  // if my weight has been in the chair for x amount of time, make a buzzing sound
  if (sensorsPinReading == LOW) {      // while I'm sitting
    digitalWrite(13, HIGH);            // light board LED for testing
    curCounter++;                      // increment sitting counter
    //Serial.println("is high");
  }
  
  
  else if (sensorsPinReading == HIGH) {  //if I am standing
    digitalWrite(motorPin, LOW);         // don't buzz the motor / stop buzzing it
    curCounter = 0;                      // reset the counter to 0
    digitalWrite(13, LOW);               // turn off trinket's board LED
    //Serial.println("is low");
  }

  //Serial.println(curCounter);

  delay(1000);
}


