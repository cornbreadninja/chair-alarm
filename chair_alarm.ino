//Adapted from the bildr article http://bildr.org/2012/11/flexiforce-arduino/


int flexiForcePin = 1;    // analog pin 0
int motorPin = 3;         // LED for status
int curCounter = 0;       // current counter - goes up by 1 every second while sitting


void setup(){
  //Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  //  pinMode(flexiForcePin, INPUT_PULLUP);
}

void loop(){
  int flexiForceReading = analogRead(flexiForcePin); 
  //Serial.println(flexiForceReading);                                  // use this for serial monitoring where available
  //delay(250);                                                         // slow down the output for easier reading

  // **********************************************************
  // Check to see how long I've been sitting. Ideally, I will 
  // get up every 20 minutes and stretch.
  
  if (curCounter >= 100){
      digitalWrite(LEDpin, HIGH);
  }
  
  
  // **********************************************************
  // If my weight has been in the chair for x amount of time, 
  // vibrate a tiny motor to alert me. 
  //
  // When my weight is no longer detected, reset the counter.
  
  if (flexiForceReading > 10){             // while I'm sitting
    //if (time > 1000) {                   // if x time has passed  
      curCounter++;                        // increment sitting counter
      digitalWrite(motorPin, HIGH);        // buzz the motor
      //Serial.println("sitting");    
      //Serial.println("Time: ");
      //Serial.println(time);
    }
    
    else if (flexiForceReading < 10) {     // if I am standing
      digitalWrite(motorPin, LOW);         // stop the motor
      curCounter = 0;                      // reset counter to 0
      //Serial.println("standing");
    }
    
  delay(1000);
}
