#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8


String str_buf;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

bool quit = false;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  // large block of text
  tft.fillScreen(ST77XX_BLACK);
  tft.setRotation(1);
  tft.println("Hello World!");

  Serial.println("Enter a String: ");
  Serial.println("Or type exit to quit ");

 }

void loop() {
  
  // put your main code here, to run repeatedly:
  while( Serial.available()==0 ){ // Wait for str input 
    }
   
  str_buf = Serial.readString();
  str_buf.trim(); // readString adds garbage to the end of the string

  if ( (str_buf=="exit")){
    quit=true;
    tft.println("Exiting");
  } if (quit) exit(0);

  if ( tft.getCursorY()>=128 ){ // gone past screen's ylimit
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(0,0);
  }

  tft.println(str_buf);





}


