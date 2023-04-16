#ifndef GAME_HPP_
#define GAME_HPP_

/**
 * @file game.hpp
*/

#include "SFML/Graphics.hpp"

typedef uint8_t   ui8;
typedef uint16_t ui16;
typedef uint32_t ui32;
typedef double    f64;

class Game {
  /**
   * @class Game
   * @brief Wrapper class for SFML objects and loops
   */
private:
  sf::VideoMode     m_video_mode;
  sf::RenderWindow *m_window;
  sf::Event m_event;
  void init();
  
public:
  Game(const ui16, const ui16);
  ~Game();
  void poll_events();
  void update();
  void render();
  bool running() const;
};

#endif // GAME_HPP_
