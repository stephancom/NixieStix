// 888b    | ,e,          ,e,           ~~~888~~~          888
// |Y88b   |  "  Y88b  /   "   e88~~8e     888    888  888 888-~88e   e88~~8e
// | Y88b  | 888  Y88b/   888 d888  88b    888    888  888 888  888b d888  88b
// |  Y88b | 888   Y88b   888 8888__888    888    888  888 888  8888 8888__888
// |   Y88b| 888   /Y88b  888 Y888    ,    888    888  888 888  888P Y888    ,
// |    Y888 888  /  Y88b 888  "88___/     888    "88_-888 888-_88"   "88___/
// 
// Abstract base class representing a Nixie tube

#include "NixieTube.h"

void NixieTube::init(int _xpos, int _ypos) {
  xpos = _xpos;
  ypos = _ypos;
}

void NixieTube::draw(unsigned int digit) {
  M5.Lcd.pushImage(xpos, ypos, width(), height(), digitImage(digit));
}
