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
float sin8[NUMPIXELS][SPEEDRANGE];
void setup() {
  pixels.begin();
  for (int j = 0; j<SPEEDRANGE; j++){
    for (int i = 0; i<NUMPIXELS; i++) {
      sin8[i][j] = sin((i+j) *.8);
    }
  }
}

double LeftProgress = 0, RightProgress = 0;
void loop() {
  RobotState state = currentState();
  switch(state){
  case Driving:
    for(int j=0;j<NUMPIXELS;j++){
      for(int i=0;i<NUMPIXELS;i++){
      double left = sin8[i][LeftProgress];
      if (left < 0) left = 0;
      left *= left;
      double right = sin8[j][RightProgress];
      if (right < 0) right = 0;
      right *= right;
      pixels.setPixelColor(j, left * 100 ,0 , right *100);
    }
    }
     break;
   case Turning:
     break;
   case ArmMotion:
       for(int i = -1;i<NUMPIXELS;i++){
         pixels.setPixelColor(i,0,0,0);
         pixels.setPixelColor(i + 1,200,0,200);
         pixels.setPixelColor(i + 2,200,0,200);
         pixels.setPixelColor(i + 3,200, 0, 200);
         pixels.setPixelColor(i + 4,200,0,200);
         pixels.setPixelColor(i + 5,200,0,200);
         pixels.setPixelColor(i + 6,200,0,200);   
         pixels.setPixelColor(i + 7,200,0,200);
         pixels.setPixelColor(i + 8,200,0,200);
         pixels.setPixelColor(i + 9,200,0,200);
         pixels.setPixelColor(i + 10,0,0,0);
         pixels.show();
         tick(1);
       }
     break;
   case SensorScan:
       for(int i = -1;i<NUMPIXELS;i++){
         pixels.setPixelColor(i,0,0,0);
         pixels.setPixelColor(i + 1,200,0,0);
         pixels.setPixelColor(i + 2,200,0,0);
         pixels.setPixelColor(i + 3,200, 0, 0);
         pixels.setPixelColor(i + 4,200,0,0);
         pixels.setPixelColor(i + 5,200,0,0);
         pixels.setPixelColor(i + 6,200,0,0);   
         pixels.setPixelColor(i + 7,200,0,0);
         pixels.setPixelColor(i + 8,200,0,0);
         pixels.setPixelColor(i + 9,200,0,0);
         pixels.setPixelColor(i + 10,0,0,0);
         pixels.show();
         tick(1);
       }
      for(int i = NUMPIXELS-1;i>0;i--){
         pixels.setPixelColor(i,0,0,0);
         pixels.setPixelColor(i + 1,200,0,0);
         pixels.setPixelColor(i + 2,200,0,0);
         pixels.setPixelColor(i + 3,200, 0, 0);
         pixels.setPixelColor(i + 4,200,0,0);
         pixels.setPixelColor(i + 5,200,0,0);
         pixels.setPixelColor(i + 6,200,0,0);   
         pixels.setPixelColor(i + 7,200,0,0);
         pixels.setPixelColor(i + 8,200,0,0);
         pixels.setPixelColor(i + 9,200,0,0);
         pixels.setPixelColor(i + 10,0,0,0);
         pixels.show();
         tick(1); 
      }
      break;

    
    
  }
  RightProgress += rightMotorSpeed() / 2;
  LeftProgress += leftMotorSpeed() / 2;
  pixels.show();
  tick(1);
}
  

