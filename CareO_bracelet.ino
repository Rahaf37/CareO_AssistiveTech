#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_WIDTH 128
#define OLED_HEIGHT 64

#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);

int ctr = 1;
const int button    = 2;
const int button2    = 4;
const int signal    = 7;

#define OLED_RESET 4
//Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

const unsigned char toilet [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x63, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0x8f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x07, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x0e, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x1c, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x18, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x39, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x31, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x73, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x63, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xe3, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xe7, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xe7, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xc7, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xc7, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xcf, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xcf, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xcf, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xcf, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xcf, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xcf, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xcf, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xcf, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xc7, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xe7, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xe7, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x67, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x63, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x33, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x33, 0xfe, 0x07, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x11, 0xf8, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x09, 0xc0, 0x7f, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x04, 0x03, 0xf0, 0x01, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x1f, 0xc0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x0f, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x02, 0x3f, 0x80, 0x00, 0x07, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x03, 0x1f, 0x80, 0x00, 0x03, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x03, 0x8f, 0xe0, 0x00, 0x07, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x03, 0xc7, 0xf0, 0x00, 0x0f, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xe1, 0xff, 0x80, 0xff, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xf0, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xfc, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0x01, 0xff, 0xf8, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x0f, 0x80, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0x00, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
};


const unsigned char sleep [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x0f, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x0f, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x1f, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x3f, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xfe, 0x38, 0x7f, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xf0, 0x30, 0xff, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xfe, 0x60, 0x7f, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xfc, 0xe0, 0x0f, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xf9, 0xff, 0xdf, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0x38, 0x1f, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0x70, 0x3f, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xf8, 0x7e, 0x7f, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0x71, 0x80, 0x00, 0x1f, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0x60, 0x80, 0x00, 0x0f, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0x40, 0x00, 0x00, 0x07, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0x40, 0x80, 0x00, 0x07, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xf8, 0x60, 0x80, 0x00, 0x03, 0x3f, 0x80, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xf8, 0x71, 0x80, 0x00, 0x06, 0x3f, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xf8, 0x7f, 0xff, 0xff, 0xfe, 0x3f, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x78, 0x7f, 0xff, 0xff, 0xfe, 0x3c, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x38, 0x7f, 0xff, 0xff, 0xfe, 0x38, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x18, 0x7f, 0xff, 0xff, 0xfe, 0x38, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
};

const unsigned char food [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x2d, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x2d, 0x00, 0x00, 0x03, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x2d, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x2d, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x2d, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x2d, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x2d, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x2d, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x2d, 0x80, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x2d, 0x80, 0x3f, 0xff, 0xf8, 0x0f, 0xff, 0xfe, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x2d, 0x80, 0x7f, 0xff, 0xc0, 0x01, 0xff, 0xfe, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x2d, 0x80, 0x7f, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x2d, 0x80, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0xff, 0x81, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xc0, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0xff, 0x81, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0xff, 0x83, 0xff, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0xff, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0xff, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf0, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0xff, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xfe, 0x07, 0xfe, 0x00, 0x78, 0x0f, 0x00, 0x3f, 0xf0, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x0f, 0xfe, 0x01, 0xfe, 0x3f, 0xc0, 0x3f, 0xf8, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3c, 0x0f, 0xfc, 0x03, 0xff, 0x7f, 0xe0, 0x1f, 0xf8, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3c, 0x0f, 0xfc, 0x07, 0xff, 0xff, 0xf0, 0x1f, 0xf8, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3c, 0x0f, 0xfc, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xf8, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3c, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xfc, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3c, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xfc, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xfc, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xfc, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xfc, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xfc, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xf8, 0x0f, 0xfc, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x1f, 0xf8, 0x07, 0xff, 0xff, 0xf0, 0x0f, 0xfc, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x1f, 0xf8, 0x03, 0xff, 0xff, 0xe0, 0x0f, 0xfc, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x1f, 0xf8, 0x01, 0xff, 0xff, 0xc0, 0x0f, 0xfc, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x0f, 0xfc, 0x00, 0xff, 0xff, 0x80, 0x1f, 0xf8, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x0f, 0xfc, 0x00, 0xff, 0xff, 0x00, 0x1f, 0xf8, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x0f, 0xfc, 0x00, 0x7f, 0xfe, 0x00, 0x1f, 0xf8, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x0f, 0xfe, 0x00, 0x1f, 0xfc, 0x00, 0x3f, 0xf8, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x07, 0xfe, 0x00, 0x0f, 0xf8, 0x00, 0x3f, 0xf0, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x07, 0xff, 0x00, 0x03, 0xe0, 0x00, 0x7f, 0xf0, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x07, 0xff, 0x00, 0x01, 0xc0, 0x00, 0x7f, 0xf0, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x01, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x01, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xc0, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x7f, 0xff, 0xc0, 0x01, 0xff, 0xfe, 0x00, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x3f, 0xff, 0xfc, 0x1f, 0xff, 0xfe, 0x00, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  Serial.begin(9600);

  pinMode(button,INPUT);
  pinMode(button2,INPUT);
  pinMode(signal,OUTPUT);

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Welcome");

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 17);
  display.println("This is");
  display.println("a Smart");
  display.println("Bracelet");

  display.display();

  delay(1000);

   display.clearDisplay();
}

void loop() {

 
  int  NextButton = digitalRead(button);
  int  ChooseButton = digitalRead(button2);


 
  if (NextButton == HIGH)
  {
    if (ctr == 1)
    {
      display.clearDisplay();    
      display.begin(SSD1306_SWITCHCAPVCC,0x3C);
      display.clearDisplay();
      display.drawBitmap(0, 0, food, 128, 64, WHITE);
      display.display();

      ctr ++;
    }
    else if (ctr == 2)
    {
      display.clearDisplay();    
      display.begin(SSD1306_SWITCHCAPVCC,0x3C);
      display.clearDisplay();
      display.drawBitmap(0, 0, sleep, 128, 64, WHITE);
      display.display();

      ctr ++;
    }
    else
    {
      display.clearDisplay();    
      display.begin(SSD1306_SWITCHCAPVCC,0x3C);
      display.clearDisplay();
      display.drawBitmap(0, 0, toilet, 128, 64, WHITE);
      display.display();

      ctr = 1;
    }
  }
  else if (ChooseButton == HIGH)
  {
      digitalWrite(signal, HIGH);
      delay(500);
      digitalWrite(signal, LOW);
      delay(500);
      digitalWrite(signal, HIGH);
      delay(500);
      digitalWrite(signal, LOW);
  }
}
