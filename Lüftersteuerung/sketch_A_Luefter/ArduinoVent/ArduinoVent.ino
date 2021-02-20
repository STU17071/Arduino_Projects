#include <Wire.h>
#include "RTClib.h"
#define air1 7
#define air2 8


/*Declare Variables*/
RTC_DS3231 rtc;
const int timer = 3600000; //1 Hour in millseconds
const int minut = 60000; // 1 minute in milliseconds

void setup() {
  if (!rtc.begin()) {
    Serial.println("Keine Echtzeituhr gefunden!");
  }
  //Set Time and Date when File was compiled -> Loaded on arduino
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  pinMode(air1, OUTPUT);
  pinMode(air2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Bitrate eingestellt 9600");
  Serial.print(rtc.now().hour(), DEC);
  Serial.print(" : ");
  Serial.print(rtc.now().minute(), DEC);
  Serial.print(" : ");
  Serial.print(rtc.now().second(), DEC);
  Serial.println();
  Serial.println("_______________________________________________");
  Serial.println();
  delay(500); // wait for console opening
}

void loop() {
  if (rtc.now().hour() % 3 == 0)
  {
    int timeend = rtc.now().hour() + 2;
    //Serial.println("Hier");
    delay(500);
    while (rtc.now().hour() < timeend )
    {
      digitalWrite(air1, HIGH);
      digitalWrite(air2, HIGH);
      Serial.print(rtc.now().hour(), DEC);
      Serial.print(" => ");
      Serial.print(timeend, DEC);
      Serial.println();
      Serial.println("======================");
      delay(5000);
    }

  }
  else
  {
    digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);
    Serial.println("Lüfter aus");
    Serial.println("======================");
    delay(5000);
  }
}


//Alter Code
/*
  int timeend = rtc.now().hour() + 2;
  while (rtc.now().hour() % 3 == 0 && rtc.now().hour() <= timeend)
  {
    Serial.println("Pause =================>");
    Serial.println(rtc.now().hour());
    digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);

  }

  Serial.println("Läuft =================>");
  Serial.println(rtc.now().hour());
  digitalWrite(air1, HIGH);
  digitalWrite(air2, HIGH);
  //delay(timer);

*/
