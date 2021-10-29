#include <ArduinoBLE.h>
#include <MKRIMU.h>

long previousMillis = 0;
int samplePeriod = 1000 / 32;

BLEService newService("180A");

void setup() {
  Serial.begin(9600);
  while(!Serial); //start on open of serial monitor
  Serial.println("Serial started");
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");
    while (1);
  }
  BLE.setLocalName("MKR WIFI");
  BLE.setAdvertisedService(newService);

  BLE.addService(newService);

  BLE.advertise();
  Serial.println("BLE device waiting for connections...");
  
}

void updateSensorData() {
  float ex, ey, ez;
  float ax, ay, az;

  IMU.readEulerAngles(ex, ey, ez);
  IMU.readAcceleration(ax, ay, az);
  Serial.flush();
  
  Serial.print(ex);
  Serial.print(" ");
  Serial.print(ey);
  Serial.print(" ");
  Serial.print(ez);
  Serial.print(" ");

  Serial.print(ax);
  Serial.print(" ");
  Serial.print(ay);
  Serial.print(" ");
  Serial.print(az);
  Serial.println("");
  delay(50);
}

void loop() {
  
  BLEDevice central = BLE.central();

  if(central) {
    Serial.print("Connected to central:");
    Serial.println(central.address());

    digitalWrite(LED_BUILTIN,HIGH);
  }

  while(central.connected()) {
    long currentMillis = millis();

    if(currentMillis - previousMillis >= samplePeriod) {
      if(IMU.eulerAnglesAvailable()) {
        previousMillis = currentMillis;
        updateSensorData();    
      }
    }
  }
   //digitalWrite(LED_BUILTIN, LOW); // when the central disconnects, turn off the LED
   //Serial.print("Disconnected from central: ");
   //Serial.println(central.address());
}
