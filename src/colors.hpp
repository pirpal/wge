#ifndef COLORS_HPP_
#define COLORS_HPP_

/**
 * @file colors.hpp
 */

#include <stdint.h>
#include <map>

#define MY_UTILS_IMPLEMENTATION
#include "my_utils.hpp"


typedef uint32_t Color32;
typedef std::map<unsigned int, Color32> Palette;


typedef enum rgbaChannel {
  _chan_ALPHA = 0,
  _chan_BLUE  = 1,
  _chan_GREEN = 2,
  _chan_RED   = 3,
} rgbaChan;


ui8 get_channel(const Color32 color, const rgbaChan chan);


#endif // COLORS_HPP_
