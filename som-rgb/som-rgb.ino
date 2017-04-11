int ledb = 13;
int ledr = 12;
int ledg = 11;
int soundDetectedPin = A0; //10; // Use Pin 10 as our Input
int soundDetectedVal = HIGH; // This is where we record our Sound Measurement
boolean bAlarm = false;
int THRESHOLD = 200;//540;

unsigned long lastSoundDetectTime; // Record the time that we measured a sound


int soundAlarmTime = 500; // Number of milli seconds to keep the sound alarm high


void setup ()
{
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);
  Serial.begin(9600);  
  pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module

  disableLeds();
}
void loop ()
{
  soundDetectedVal = analogRead (soundDetectedPin) ; // read the sound alarm time

  //Serial.println(soundDetectedVal);
  
  if(soundDetectedVal >= THRESHOLD){
    Serial.print("Sound detected! Value: ");
    Serial.println(soundDetectedVal);

      digitalWrite(ledr, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledg, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledb, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);
    }

    disableLeds();
}

void disableLeds() {
        digitalWrite(ledr, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledg, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ledb, HIGH);   // turn the LED on (HIGH is the voltage level)

  }

