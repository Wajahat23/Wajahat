/*AUTO_ON_STREET_LIGHT
  CREATED BY AMEYA ANGADI
  LAST EDITED ON  - 19/08/2021
  THIS CODE IS AN EXAMPLE OF AN AUTO ON-OFF STREET LIGHT WHICH AUTOMATICALLY  SWITCHES ON WHEN IT GETS DARK AND REMAINS ON UNTILL IT DETECTS ENOUGH LIGHT.
*/

const  int ledpin = 13; // ledpin and lightpin are not changed throughout the process
const  int lightpin = A2;
const int LIGHT = 10; // sets LIGHT value for light sensor
void  setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(lightpin,  INPUT);
}
void loop() {
  int lightsens = analogRead(lightpin); // reads  analog data from light sensor
  if (lightsens < LIGHT) {
    digitalWrite(ledpin,  HIGH); //turns led on
    delay(1500);
  }
  else {
    digitalWrite(ledpin,  LOW);
  }
}
