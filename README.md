# NixieStix Library

By [stephan.com](mailto://stephan@stephan.com)
shamelessly stolen from [McOrts/M5StickC_Nixie_tube_Clock](https://github.com/McOrts/M5StickC_Nixie_tube_Clock)

This library allows for the display of integers in the style of a [Nixie tube](https://en.wikipedia.org/wiki/Nixie_tube).  It is designed to work only with the wonderful [M5StickC](https://m5stack.com/products/stick-c) ESP32 protyping system, which includes a screen, buttons, wifi, bluetooth, accelerometer and more for around $10.  It's small enough to be worn as a wristwatch.

## Documentation

Simply include the library with 
```cpp
#include "NixieStix.h"
```
and you may now include a sequence of Nixie tubes your application by declaring it like so:
```cpp
NixieStix <[tubetype], [digits]> [varname]([xstart],[ypos],[space]);
```
Where `tubetype` is either `SmallNixie` (18x34) or `BigNixie` (35x67), `digits` is the number of digits in the set, `xstart` and `ypos` are where to begin drawing, and `space` is how many pixels to leave between digits.  For example, to get a long counter - big enough to fill the M5StickC screen horizontally - you might use:
```cpp
NixieStix <SmallNixie, 8> Counter(1, 23, 2);
```
Which creates an 8 digit string of small tubes, which starts drawing at (1,23) with a 2-pixel space between tubes.

Then, elsewhere in your code, you would do:
```cpp
Counter.draw(12345);
```
and the tubes would show "00012345"

You may also use tubes individually, or create your own sets by inheriting from the `NixieTube` class.  This could be generalized to work with any display of image-based digits.

## Dependencies

* [M5StickC](https://github.com/m5stack/M5StickC)

## Update the Nixie Tube Images

[McOrts original repo](https://github.com/McOrts/M5StickC_Nixie_tube_Clock) includes the lcd-image-converter.exe program used to convert the images - I don't want to steal his thunder from having done the hard work of this, I just refactored it into a handy library.  If you're interested, I'd recommend starting there, which also contains further instructions on getting things running for the M5StickC.  

## Future expansion

* todo "blank" tube
* todo "negative" tube for signed integers
* todo support TTGO or other platforms
