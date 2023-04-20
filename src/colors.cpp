#include "colors.hpp"


static const Color32 CHANNELS[4] = {
  0xFF000000, // _chan_RED
  0x00FF0000, // _chan_GREEN
  0x0000FF00, // _chan_BLUE
  0x000000FF  // _chan_ALPHA
};


ui8 get_channel(const Color32 color, const rgbaChan chan)
{
  /**
   * @fn    Colors::get_channel(const Color32, const rgbaChan)
   * @param Color32 COLOR: hexadecimal Color32 as `0xf080acff` 
   * @param rgbaChan CHAN: _chan_(RED|GREEN|BLUE|ALPHA)
   * @return ui8
   */
  return (color & CHANNELS[chan]) >> 8 * chan;
}
