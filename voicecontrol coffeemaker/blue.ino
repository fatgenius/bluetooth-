#include <SoftwareSerial.h>
SoftwareSerial bluetooth(11,10);
String inputString="";
char junk;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(115200);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(bluetooth.available()){
  while(bluetooth.available())
    {
      char inChar = (char)bluetooth.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
 bluetooth.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
    if(inputString == "a"){         //in case of 'a' turn the LED on
      digitalWrite(8, HIGH);  
    }else if(inputString == "b"){   //incase of 'b' turn the LED off
      digitalWrite(8, LOW);
    }
    inputString = "";
  }
  Serial.flush();
}
