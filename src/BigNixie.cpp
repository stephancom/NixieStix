// 888~~\  ,e,       / ~~~888~~~          888
// 888   |  "  e88~88e    888    888  888 888-~88e   e88~~8e
// 888 _/  888 888 888    888    888  888 888  888b d888  88b
// 888  \  888 "88_88"    888    888  888 888  8888 8888__888
// 888   | 888  /         888    888  888 888  888P Y888    ,
// 888__/  888 Cb         888    "88_-888 888-_88"   "88___/
//              Y8""8D
// 
// Representing a large nixie tube, 35x67 pixels

#include "BigNixie.h"
#include "Tubes/vfd_35x67.c"

const uint8_t *BigNixie::TubeFont[] = {
  vfd_35x67_0,vfd_35x67_1,vfd_35x67_2,vfd_35x67_3,vfd_35x67_4,
  vfd_35x67_5,vfd_35x67_6,vfd_35x67_7,vfd_35x67_8,vfd_35x67_9
  };

int BigNixie::width() { return 35; }
int BigNixie::height() { return 67; }
uint16_t *BigNixie::digitImage(unsigned int digit) {
  return (uint16_t *)TubeFont[digit%10];
}
