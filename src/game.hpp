#ifndef GAME_HPP_
#define GAME_HPP_

/**
 * @file GAME.HPP
 */

#include "SFML/Graphics.hpp"
#include "hex_grid.hpp"

#define MY_UTILS_IMPLEMENTATION
#include "my_utils.hpp"



#define FRAME_RATE_MAX 60
#define MIN_HEX_RADIUS 32

class Game {
  /**
   * @class Game
   * @brief wrapper class for sfml objects and loops
   */
private:
  sf::VideoMode     m_video_mode;
  sf::Event         m_event;
  sf::RenderWindow *m_window;
  HexagonGrid      *m_hex_grid;
  void init_window();
  void init_grid(const f64);
  
public:
  Game(const uint, const uint, const f64);
  ~Game();
  void poll_events();
  void update();
  void render();
  bool running() const noexcept;
  sf::Vector2f get_dim() const noexcept;
  sf::Vector2f get_pos() const noexcept;
  sf::Vector2f get_center() const noexcept;
};

#endif // GAME_HPP_
