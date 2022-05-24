// Script to measure the current humidity status in the earth
#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
#include <LCDIC2.h>

LCDIC2 lcd(0x27, 16, 2);

// void setup()
// {

// 	lcd.begin();
  
// 	lcd.backlight();
// 	lcd.print("Hello, MaxTechTV");
//   lcd.setCursor(0,1);
//   lcd.print("Viewers!");
//   delay(10000);
//   lcd.noBacklight();
// }

// Set I/O
int input = A0;
int powerSupply =2;

int Humididy_relativ;

// Define constants
const int DRY = 975;
const int WET = 475;
const int TOODRYREL = 10;
const int TOOWETREL = 50;


void setup() {
  Serial.begin(9600);           
  pinMode(powerSupply, OUTPUT);
  digitalWrite(powerSupply, HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  if (lcd.begin()) lcd.print("Hello, World!");
  delay(2000);
  lcd.clear();  
  lcd.print("Job is starting");
  delay(5000);
  lcd.clear();  
}


void loop() {
  // Function to measure humidity
  int humididyRaw = analogRead(input);
  Serial.print("Humididy raw value: ");
  Serial.println(humididyRaw);

  int humididyRelativ = map(humididyRaw, WET, DRY, 100, 0);
  Serial.print("Realtive Humidty /%: ");
  Serial.println(humididyRelativ);

  int voltageRaw = digitalRead(powerSupply);
  Serial.print("Power supply raw: ");
  Serial.println(voltageRaw);

  float voltageNormal = ((float)voltageRaw*5);
  Serial.print("Normal Voltage /V: ");
  Serial.println(voltageNormal);
  
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);  
  Serial.println("");
  delay(1000);

}
