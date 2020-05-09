#include <Wire.h>
#include "RTClib.h"
#define air1 7
#define air2 8


/*Declare Variables*/
RTC_DS3231 rtc;
/*char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};*/

/*running Vent Parameters*/
const unsigned long stunde = 3600000; // in seconds
const unsigned long minutes = 3600; // in seconds
int dauer = 2;
int pause = 1;
int ende = 0;
int nextday = 0;


void setup ()
{
  Serial.begin(9600);
  pinMode(air1, OUTPUT);
  pinMode(air2, OUTPUT);
  delay(3000); // wait for console opening

  //  if (! rtc.begin()) {
  //    Serial.println("Couldn't find RTC");
  //    while (1);
  //  }

  /*SET of the Date when File was last compiled*/
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));



  //ende = rtc.now().hour() + dauer;
  nextday = rtc.now().day() + 1;
}

void TimeStringOutput(DateTime Uhrzeit)
{
  String Timenow = String(String(Uhrzeit.hour(), DEC) + ':' + String(Uhrzeit.minute(), DEC) + ':' + String(Uhrzeit.second(), DEC));
  Serial.println(Timenow);
}


void loop ()
{
  ende = rtc.now().hour() + pause;
  /*Runs for X Hours and make a break for Y Hours*/

  /*Wenn derzeitige Uhrzeit größer oder gleich 22 Uhr ist*/
  if (rtc.now().hour() >= 22)
  {
    if (ende < 0)
    {
      ende = ende + 24;
    }
    //switchen
    ende = ende - 24;
    Serial.println(ende, DEC);
    while (rtc.now().day() < nextday && rtc.now().hour() != 0 && rtc.now().minute() != 0)
    {
      digitalWrite(air1, HIGH);
      digitalWrite(air2, HIGH);
      Serial.println("läuft ab 22 Uhr");
      Serial.println((String)ende);
    }
    digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);
    Serial.println("Ventilatoren aus 'in > 22 Uhr'");
    delay(pause * stunde);
    ende = rtc.now().hour() + dauer;
    nextday = rtc.now().day() + 1;
  }
  else
  {
    Serial.println("Gilt nur für den heutigen Tag" + rtc.now().day());
    //  //Gilt nur für den heutigen Tag
    while (rtc.now().hour() < ende)
    {
      //TimeStringOutput(rtc.now());
      digitalWrite(air1, HIGH);
      digitalWrite(air2, HIGH);
    }
    digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);
    // Serial.println("Ventilatoren sind heute " + (String)beginn + "aus");
    Serial.println("läuft nicht");
    delay(pause * stunde);
    ende = rtc.now().hour() + dauer;
    nextday = rtc.now().day() + 1;
  }
}
