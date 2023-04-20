#include "hex_grid.hpp"
#include <math.h>

/**
 * @file hex_grid.hpp
 */

static const Palette PALETTE = {
  {_wood,   0x21DE31FF}, // #21de31
  {_water,  0x80EFD7FF}, // #80efd7
  {_ground, 0xF2F297FF}, // #f2f297
};


HexagonGrid::HexagonGrid(const ui8 rows,
			 const ui8 cols,
			 const f64 radius)
{
  /**
   * @fn HexagonGrid constructor
   * @see https://www.redblobgames.com/grids/hexagons/
   */
  this->m_rows = rows;
  this->m_cols = cols;
  this->m_radius = radius;
  this->m_top = FLAT; // development default

  this->init_geometry();
  this->init_hexagons();
}


HexagonGrid::~HexagonGrid()
{
  /**
   * @fn HexagonGrid destructor
   * @brief Free hexagons
   * @return void
   */
  for (auto hp : this->m_hexagons) {
    delete(hp);
  }
}


void HexagonGrid::init_geometry()
{
  /**
   * @fn private HexagonGrid::init_geometry
   * @brief calc grid geometry according to hexagon
   *        radius and orientation
   * @see https://www.redblobgames.com/grids/hexagons/
   * @return `void`
   */
  switch(this->m_top) {
  case FLAT:
    this->m_hex_w = static_cast<f64>(this->m_radius * 2);
    this->m_hex_h = static_cast<f64>(sqrt(3) * this->m_radius);
    this->m_hor_dist = 3 / 2.f * this->m_radius;
    this->m_ver_dist = sqrt(3) * this->m_radius;
    break;
  case POINTY:
    this->m_hex_w = static_cast<f64>(sqrt(3) * this->m_radius);
    this->m_hex_h = static_cast<f64>(this->m_radius * 2);
    this->m_hor_dist = sqrt(3) * this->m_radius;
    this->m_ver_dist = 3 / 2.f * this->m_radius;
    break;
  default:
    break;
  }
}


void HexagonGrid::init_hexagons()
{
  /**
   * @fn private HexagonGrid::init_hexagons(const uint, const uint)
   * @brief Fill `m_hexagons` vector according to geometry
   * @return `void`
   */
                                                                   
  f64 offset = 0.f;

  // default rotation for FLAT top hexagons
  f64 rotation_deg = 180.f / 6;

  for (int row = 0; row < this->m_rows; ++row) {
    for (int col = 0; col < this->m_cols; ++col) {
      // offset down even columns
      offset = col % 2 == 0 ? static_cast<f64>(this->m_hex_h / 2) : 0.f;

      sf::CircleShape *hexagon = new sf::CircleShape(this->m_radius, 6);
      f64 x = static_cast<f64>(col * this->m_hor_dist);
      f64 y = static_cast<f64>(row * this->m_ver_dist + offset);
      hexagon->setPosition(x, y);
      hexagon->setRotation(rotation_deg);
      hexagon->setFillColor(sf::Color::Transparent);
      hexagon->setOutlineThickness(1.0);
      hexagon->setOutlineColor(sf::Color(128, 128, 128, 128));
      this->m_hexagons.push_back(hexagon);
    }
  }
}


void HexagonGrid::draw(sf::RenderWindow* window)
{
  for (auto hp : this->m_hexagons) {
    window->draw(*hp);
  }
}



// END hexagons.cpp
