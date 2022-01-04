// Define variables 

int _input = A0;
int _powerSupply =2;
int _Humididy_relativ;

// Define constants
const int _dry = 975;
const int _wet = 475;
const int _too_dry_rel = 10;
const int _too_wet_rel = 50;



// no functions yet
void constants()
{
  // Define constants
  const int _dry = 975;
  const int _wet = 475;
  const int _too_dry_rel = 10;
  const int _too_wet_rel = 50;
}

void variables()
{
  // Define variables 
  int _input = A0;
  int _powerSupply =2;
  int _Humididy_relativ;
}



// Programm starts below
void setup() 
{
  Serial.begin(9600);           
  pinMode(_input, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(_powerSupply, OUTPUT);
  digitalWrite(_powerSupply, LOW);
  digitalWrite(LED_BUILTIN, LOW);  
}

void loop() 
{
  // Read & convert input values
  int _Humididy_raw = analogRead(_input);
  Serial.print("Humididy raw value: ");
  Serial.println(_Humididy_raw);

  int _Humididy_relativ = map(_Humididy_raw, _wet, _dry, 100, 0);
  Serial.print("Realtive Humidty /%: ");
  Serial.println(_Humididy_relativ);

  int _voltage_raw = digitalRead(_powerSupply);
  Serial.print("Power supply raw: ");
  Serial.println(_voltage_raw);

  float _voltage_normal = ((float)_voltage_raw*5);
  Serial.print("Normal Voltage /V: ");
  Serial.println(_voltage_normal);

  //Watering condition
  if (_Humididy_relativ <  _too_wet_rel && _Humididy_relativ > _too_dry_rel)
  {
    Serial.println ("Water level O.K. no watering");
  }

  else if (_Humididy_relativ < _too_dry_rel) 
  {
    Serial.println("Water level to low - starting water pump");
    digitalWrite(LED_BUILTIN, HIGH);  
    digitalWrite(_powerSupply, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);  
    digitalWrite(_powerSupply, LOW);

  }

  else if (_Humididy_relativ > _too_wet_rel)
  {
    Serial.println("Water level to high - check value in next few houres");
  }

  else
  {
    Serial.println("Water level not in Range");
  }

  
  // Wait
  delay(10000);
  Serial.println("");       //no content line


}