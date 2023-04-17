#include "game.hpp"

/**
 * @file game.cpp
*/

Game::Game(const ui16 w, const ui16 h)
{
  /**
   * @fn    Game::Game(const ui16, const ui16)
   * @brief Game constructor
   * @param W ui16 width of main window
   * @param H ui16 height of main window
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
   * @fn    private Game::init
   * @brief private Game::init
   * Mallocate program's main sf::RenderWindow
   */
  this->m_window = new sf::RenderWindow(this->m_video_mode,
                                        "Game",
                                        sf::Style::Titlebar | \
					sf::Style::Close);

  // center window:
  int pos_x = static_cast<int>(sf::VideoMode::getDesktopMode().width / 2 - this->m_video_mode.width / 2);
  int pos_y = static_cast<int>(sf::VideoMode::getDesktopMode().height / 2 - this->m_video_mode.height / 2);
  this->m_window->setPosition(sf::Vector2i(pos_x, pos_y));
}
//---------------------------------------------- 


Game::~Game()
{
  /**
   *  @fn Game::~Game
   *  @brief destructor; free mallocated sf::RenderWindow
   */
  delete(this->m_window);
}

 
//---------------------------------------------- 
void Game::poll_events()
{
  /**
   * @fn Game::poll_events
   * @brief Events poll loop
   *        Caller: Game::update
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
   * @fn Game::update
   * @brief Logic update loop
   */
  this->poll_events();
}

//---------------------------------------------- 
void Game::render()
{
  /**
   * @fn Game::render
   * @brief Clear window and render game objects
   */
  // clear:
  this->m_window->clear(sf::Color(255, 255, 255, 255));

  // draw objects:

  // display:
  this->m_window->display();
}

//---------------------------------------------- 
bool Game::running() const noexcept
{
  /**
   * @fn Game::running
   * @return bool
   * @brief Return true if m_window is opened
   */
  return this->m_window->isOpen();
}

 // END game.cpp
