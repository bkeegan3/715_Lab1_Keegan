# 715_Lab1_Keegan

## Requirements
Develop a C or C++ application which executes on an Arduino and displays a user typed string. The first option to display the string is through morse code on a LED. The second option to display the string is with an LCD screen. If the morse code option is selected, all basic Latin letters(A-Z) and Arabic numerals(0-9) must have a morse code implementation. If a sentinel is entered the software will exit.

## Design

### Hardware
For this lab I'm going to use the built-in serial port of the Arduino to take in a user typed string. To display that string, I'm going to reuse a [1.8" TFT display](https://www.adafruit.com/product/358) that I have from another course. The display uses SPI to communicate to the Arduino.

![alt text](https://github.com/bkeegan3/715_Lab1_Keegan/blob/master/HW%20Diagram.drawio.png)

| Arduino Pins  | TFT 1.8" LCD Pins |
| ------------- | ------------------|
| Digital 11    | MOSI              |
| Digital 13    | SCK               |
| Digital 10    | CS                |
| Digital 9     | RST               |
| Digital 8     | DC                |
| 5V            | VCC               |
| GND           | GND               |

### Software
For the software design I'm going to follow the instructions from the project and use a Round Robbin loop design. The code will wait for the user to input a string. After the string has been entered , if the string is not a sentinel, it will be displayed on the LCD screen. 

Libraries used
* [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
* [Adafruit-ST7735-Library](https://github.com/adafruit/Adafruit-ST7735-Library)

[Software](https://github.com/bkeegan3/715_Lab1_Keegan/blob/master/Mod1.ino)
