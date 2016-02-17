// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include "robot_state.h"


// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            8

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      275

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

double LeftProgress = 0, RightProgress = 0;

void loop() {
  RobotState state = currentState();
  switch(state){
  case Driving:
    for(int j=0;j<NUMPIXELS;j++){
      double left = sin((j+LeftProgress)*.5);
      if (left < 0) left = 0;
      left *= left;
      double right = sin((j+RightProgress)*.5);
      if (right < 0) right = 0;
      right *= right;
      pixels.setPixelColor(j, left * 100 ,0 , right *100);
    }
    break;
  case Turning:
    
    
  }
  RightProgress += rightMotorSpeed() / 100;
  LeftProgress += leftMotorSpeed() / 100;
  pixels.show();
  tick(1);
}
  

