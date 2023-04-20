#include "game.hpp"

/**
 * @file game.cpp
 */


using namespace sf;


Game::Game(const uint w, const uint h, const f64 radius)
{
  /**
   * @fn Game constructor
   * @brief Game constructor
   * @param W     `uint` width of the main window
   * @param H     `uint` height of the main window
   * @param RADIUS `f64` radius of hexagons; not a member of Game,
            but passed to `init_grid` (member of HexagonGrid)
   */
  this->m_video_mode.width  = w;
  this->m_video_mode.height = h;

  // window
  this->m_window = nullptr;
  this->init_window();

  // grid
  this->m_hex_grid = nullptr;
  this->init_grid(radius);
}


void Game::init_grid(const f64 radius)
{
  /**
   * @fn private Game::init_grid(const f64)
   * @brief Set number of rows and cols and build `m_hex_grid`
   */
  // calc rows and cols and instantiate hex_grid with it
  ui8 cols = static_cast<ui8>(this->m_video_mode.width / radius);
  ui8 rows = static_cast<ui8>(this->m_video_mode.height / radius);

  this->m_hex_grid = new HexagonGrid(rows, cols, radius);
}


void Game::init_window()
{
  /**
   * @fn private Game::init()
   * @brief Create centered main window, set frame rate
   * @return `void`
   */
  this->m_window = new RenderWindow(this->m_video_mode,
				    "Game",
				    Style::Titlebar | Style::Close);
  // center window:
  int pos_x = static_cast<int>(VideoMode::getDesktopMode().width / 2 - this->m_video_mode.width / 2);
  int pos_y = static_cast<int>(VideoMode::getDesktopMode().height / 2 - this->m_video_mode.height / 2);
  this->m_window->setPosition(Vector2i(pos_x, pos_y));

  this->m_window->setFramerateLimit(FRAME_RATE_MAX);
}


//--------------------------------------
// Public methods
//--------------------------------------

Game::~Game()
{
  /**
   *  @fn Game::~Game()
   *  @brief destructor; free mallocated ressources
   */
  delete(this->m_window);
  delete(this->m_hex_grid);
}

 
void Game::poll_events()
{
  /**
   * @fn Game::poll_events()
   * @brief Events loop
   * @return `void`
   */
  while (this->m_window->pollEvent(this->m_event)) {
    switch (this->m_event.type) {
    case Event::Closed:
      this->m_window->close();
      break;
    default:
      break;
    }
  }
}


void Game::update()
{
  /**
   * @fn Game::update()
   * @brief Logic update loop
   * @return `void`
   */
  this->poll_events();
}


void Game::render()
{
  /**
   * @fn Game::render()
   * @brief Clear window and render game objects
   * @return `void`
   */
  // 1/ clear
  this->m_window->clear(sf::Color(242, 242, 151, 255));

  // 2/ draw shapes
  this->m_hex_grid->draw(this->m_window);
  
  // 3/ display
  this->m_window->display();
}


bool Game::running() const noexcept
{
  /**
   * @fn Game::running()
   * @brief Check if `m_window` is opened
   * @return `bool`
   */
  return this->m_window->isOpen();
}

 
Vector2f Game::get_dim() const noexcept
{
  /**
   * @fn Game::get_pos()
   * @brief Return main window width and height
   * @return `sf::Vector2f`
   */
  return Vector2f(static_cast<double>(VideoMode::getDesktopMode().width),
		      static_cast<double>(VideoMode::getDesktopMode().height));
}


Vector2f Game::get_pos() const noexcept
{
  /**
   * @fn Game::get_pos()
   * @brief Return current main window position (x, y)
   * @return `sf::Vector2f`
   */

  return Vector2f(static_cast<double>(this->m_window->getPosition().x),
		      static_cast<double>(this->m_window->getPosition().y));
}


Vector2f Game::get_center() const noexcept
{
  /**
   * @fn Game::get_center()
   * @brief Return current main window center (x, y)
   * @return sf::Vector2f
   */
  double x = static_cast<double>(VideoMode::getDesktopMode().width / 2 - this->m_video_mode.width / 2);
  double y = static_cast<double>(VideoMode::getDesktopMode().height / 2 - this->m_video_mode.height / 2);
  return Vector2f(x, y);
}

 
 // END game.cpp
