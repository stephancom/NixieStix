// 888~~\  ,e,       / ~~~888~~~          888
// 888   |  "  e88~88e    888    888  888 888-~88e   e88~~8e
// 888 _/  888 888 888    888    888  888 888  888b d888  88b
// 888  \  888 "88_88"    888    888  888 888  8888 8888__888
// 888   | 888  /         888    888  888 888  888P Y888    ,
// 888__/  888 Cb         888    "88_-888 888-_88"   "88___/
//              Y8""8D
// 
// Representing a large nixie tube, 35x67 pixels
#pragma once

#include "NixieTube.h"

#ifndef BigNixie_h
#define BigNixie_h

class BigNixie : public NixieTube {
public:
  int width();
  int height();
  uint16_t *digitImage(unsigned int n);
private:
  static const int www;
  static const int hhh;
  static const uint8_t *TubeFont[];
};

#endif
