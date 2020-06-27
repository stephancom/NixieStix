// 888b    | ,e,          ,e,           ~~~888~~~          888
// |Y88b   |  "  Y88b  /   "   e88~~8e     888    888  888 888-~88e   e88~~8e
// | Y88b  | 888  Y88b/   888 d888  88b    888    888  888 888  888b d888  88b
// |  Y88b | 888   Y88b   888 8888__888    888    888  888 888  8888 8888__888
// |   Y88b| 888   /Y88b  888 Y888    ,    888    888  888 888  888P Y888    ,
// |    Y888 888  /  Y88b 888  "88___/     888    "88_-888 888-_88"   "88___/
// 
// Abstract base class representing a Nixie tube
#pragma once

#include <M5StickC.h>

#ifndef NixieTube_h
#define NixieTube_h

class NixieTube {
public:
  void init(int xpos, int ypos);
  virtual int width() = 0;
  virtual int height() = 0;
  virtual void draw(unsigned int digit);
  virtual uint16_t *digitImage(unsigned int n);

protected:
  NixieTube() {};
  unsigned int xpos;
  unsigned int ypos;
};

#endif
