#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8


String str_buf;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  // large block of text
  tft.fillScreen(ST77XX_BLACK);
  tft.println("Hello Word!");

 }

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println();
    while( Serial.available()) //Wait for str input
  str_buf = Serial.readString();


}
