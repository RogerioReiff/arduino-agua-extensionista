#include <dht11.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define WS_POWER_PIN 7
#define WS_SIGNAL_PIN A5
#define DHT11PIN 4
#define WT_SENSOR_PIN 13

OneWire oneWire(WT_SENSOR_PIN); //setup do onewire
DallasTemperature tempSensor(&oneWire); //passa o onewire para a biblioteca Dallas

float tempCelsius; //temperatura em Celsius
float tempFahrenheit; //temperature em Fahrenheit

int value = 0; //valor do sensor

void setup() {
  Serial.begin(9600);
  //<<---------------------WATER LEVEL SENSOR--------------------->>
  pinMode(WS_POWER_PIN, OUTPUT); 
  digitalWrite(WS_POWER_PIN, LOW); //desliga o sensor

  //<<---------------------WATER TEMPERATURE SENSOR--------------------->>
  tempSensor.begin();

}

void loop() {

  //<<---------------------WATER LEVEL SENSOR--------------------->>
  digitalWrite(WS_POWER_PIN, HIGH); //liga o sensor
  delay(10);
  value = analogRead(WS_SIGNAL_PIN); // ler o valor analogo do sensor
  delay(10);
  digitalWrite(WS_POWER_PING, LOW);

  Serial.print("Valor do sensor: ");
  Serial.println(value);

  delay(1000);

  //<<---------------------DHT11--------------------->>
  Serial.println();
  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidade (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperatura (C): ");
  Serial.println((float)DHT11.temperature, 2);
  delay(2000);

  //<<---------------------WATER TEMPERATURE SENSOR--------------------->>
  tempSensor.requestTemperatures(); // pede as temperaturas
  tempCelsius = tempSensor.getTempCByIndex(0); //ler a temperatura em celsius
  tempFahrenheit = TempCelsius * 9 /5 + 32; //converte de C para F

  Serial.print("Temperatura: ");
  Serial.print(tempCelsius);
  Serial.print("°C");
  Serial.print("~");
  Serial.print(tempFahrenheit);
  Serial.print("°F");

  delay(1000);


}
