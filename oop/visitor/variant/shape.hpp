#include <variant>
#include <vector>

#include "circle.hpp"
#include "square.hpp"

using Shape = std::variant<Circle, Square>;
using Shapes = std::vector<Shape>;