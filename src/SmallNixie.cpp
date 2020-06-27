// ,d88~~\                         888 888 ~~~888~~~          888
// 8888    888-~88e-~88e   /~~~8e  888 888    888    888  888 888-~88e   e88~~8e
// `Y88b   888  888  888       88b 888 888    888    888  888 888  888b d888  88b
//  `Y88b, 888  888  888  e88~-888 888 888    888    888  888 888  8888 8888__888
//    8888 888  888  888 C888  888 888 888    888    888  888 888  888P Y888    ,
// \__88P' 888  888  888  "88_-888 888 888    888    "88_-888 888-_88"   "88___/
// 
// Representing a small nixie tube, 18x34 pixels

#include "SmallNixie.h"
#include "Tubes/vfd_18x34.c"

const uint8_t *SmallNixie::TubeFont[] = {
  vfd_18x34_0,vfd_18x34_1,vfd_18x34_2,vfd_18x34_3,vfd_18x34_4,
  vfd_18x34_5,vfd_18x34_6,vfd_18x34_7,vfd_18x34_8,vfd_18x34_9
  };

int SmallNixie::width() { return 18; }
int SmallNixie::height() { return 34; }
uint16_t *SmallNixie::digitImage(unsigned int digit) {
  return (uint16_t *)TubeFont[digit%10];
}

