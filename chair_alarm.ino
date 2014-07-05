//Adapted from the bildr article http://bildr.org/2012/11/flexiforce-arduino/


int flexiForcePin = 1;    // analog pin 0
int motorPin = 0;         // tiny vibration motor for feedback
int curCounter = 0;       // current counter - goes up by 1 every second while sitting


void setup(){
  //Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  //  pinMode(flexiForcePin, INPUT_PULLUP);
}

void loop(){
  int flexiForceReading = analogRead(flexiForcePin); 
  //Serial.println(flexiForceReading);                     // use this for serial monitoring where available
  //delay(250);                                            // slow down the output for easier reading

  // **********************************************************
  // Check to see how long I've been sitting. Ideally, I will 
  // get up every 20 minutes and stretch.
  
  if (curCounter >= 1200){                // 20 minutes = 1200
      digitalWrite(motorPin, HIGH);       // light the LED after x time
      digitalWrite(1, HIGH);              // light board LED for testing
  }
  
  
  // **********************************************************
  // If my weight has been in the chair for x amount of time, 
  // vibrate the tiny motor to alert me. 
  //
  // When my weight is no longer detected, reset the counter.
  
   if (flexiForceReading > 10){         // while I'm sitting
      curCounter++;                     // increment sitting counter
    }
    else if (flexiForceReading < 10) {  // if I am standing
      digitalWrite(motorPin, LOW);      // don't buzz the motor
      curCounter = 0;                   // reset the counter to 0
      digitalWrite(1, LOW);             // turn off trinket's board LED
    }
 
  delay(1000);
}

