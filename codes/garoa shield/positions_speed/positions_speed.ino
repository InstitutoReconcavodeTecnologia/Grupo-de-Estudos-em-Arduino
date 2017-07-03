hield // the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int readValue = analogRead(A0);
  if (readValue < 50) {
    readValue = 50;
  }
  
  for(int i = 8; i< 14; i++) {
    int prev;
    if (i == 8) {
      prev = 13;
    } else {
      prev = i-1;
    }
    
    digitalWrite(i, HIGH);   
    digitalWrite(prev, HIGH);   
    delay(readValue);                      
    digitalWrite(i, LOW); 
    digitalWrite(prev, LOW);     
    delay(readValue);    
    if(i > 13) {
      i = 8;        
    }           
  }
}
