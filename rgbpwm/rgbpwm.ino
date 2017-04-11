int ledr = 13;
int ledg = 12;
int ledb = 11;
int brigtness = A0; //10; // Use Pin 10 as our Input
int boobs;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);
  pinMode (brigtness, OUTPUT) ;
  boobs = 50;
  Serial.begin(9600);  
}

// the loop function runs over and over again forever
void loop() {
  boobs += 50;
  Serial.println(boobs);
  analogWrite(ledr, 10);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledg, 10);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledb, 10);   // turn the LED on (HIGH is the voltage level)

  analogWrite(brigtness, boobs);
  
  delay(1000);                       // wait for a second

  if(boobs >1000)
    boobs = 50;
 /* analogWrite(ledr, 0);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledg, 25);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledb, 50);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  analogWrite(ledr, 500);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledg, 0);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledb, 100);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  */
}
