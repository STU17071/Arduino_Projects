#include <Wire.h>
#include "RTClib.h"
#define air1 7
#define air2 8


/*Declare Variables*/
RTC_DS3231 rtc;
/*char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};*/

/*running Vent Parameters*/
const unsigned long stunde = 3600; //min
const unsigned long seconds = 1000; // 1min = 1000 millisekunden
int dauer = 2;
int pause = 1;
int beginn = 0;
int ende = 0;
int nextday = 0;
DateTime current = new DateTime();
/*Wochentage*/


/*Sonntag*/
int sonbegin = 6;
int sonend = 22;

/*Montag*/
int mbegin = 6;
int mend = 22;

/*Dienstag*/
int dibegin = 6;
int diend = 22;

/*Mittwoch*/
int mitbegin = 6;
int mitend = 22;

/*Donnerstag*/
int dobegin = 6;
int doend = 22;

/*Freitag*/
int frbegin = 6;
int frend = 22;

/*Samstag*/
int sambegin = 6;
int samend = 22;

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


  current = rtc.now();
//  beginn = current.hour();
//  ende = beginn + dauer;
  nextday = current.day() + 1;
}

void TimeStringOutput(DateTime Uhrzeit)
{
  String Timenow = String(String(Uhrzeit.hour(), DEC) + ':' + String(Uhrzeit.minute(), DEC) + ':' + String(Uhrzeit.second(), DEC));
  Serial.println(Timenow);
}


void loop ()
{
  /*Runs for X Hours and make a break for Y Hours*/
  current = rtc.now();
  TimeStringOutput(current);
  Serial.println((String)nextday);
  if (beginn >= 22)
  {
    //switchen
    ende = ende - 24;
    Serial.println(ende, DEC);
    while (current.day() < nextday && current.hour() != 0)
    {
      digitalWrite(air1, HIGH);
      digitalWrite(air2, HIGH);
      Serial.println("läuft ab 22 Uhr");
      //Serial.println((String)beginn + " - " + (String)ende);
    }
    digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);
    Serial.println("Ventilatoren aus");
    delay(100000);
    Serial.println("hello");
    beginn = current.hour();
    ende = beginn + dauer;
    nextday = current.day() + 1;
    //delay(pause * stunde * seconds);
  }
  else
  {
    Serial.println("Gilt nur für den heutigen Tag");
    //  //Gilt nur für den heutigen Tag
    while (current.hour() < ende)
    {
      digitalWrite(air1, HIGH);
      digitalWrite(air2, HIGH);
      Serial.println("läuft tagsüber bis 22 - " + (String)ende);
      delay(100000);
      //Serial.println((String)beginn + " - " + (String)ende);
    }
    digitalWrite(air1, LOW);
    digitalWrite(air2, LOW);
    Serial.println("Ventilatoren sind heute " + (String)beginn + "aus");
    delay(100000);
    //delay(pause * stunde * seconds);
    beginn = current.hour();
    ende = beginn + dauer;
    nextday = current.day() + 1;
  }
}


/*Methods for the Ventilators*/

//void Wochentage()
//{
//DateTime now = rtc.now();
//  switch (now.dayOfTheWeek())
//  {
//    case 0:
//      digitalWrite(air1, Sunday(now));
//      digitalWrite(air2, Sunday(now));
//      break;
//    case 1:
//      digitalWrite(air1, Monday(now));
//      digitalWrite(air2, Monday(now));
//      break;
//    case 2:
//      digitalWrite(air1, Tuesday(now));
//      digitalWrite(air2, Tuesday(now));
//      break;
//    case 3:
//      digitalWrite(air1, Wednesday(now));
//      digitalWrite(air2, Wednesday(now));
//      break;
//    case 4:
//      digitalWrite(air1, Thursday(now));
//      digitalWrite(air2, Thursday(now));
//      break;
//    case 5:
//      digitalWrite(air1, Friday(now));
//      digitalWrite(air2, Friday(now));
//      break;
//    case 6:
//      digitalWrite(air1, Saturday(now));
//      digitalWrite(air2, Saturday(now));
//      break;
//  }
//}



//boolean Sunday(DateTime now)
//{
//  while (now.hour() > sonbegin && now.hour() < sonend)
//  {
//    Serial.println("not run");
//    return false;
//  }
//  Serial.println("run");
//  return true;
//}
//
//
//boolean Monday(DateTime now)
//{
//  while (now.hour() > mbegin && now.hour() < mend)
//  {
//    Serial.println("not run");
//    return false;
//  }
//  Serial.println("run");
//  return true;
//}
//
//boolean Tuesday(DateTime now)
//{
//  while (now.hour() > dibegin && now.hour() < diend)
//  {
//    Serial.println("not run");
//    return false;
//  }
//  Serial.println("run");
//  return true;
//}
//
//boolean Wednesday(DateTime now)
//{
//  while (now.hour() > mitbegin && now.hour() < mitend)
//  {
//    Serial.println("not run");
//    return false;
//  }
//  Serial.println("run");
//  return true;
//}
//
//
//boolean Thursday(DateTime now)
//{
//  while (now.hour() > dobegin && now.hour() < doend)
//  {
//    Serial.println("not run");
//    return false;
//  }
//  Serial.println("run");
//  return true;
//}
//
//boolean Friday(DateTime now)
//{
//  while (now.hour() > frbegin && now.hour() < frend)
//  {
//    Serial.println("not run");
//    return false;
//  }
//  Serial.println("run");
//  return true;
//}
//
//boolean Saturday(DateTime now)
//{
//  while (now.hour() > sambegin && now.hour() < samend)
//  {
//    Serial.println("not run");
//    return false;
//  }
//  Serial.println("run");
//  return true;
//}
