#include <Adafruit_CircuitPlayground.h>
float X, Y, Z;
int value;
bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}


//run the acceleromitor
void loop() {
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

//if the x acceleration is greater then 1 then plays a sound
if(X>1){
  CircuitPlayground.playTone(500, 100);
}

//prints the motions of xyz
  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);

  delay(300);

//detects if the buttons are press and what position theyre in
  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();
  
  //If left button is held plays tone
  Serial.print("Left Button: ");
  if (leftButtonPressed) {
    CircuitPlayground.playTone(550, 150);
  }
  //If right button is held plays tone
  Serial.print("   Right Button: ");
  if (rightButtonPressed) {
    CircuitPlayground.playTone(300, 200);
  }   


//set the value if the light sensor equl to a varable
  value = CircuitPlayground.lightSensor();
  //prints the value of the light sensor
  Serial.print("Light Sensor: ");
  Serial.println(value);
  
  delay(1000);

//turns off all the leds when light value is lower than 100
CircuitPlayground.clearPixels();
//if the light value is greater than 100 it turns on the leds 
  if(value>100){
   CircuitPlayground.setPixelColor(0, 255,   0,   0);
  CircuitPlayground.setPixelColor(1, 128, 128,   0);
  CircuitPlayground.setPixelColor(2,   0, 255,   0);
  CircuitPlayground.setPixelColor(3,   0, 128, 128);
  CircuitPlayground.setPixelColor(4,   0,   0, 255);
  
  CircuitPlayground.setPixelColor(5, 0xFF0000);
  CircuitPlayground.setPixelColor(6, 0x808000);
  CircuitPlayground.setPixelColor(7, 0x00FF00);
  CircuitPlayground.setPixelColor(8, 0x008080);
  CircuitPlayground.setPixelColor(9, 0x0000FF);

  }
}