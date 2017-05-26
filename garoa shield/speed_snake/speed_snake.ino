int positions[8][2] = {{8,9}, {9,7}, {7,12}, {12, 11}, {10, 11}, {10, 7}, {7, 13}, {13, 8}}; 


// the setup function runs once when you press reset or power the board
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
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int readValue = analogRead(A0);
  if (readValue < 50) {
    readValue = 50;
  }
  
  for(int i = 0; i< 8; i++) {
    digitalWrite(positions[i][0], HIGH);   
    digitalWrite(positions[i][1], HIGH);   
    delay(readValue);                      
    digitalWrite(positions[i][0], LOW); 
    digitalWrite(positions[i][1], LOW);     
    delay(readValue);    

    Serial.print(positions[i][0]);
    Serial.print(" ");
    Serial.println(positions[i][1]);
    if(i > 7) {
      i = 0;        
    }           
  }
}
