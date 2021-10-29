
void setup()
{
  Serial.begin(9600);
  while (!Serial) delay(1);
  Serial.println("Started Serial");
  pinMode(1, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(1, HIGH);
  Serial1.begin(38400);
  while (!Serial1) delay(1);
  Serial.println("Enter AT commands:");
  
  //Serial.println("Enter AT commands:");
  //Serial1.begin(38400);  // HC-05 default speed in AT command mode
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (Serial1.available())
    Serial.write(Serial1.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    Serial1.write(Serial.read());
}

/*
String readString;

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(1);
  Serial.println("serial test 0021"); // so I can keep track of what is loaded
}

void loop() {

  while (Serial.available()) {
    delay(2);  //delay to allow byte to arrive in input buffer
    char c = Serial.read();
    readString += c;
  }

  if (readString.length() >0) {
    Serial.println(readString);

    readString="";
  } 
}
*/
