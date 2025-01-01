#include <Adafruit_NeoPixel.h>

#define PIN_A   8
#define PIN_B   A1
#define NUMPIXELS_A 10
#define NUMPIXELS_B 2

Adafruit_NeoPixel pixelsA(NUMPIXELS_A, PIN_A, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsB(NUMPIXELS_B, PIN_B, NEO_GRB + NEO_KHZ800);

const int colors[10][3] = {
  {255, 100, 203},  // Pink
  {0, 255, 0},      // Green
  {0, 0, 255},      // Blue
  {255, 255, 0},    // Yellow
  {0, 255, 255},    // Cyan
  {255, 0, 255},    // Magenta
  {255, 165, 0},    // Orange
  {128, 0, 128},    // Purple
  {255, 255, 255},  // White
  {255, 0, 0},      // Red
};

void setup() {
  pixelsA.begin();
  pixelsA.setBrightness(50);
  pixelsB.begin();
  pixelsB.setBrightness(50);
}

void loop() {
  pixelsA.clear();

  for (int i = 0; i < NUMPIXELS_A; i++) {
    pixelsA.setPixelColor(i, pixelsA.Color(colors[i][0], colors[i][1], colors[i][2]));
    pixelsA.show();
    colorWipe(pixelsB.Color(colors[i][0], colors[i][1], colors[i][2]), 50);
    delay(25);
  }
}

void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < pixelsB.numPixels(); i++) { 
    pixelsB.setPixelColor(i, color);   
    pixelsB.show(); 
    delay(wait);  
  }
}

