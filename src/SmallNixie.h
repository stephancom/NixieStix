// ,d88~~\                         888 888 ~~~888~~~          888
// 8888    888-~88e-~88e   /~~~8e  888 888    888    888  888 888-~88e   e88~~8e
// `Y88b   888  888  888       88b 888 888    888    888  888 888  888b d888  88b
//  `Y88b, 888  888  888  e88~-888 888 888    888    888  888 888  8888 8888__888
//    8888 888  888  888 C888  888 888 888    888    888  888 888  888P Y888    ,
// \__88P' 888  888  888  "88_-888 888 888    888    "88_-888 888-_88"   "88___/
// 
// Representing a small nixie tube, 18x34 pixels
#pragma once

#include "NixieTube.h"

#ifndef SmallNixie_h
#define SmallNixie_h

class SmallNixie : public NixieTube {
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
