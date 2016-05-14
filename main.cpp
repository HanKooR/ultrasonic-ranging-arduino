#include "Arduino.h"
#include "NewPing.h"
//#include <LiquidCrystal.h>
#define TRIGGER_PIN  11
#define ECHO_PIN     12
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
unsigned long StartTime;
unsigned long ElapsedTime;
double Frequency;
unsigned long counter;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
//LiquidCrystal lcd(10, 9, 5, 4, 3, 2);
void setup() {
  //lcd.begin(16, 2);
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  counter = 0;
  //lcd.print("hello, world!");
}
void loop() {
  StartTime = millis();
  delay(30);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print(counter);
  Serial.print(". Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print("cm. At ");
  ElapsedTime = millis()-StartTime;
  Frequency = 1/(double)((double)ElapsedTime/(double)1000);
  Serial.print(Frequency);
  Serial.print("Hz.");
  Serial.print(" Time btw. two measures is: ");
  Serial.print(ElapsedTime);
  Serial.println("ms");
  counter++;
}
