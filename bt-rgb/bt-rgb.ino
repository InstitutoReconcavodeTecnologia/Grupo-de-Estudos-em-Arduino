#include <SoftwareSerial.h>

int green = 12;
int red = 9;
int blue = 13;
SoftwareSerial mySerial(10, 11); // RX, TX
String command;
void setup()
{
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  Serial.println("Type AT commands!");
  // SoftwareSerial "com port" data rate. JY-MCU v1.03 defaults to 9600.
  mySerial.begin(9600);
}

void loop()
{

  // Read device output if available.
  if (mySerial.available())
  {    while (mySerial.available())
    { // While there is more to be read, keep reading.
      command += (char)mySerial.read();
    }
    Serial.print(command);
    if(command == "0"){
         digitalWrite(blue,LOW);
      digitalWrite(red ,LOW);
      digitalWrite(green, HIGH);
    }else if (command == "1") {
         digitalWrite(blue,LOW);
      digitalWrite(red ,HIGH);
      digitalWrite(green, LOW);
    }else if(command == "2"){
         digitalWrite(blue,HIGH);
      digitalWrite(red ,LOW);
      digitalWrite(green, LOW);
    } else{
               digitalWrite(blue,LOW);
      digitalWrite(red ,LOW);
      digitalWrite(green, LOW);
      }
    command = ""; // No repeats
  }
  // Read user input if available.
  if (Serial.available())
  {
    delay(1000); // The DELAY!
    mySerial.write(Serial.read());
  }

}// END loop()
