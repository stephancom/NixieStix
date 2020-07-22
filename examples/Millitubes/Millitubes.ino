//      e    e      ,e, 888 888 ,e,   d8            888
//     d8b  d8b      "  888 888  "  _d88__ 888  888 888-~88e   e88~~8e   d88~\
//    d888bdY88b    888 888 888 888  888   888  888 888  888b d888  88b C888
//   / Y88Y Y888b   888 888 888 888  888   888  888 888  8888 8888__888  Y88b
//  /   YY   Y888b  888 888 888 888  888   888  888 888  888P Y888    ,   888D
// /          Y888b 888 888 888 888  "88_/ "88_-888 888-_88"   "88___/  \_88P
// 
// by stephan.com 2020
// display milliseconds since start on nixie tubes

#include <M5StickC.h>
#include <NixieStix.h>

NixieStix <SmallNixie, 8> Millitubes(1,23,2);

void setup(void){ 
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setRotation(1);
}

void loop(void){
  Millitubes.draw(millis());
}
