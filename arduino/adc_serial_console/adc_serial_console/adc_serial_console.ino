int r = 2;
int g = 3;
int b = 4;


void setup() {
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

boolean pin = false;

void loop() {
  int sensorValue = analogRead(A0);

  
  digitalWrite(r, HIGH); //включаем красный
  delay(sensorValue); 
  digitalWrite(g, HIGH); //включаем зеленый
  delay(sensorValue); 
  digitalWrite(r, LOW); //выключаем красный
  delay(sensorValue); 
  digitalWrite(b, HIGH); //включаем синий
  delay(sensorValue); 
  digitalWrite(g, LOW); //выключаем зеленый
  delay(sensorValue);
  digitalWrite(b, LOW); //выключаем синий

  
  Serial.println(sensorValue);
  //delay(1);        // delay in between reads for stability
}
