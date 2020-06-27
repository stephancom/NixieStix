// 888b    | ,e,          ,e,           ,d88~~\   d8   ,e,
// |Y88b   |  "  Y88b  /   "   e88~~8e  8888    _d88__  "  Y88b  /
// | Y88b  | 888  Y88b/   888 d888  88b `Y88b    888   888  Y88b/
// |  Y88b | 888   Y88b   888 8888__888  `Y88b,  888   888   Y88b
// |   Y88b| 888   /Y88b  888 Y888    ,    8888  888   888   /Y88b
// |    Y888 888  /  Y88b 888  "88___/  \__88P'  "88_/ 888  /  Y88b
// 
// Representing an integer comprised of nixie tubes

#pragma once

#include "BigNixie.h"
#include "SmallNixie.h"

#ifndef NixieStix_h
#define NixieStix_h

template <class T, int N>
class NixieStix {
public:
  NixieStix(unsigned int _x = 0, unsigned int _y = 0, unsigned int _space = 1):x(_x),y(_y),space(_space) {
    width = tubes[0].width();
    int xpos = x;
    // An amusing insanity - building the tubes from last to first positioned left to right
    // which makes this for loop looks so cool, and makes the math easier later.
    for(int i=N ; i-- ;) {
      tubes[i].init(xpos, y);
      xpos += tubes[i].width() + space;
    }
  };  
  void draw(int number)  {
    for(int i=0 ; i<N ; i++) {
      tubes[i].draw(number%10);
      number /= 10;
    }
  };

protected:
  T tubes[N];
  unsigned int x;
  unsigned int y;
  unsigned int space;
  unsigned int width;
};

#endif

