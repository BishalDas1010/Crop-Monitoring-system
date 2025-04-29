#include <DHT.h>

// Define pins
#define DHTPIN 2         
#define DHTTYPE DHT11    

#define RAIN_SENSOR_PIN A0 
#define SOIL_SENSOR_PIN A1 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Important: Baudrate must match with ESP8266 serial reading
  dht.begin();
  delay(2000); 
}

void loop() {
  // Fetch data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int rainValue = analogRead(RAIN_SENSOR_PIN);
  int soilMoistureValue = analogRead(SOIL_SENSOR_PIN);

  // Send data only if DHT read is valid
  if (!isnan(temperature) && !isnan(humidity)) {
    // Format: temp,humidity,rain,soil
    Serial.print(temperature);
    Serial.print(",");
    Serial.print(humidity);
    Serial.print(",");
    Serial.print(rainValue);
    Serial.print(",");
    Serial.println(soilMoistureValue);
  } else {
    Serial.println("Error reading DHT11!");
  }

  delay(2000); 
}
