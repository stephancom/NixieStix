//  e88~-_                               d8
// d888   \  e88~-_  888  888 888-~88e _d88__  e88~~8e  888-~\
// 8888     d888   i 888  888 888  888  888   d888  88b 888
// 8888     8888   | 888  888 888  888  888   8888__888 888
// Y888   / Y888   ' 888  888 888  888  888   Y888    , 888
//  "88_-~   "88_-~  "88_-888 888  888  "88_/  "88___/  888
// 
// by stephan.com 2020
// a trivial nixie tube counter
// counts tenths of seconds, pausing when the M5 button is pressed.
// the number of milliseconds since pressing the button is shown
// until the button is released.

#include <M5StickC.h>
#include <NixieStix.h>

NixieStix <SmallNixie, 8> Counter(1,23,2);
unsigned long int count = 0;
boolean do_count = true;

void setup(void){ 
  M5.begin();
  pinMode(M5_BUTTON_HOME, INPUT);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setRotation(1);
}

void loop(void){
  if(do_count) { count++; }

  if(digitalRead(M5_BUTTON_HOME) == LOW){
    int startButton = millis();
    while(digitalRead(M5_BUTTON_HOME) == LOW) Counter.draw(millis() - startButton);
    do_count = !do_count;
  }
  Counter.draw(count);

  delay(100);
}
