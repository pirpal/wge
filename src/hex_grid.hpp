#ifndef HEX_GRID_HPP_
#define HEX_GRID_HPP_

/**
 * @file hex_grid.hpp
 */

#include <vector>
#include "SFML/Graphics.hpp"

#define MY_UTILS_IMPLEMENTATION
#include "my_utils.hpp"
#include "colors.hpp"

typedef enum TerrainType {
  _ground, _water, _wood
} TerrainT;



typedef enum HexTop {
  /**
   * @enum HexTop
   * @brief Defines hexagon's orientation
   */ 
  FLAT, POINTY
} HexTop;


typedef std::vector<sf::CircleShape*> Hexagons;

class HexagonGrid {
  /**
   * @class HexagonGrid
   * @brief Container for `sf::CircleShape` as hexagons
   *        Defines grid geometry
   */
private:
  // constructor args:
  ui8      m_rows;
  ui8      m_cols;
  double   m_radius;
  HexTop   m_top;
  // calc by Game::init_geometry()
  double   m_hex_w;
  double   m_hex_h;
  double   m_hor_dist;
  double   m_ver_dist;

  // built by Game::init_hexagons()
  Hexagons m_hexagons;

  // private methods:
  void init_geometry();
  void init_hexagons();

public:
  HexagonGrid() = delete;
  HexagonGrid(const ui8, const ui8, const f64);
  ~HexagonGrid();
  void draw(sf::RenderWindow*);
};


#endif // HEX_GRID_HPP_
