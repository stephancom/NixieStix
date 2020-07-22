//     888                           d8   ,e,         888   _
//     888  e88~-_  Y88b  /  d88~\ _d88__  "   e88~~\ 888 e~ ~
//     888 d888   i  Y888/  C888    888   888 d888    888d8b
//     888 8888   |   Y8/    Y88b   888   888 8888    888Y88b
// |   88P Y888   '    Y      888D  888   888 Y888    888 Y88b
//  \__8"   "88_-~    /     \_88P   "88_/ 888  "88__/ 888  Y88b
//                  _/
// 
// by stephan.com 2020
// Displaying joystick hat x/y/button data on nixie tubes

#include <M5StickC.h>
#include <NixieStix.h>
#include <Wire.h>

#define JOY_ADDR 0x38
int8_t x_data,y_data,button_data;

NixieStix <SmallNixie, 3> JoyX(20, 0,2);
NixieStix <SmallNixie, 3> JoyY(20,40,2);
NixieStix <BigNixie, 1> Button(20,80,2);

void setup() {
  M5.begin();
  Wire.begin(0, 26, 100000);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setRotation(0);

  JoyX.draw(0);
  JoyY.draw(0);
  Button.draw(0);
}

void loop() {
  Wire.beginTransmission(JOY_ADDR);
  Wire.write(0x02); 
  Wire.endTransmission();
  Wire.requestFrom(JOY_ADDR, 3);
  if (Wire.available()) {
    x_data = Wire.read();
    y_data = Wire.read();
    button_data = Wire.read();
  }

  Button.draw(button_data);
  M5.lcd.drawLine(5,17,15,17, x_data < 0 ? YELLOW : BLACK );
  M5.lcd.drawLine(5,18,15,18, x_data < 0 ? ORANGE : BLACK );
  JoyX.draw(abs(x_data));
  M5.lcd.drawLine(5,57,15,57, y_data < 0 ? YELLOW : BLACK );
  M5.lcd.drawLine(5,58,15,58, y_data < 0 ? ORANGE : BLACK );
  JoyY.draw(abs(y_data));

  delay(33);
}
