#include "parsecstar.h"


ParsecStar::ParsecStar (QSharedPointer<Star> star, double _psf) : _star(star), _parsecStarFactor(_psf) {
    this->_x = static_cast<int>(_star->x() / _parsecStarFactor); // Ly per hex
    this->_y = static_cast<int>(_star->y() / _parsecStarFactor); // Ly per hex
    this->_z = static_cast<int>(_star->z() / _parsecStarFactor); // Ly per hex
    _visited = false;
    _mode = SceneMediatorDrawMode::XY;
}
