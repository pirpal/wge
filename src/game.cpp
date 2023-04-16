#include "game.hpp"

/**
 * @file game.cpp
*/

//---------------------------------------------- 
// Public methods
//---------------------------------------------- 
Game::Game(const ui16 w, const ui16 h)
{
  /**
   * @fn Game::Game(const ui16, const ui16)
   * @brief Game constructor
   * @param W uint16_t width of the main window
   * @param H uint16_t height of the main window
   */
  this->m_video_mode.width  = w;
  this->m_video_mode.height = h;
  this->m_window = nullptr;
  this->init();
}


// private method ------------------------------
void Game::init()
{
  /**
   * @fn private Game::init()
   * @brief private Game::init()
   * Mallocate program's main sf::RenderWindow
   */
  this->m_window = new sf::RenderWindow(this->m_video_mode,
                                        "Game",
                                        sf::Style::Titlebar | sf::Style::Close);
}

//---------------------------------------------- 
Game::~Game()
{
  /**
   *  @fn Game::~Game()
   *  @brief destructor; free mallocated sf::RenderWindow
   */
  delete(this->m_window);
}

 
//---------------------------------------------- 
void Game::poll_events()
{
  /**
   * @fn Game::poll_events()
   * @brief Events loop
   * 
   */
  while (this->m_window->pollEvent(this->m_event)) {
    switch (this->m_event.type) {
    case sf::Event::Closed:
      this->m_window->close();
      break;
    default:
      break;
    }
  }
}
//---------------------------------------------- 
void Game::update()
{
  /**
   * @fn Game::update()
   * @brief Logic update loop
   */
  this->poll_events();
}

//---------------------------------------------- 
void Game::render()
{
  /**
   * @fn Game::render()
   * @brief Clear window and render game objects
   */
  this->m_window->clear(sf::Color(255, 255, 255, 255));
  this->m_window->display();
}

//---------------------------------------------- 
bool Game::running() const
{
  /**
   * @fn Game::running()
   * @brief Checks if m_window is opened
   */
  return this->m_window->isOpen();
}

 // END game.cpp
