#include "DHT.h"
#define DHTTYPE DHT11 
#define dhtpin 2
#define air 6
DHT dht(dhtpin, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  pinMode(air, OUTPUT);
  Serial.begin(9600); 
  dht.begin(); // Damit wird der Sensor aktiviert.
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float feuchtigkeit = dht.readHumidity(); // Liest die Feuchtigkeit des Sensors.
  float temperatur = dht.readTemperature(); // Liest die Feuchtigkeit des Sensors.
  delay(1000);
  while(temperatur >= 20.0f) // Solange die Temperatur über 20 Grad ist läuft der Lüfter.
  {
    luefter();
  Serial.print("Luftfeuchtigkeit: ");
  Serial.println(feuchtigkeit);
  Serial.print("Temperatur: ");
  Serial.println(temperatur);
  delay(1000);
  }
  digitalWrite(air,LOW);
  Serial.println("Temperatur ist unter dem ");
  Serial.print("Temperatur: ");
  Serial.println(temperatur);
  delay(500);
}


void luefter()
{
  digitalWrite(air, HIGH);
}
