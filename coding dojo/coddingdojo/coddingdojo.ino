/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  for (int i = 13; i > 6; i--){
    pinMode(i, OUTPUT);
  }
  
}

// the loop function runs over and over again forever
void loop() {

  //int x = 2;
  //for (int i = 8; i <= 13; i++){
        
     light(8,8);
     light(9,13);
     light(13,7);
     light(7,10);
     light(10,11);
     light(11,12);
     light(12,7);
     light(7,9);
  //}
    
}

void light(int v1, int v2) {
   //digitalWrite(v1, HIGH);
   digitalWrite(v2, HIGH);// turn the LED on (HIGH is the voltage level)
   delay(analogRead(0));                       // wait for a second
   //digitalWrite(v1, LOW); 
   digitalWrite(v2, LOW);// turn the LED off by making the voltage LOW
   delay(analogRead(0));
}

