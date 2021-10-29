#include <MKRIMU.h>
#include <Arduino_JSON.h>

long previousMillis = 0;       // last timechecked, in ms
int  samplePeriod = 1000 / 32; // 1000 / sample rate in HZ

void setup() {
  Serial1.begin(9600);    // initialize serial communication 115200
  while(!Serial1) {
    ;
  }
  if (!IMU.begin()) {
    Serial1.println("Failed to initialize IMU");
    while (1);
  }
}

void loop() {
  Serial1.print("A");
  delay(1);
}
/*

// IMU data
void updateSensorData() {
  float ex, ey, ez;
  float ax, ay, az;
 
  IMU.readEulerAngles(ex, ey, ez);
  IMU.readAcceleration(ax, ay, az);

  Serial1.flush();

  Serial1.print(ex);
  Serial1.print(" ");
  Serial1.print(ey);
  Serial1.print(" ");
  Serial1.print(ez);
  Serial1.print(" ");

  Serial1.print(ax);
  Serial1.print(" ");
  Serial1.print(ay);
  Serial1.print(" ");
  Serial1.print(az);
  Serial1.println("");

  //delay(100);
  
}

void loop() {
  long currentMillis = millis();
  /*
  // if time passed output sensor value
  if (currentMillis - previousMillis >= samplePeriod) {
    if (IMU.eulerAnglesAvailable()) {
      previousMillis = currentMillis;
      updateSensorData();
    }
  }
  */
  /*
  if (IMU.eulerAnglesAvailable()) {
      //previousMillis = currentMillis;
      updateSensorData();
  }

}
*/
