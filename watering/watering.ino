// Define variables
int sensorOut = A0;
int humidityRelative = 0;
int powerPump = 2;

// Define constants
const int dry = 975;
const int wet = 475;
const int tooDryRel = 10;
const int tooWetRel = 50;


// Program execution starts below

void setup() {
  Serial.begin(9600);           
  pinMode(sensorOut, INPUT);
  pinMode(powerPump, OUTPUT);
  digitalWrite(powerPump, LOW);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() 
{
  // Read & convert input values
  int humidityRaw = analogRead(sensorOut);
  Serial.print("humidity raw value: ");
  Serial.println(humidityRaw);

  int humidityRelative = map(humidityRaw, wet, dry, 100, 0);
  Serial.print("Relative humidity: ");
  Serial.print(humidityRelative);
  Serial.println(" %");


  //Watering condition
  if (humidityRelative <  tooWetRel && humidityRelative > tooDryRel) {
    Serial.println ("Water level O.K. no watering");
  }

  else if (humidityRelative < tooDryRel) {
    Serial.println("Water level to low - starting water pump");
    //-digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(powerPump, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);  
    digitalWrite(powerPump, LOW);
  }

  else if (humidityRelative > tooWetRel) {
    Serial.println("Water level to high - check value in next few hours");
  }

  else {
    Serial.println("Water level not in Range - check conditions");
  }

  // Wait
  delay(5000);
  Serial.println("");       //no content line


}