#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float h,t,f;

void setup() {
  Serial.begin(9600);
  Serial.println("Prueba de temperatura");
  dht.begin();

}

void loop() {
  delay(2000);
  h=dht.readHumidity();
  t=dht.readTemperature();
  f=dht.readTemperature(true);
   if(isnan(h)||isnan(t)||isnan(f))
    {
    Serial.println("Error en la medición");
    return;
    }
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.println(" *F\t");
}
