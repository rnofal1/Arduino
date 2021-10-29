#include <MKRIMU.h>
#include <Arduino_JSON.h>

long previousMillis = 0;       // last timechecked, in ms
int  samplePeriod = 1000 / 32; // 1000 / sample rate in HZ

void setup() {
  Serial.begin(9600);    // initialize serial communication

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU");
    while (1);
  }
}

// IMU data
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
  long currentMillis = millis();
  
  // if time passed output sensor value
  if (currentMillis - previousMillis >= samplePeriod) {
    if (IMU.eulerAnglesAvailable()) {
      previousMillis = currentMillis;
      updateSensorData();
    }
  }

}
