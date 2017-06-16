int ledr = 11;
int ledg = 13;
int ledb = 12;
int brigtness = 9;//A0; //10; // Use Pin 10 as our Input
int boobs;
int cycle;
int r;
int g;
int b;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);
  pinMode (brigtness, OUTPUT) ;
  boobs = 0;
  cycle = 0;
  r= HIGH;
  g= HIGH;
  b= HIGH;  
  Serial.begin(9600);  
}

// the loop function runs over and over again forever
void loop() {
  boobs += 50;
  
  if(cycle == 0){
    r = LOW;
    g= HIGH;
    b = HIGH;
    }else if(cycle == 1){
    r = HIGH;
    g= LOW;
    b = HIGH;
    }else{
      r = HIGH;
      g= HIGH;
      b = LOW;
      }
  
  digitalWrite(ledr, r);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledg, g);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledb, b);   // turn the LED on (HIGH is the voltage level)

  analogWrite(brigtness, boobs);
  
  delay(1000);                       // wait for a second

  if(boobs >= 250){
    boobs = 0;
    cycle = (cycle+1)%3;
  }
 /* analogWrite(ledr, 0);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledg, 25);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledb, 50);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  analogWrite(ledr, 500);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledg, 0);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledb, 100);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  */
}
