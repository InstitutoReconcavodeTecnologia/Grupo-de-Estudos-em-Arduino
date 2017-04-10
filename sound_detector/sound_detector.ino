
int soundDetectedPin = A0; //10; // Use Pin 10 as our Input
int soundDetectedVal = HIGH; // This is where we record our Sound Measurement
boolean bAlarm = false;
int THRESHOLD = 540;

unsigned long lastSoundDetectTime; // Record the time that we measured a sound


int soundAlarmTime = 500; // Number of milli seconds to keep the sound alarm high


void setup ()
{
  Serial.begin(9600);  
  pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module
}
void loop ()
{
  soundDetectedVal = analogRead (soundDetectedPin) ; // read the sound alarm time

  //Serial.println(soundDetectedVal);
  
  if(soundDetectedVal >= THRESHOLD){
    Serial.print("Sound detected! Value: ");
    Serial.println(soundDetectedVal);
    }
}

